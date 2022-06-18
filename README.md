# rock-paper-scissors
### Description
Hey! 
This is a simple project done in C++ using socket programming, mutex locks and multi-threads to create a simple game namely "Rock Paper Scissors".
### Running the project
1. Clone this repository
2. Run the following commands in your terminal :
```
g++ server.cpp -lpthread -o server
g++ client.cpp -lpthread -o client
```
3. To run the server application, use this command in the terminal :
```
./server
```

4. Now, open another terminal and use this command to run the client application :
```
./client
```

5. For opening multiple client applications, repeat step 4.

https://user-images.githubusercontent.com/80099980/174426924-7a51d12a-e6f9-4bea-b26c-ba1342c7e6e8.mp4

### Internal Working
The server creates a game and when the client joins the game, the client is asked to enter their choice. The input is then sent to the server and then the CPU or server plays their choice (using int n= rand()%3). Thus, the game is concluded. Many clients can also access the server at the same time.  

Multiple users(clients) may want to access some information from the server. All of them may simultaneously request the resources from the server. For better user experience the server needs to be more responsive that is it should be able to process as many requests as possible. Multithreading is the concept of using multiple threads to execute concurrently. In order to make the server more responsive we would assign the requests to different threads, so that the maximum number of requests can be processed concurrently. Using many threads would lead to a situation where two threads are accessing the same code or the same shared variable and there is a possibility of wrong output. To tackle this situation we use mutex locks to allow only one thread to access the shared code and do the necessary changes and synchronize all the threads. Using too many threads may also slow down. In order to tackle this problem, we would be using a thread pool having a definite number of threads and with the use of mutex we would be assigning each request to a thread. This would speed up the response time and would aim for more user satisfaction.
### My learning
1. Threads and pthreads.
2. Locks and mutex.
3. Creating a socket and then binding, listenning and accepting the connection.
4. Implementing threads in a simple server to make it more efficieint.
### Resources
The live classes done by ACM IITR were a major source of knowledge. 

Along with it, these resources were helpful:
1. https://youtube.com/playlist?list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM
2. https://www.geeksforgeeks.org/socket-programming-cc/
3. https://www.geeksforgeeks.org/handling-multiple-clients-on-server-with-multithreading-using-socket-programming-in-c-cpp/
