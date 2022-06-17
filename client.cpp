#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <signal.h>
#include <mutex>
using namespace std;
int client_socket;

int main(){
if((client_socket=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket: ");
		exit(-1);
	}

	struct sockaddr_in client;
	client.sin_family=AF_INET;
	client.sin_port=htons(8989);
	client.sin_addr.s_addr=INADDR_ANY;
	
	bzero(&client.sin_zero,0);

	if((connect(client_socket,(struct sockaddr *)&client,sizeof(struct sockaddr_in)))==-1)
	{
		perror("connection failed. ");
		exit(-1);
	}
    cout<<"Creating game. Please wait..."<<endl;
    sleep(2);
	int flag=0;
    while(1){
		if(flag==1){break;}
	cout<<endl<<"Game created!"<<endl<<"Enter your choice : (1 for rock, 2 for paper and 3 for scissor)"<<endl;
    char k;
    cin>>k;
    send(client_socket, &k, sizeof(k),0);
	char result;
	int bytes_rcvd;
    bytes_rcvd=recv(client_socket, &result, sizeof(result), 0);
    if (bytes_rcvd<=0)
			{
				break;
			}
    if(result=='1'){
		if(k=='1'){
			cout<<"CPU played rock"<<endl<<"The game is a draw"<<endl;
			flag=1;
		}else if(k=='2'){
			cout<<"CPU played paper"<<endl<<"The game is a draw"<<endl;
			flag=1;
		}else if(k=='3'){
			cout<<"CPU played scissors"<<endl<<"The game is a draw"<<endl;
			flag=1;
		}
		
    }else if(result=='2'){
		if(k=='1'){
			cout<<"CPU played scissors"<<endl<<"YOu won the game!"<<endl;
			flag=1;
		}
        else if(k=='2'){
			cout<<"CPU played rock"<<endl<<"YOu won the game!"<<endl;
			flag=1;
		}else if(k=='3'){
			cout<<"CPU played paper"<<endl<<"YOu won the game!"<<endl;
			flag=1;
		}
    }else if(result=='3'){
		if(k=='1'){
        cout<<"CPU played paper"<<endl<<"CPU won the game :("<<endl;
		flag=1;
		}else if(k=='2'){
			cout<<"CPU played scissors"<<endl<<"CPU won the game :("<<endl;
		flag=1;
		}else if(k=='3'){
			cout<<"CPU played rock"<<endl<<"CPU won the game :("<<endl;
		flag=1;
		}
    }

	}

    close(client_socket);

return 0;
}