#include <bits/stdc++.h>
#include <sys/socket.h>
#include <limits.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include "myQueue.h"

#define SERVERPORT 8989
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100
#define THREAD_POOL_SIZE 20

pthread_t thread_pool[THREAD_POOL_SIZE] ; 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER ;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER ;

typedef struct sockaddr_in SA_IN ;
typedef struct sockaddr SA ;

void * handle_connection(void * p_clinet_soccket) ;
int check(int exp , const char *msg) ;
void * thread_function(void * args) ;

int main(){
 int server_socket , client_socket, addr_size ;
    SA_IN server_addr , client_addr ;
    
    for(int i =0 ; i < THREAD_POOL_SIZE ; i ++){
        pthread_create(&thread_pool[i] , NULL , thread_function , NULL) ;
    } 
    check((server_socket = socket(AF_INET , SOCK_STREAM , 0)), "Failed to create socket") ;
    server_addr.sin_family = AF_INET ;
    server_addr.sin_addr.s_addr = INADDR_ANY ;
    server_addr.sin_port = htons(SERVERPORT) ;
    check((bind(server_socket, (SA*)&server_addr , sizeof(server_addr))), "Bind Failed!") ;
    check(listen(server_socket, SERVER_BACKLOG), "Listen Failed!") ;
    std::cout<<"Game created!"<<std::endl<<"Waiting for a Player..."<<std::endl; 
    while(true){
        
        addr_size = sizeof(SA_IN) ;
        check(client_socket = accept(server_socket , (SA*)&client_addr, (socklen_t*)&addr_size),
                "accept failed!!") ;
        
        printf("Connected\n") ;
      
        int *pclient = (int *)malloc(sizeof(int)) ;
        *pclient = client_socket ;
        pthread_mutex_lock(&lock) ;
        enqueue(pclient) ;
        pthread_cond_signal(&cond_var) ;
        pthread_mutex_unlock(&lock) ;
    }   


return 0;
}
int check(int exp, const char *msg) {
    if(exp == SOCKETERROR){
        perror(msg) ;
        exit(1) ;
    }
    return exp ;
}

void * thread_function(void * args) {
    while(true){
        int *pclient ;
        pthread_mutex_lock(&lock) ;
        if((pclient = dequeue()) == NULL){
            pthread_cond_wait(&cond_var , &lock) ;
            pclient = dequeue() ;
        }
        pthread_mutex_unlock(&lock) ;
        if(pclient != NULL){
            handle_connection(pclient) ;
        }
    }
}
void * handle_connection(void * p_clinet_soccket) {
  
    int clinet_soccket = *((int *) p_clinet_soccket) ;
    free(p_clinet_soccket) ;
    char x;
    int bytes_recvd = recv(clinet_soccket,&x, sizeof(x),0 );
    check(bytes_recvd , "recv error") ;
    int n= rand()%3;
     char flag;
     int num= x - '0';
    	if(num==1){
        if(n==1){
            flag='1';
        }else if(n==2){
            flag='3';
        }else if(n==3){
            flag='2';
        }
    }else if(num==2){
        if(n==1){
            flag='2';
        }else if(n==2){
            flag='1';
        }else if(n==3){
            flag='3';
        }
    }else if(num==3){
        if(n==1){
            flag='3';
        }else if(n==2){
            flag='2';
        }else if(n==3){
            flag='1';
        }
    }
    send(clinet_soccket,&flag, sizeof(flag),0);
    close(clinet_soccket) ;
    printf("CLosing connection\n") ;
    return NULL ;
}