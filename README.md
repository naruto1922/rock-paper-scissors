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
![](https://github.com/naruto1922/rock-paper-scissors/blob/main/demo.mp4)

### Internal Working
The server creates a game and when the client joins the game, the client is asked to enter their choice. The input is then sent to the server and then the CPU or server plays their choice (using int n= rand()%3). Thus, the game is concluded. Many clients can also access the server at the same time.  
