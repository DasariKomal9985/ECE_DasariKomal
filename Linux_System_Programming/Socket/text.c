🌐 IPC in Linux — Socket Programming
1. What is a Socket?

A socket is an endpoint used for communication between two processes. Processes can communicate on the same computer or across different computers through a network.

Examples:

🌐 Web browsers communicating with web servers.

💬 Chat applications exchanging messages.

📡 Embedded Linux devices sending sensor data to a server.






2. How does socket communication work?

Client
Requests data

Server
Provides data

Request

Response

Communication through sockets




3. Important socket functions

Function



Purpose




socket()
Creates a socket

bind()
Assigns an address and port to a server socket

listen()
Marks a TCP socket as ready to accept connections

accept()
Accepts a client connection

connect()
Connects a client to a server

send() / recv()
Sends and receives data

close()
Closes a socket descriptor








This example uses INADDR_LOOPBACK, so both programs communicate on the same computer through 127.0.0.1.

5. Compile and run ⚙️

Compile both programs:

gcc server.c -o server
gcc client.c -o client

Terminal 1 — Start the server first:

./server

Output:

Server waiting on port 8080...
Client says: Hello from client!

Terminal 2 — Run the client:

./client

Output:

Message sent successfully!
6. Types of sockets



6. Types of sockets

Type

Description

SOCK_STREAM
Stream communication, commonly TCP

SOCK_DGRAM
Datagram communication, commonly UDP

Unix domain socket
Communication between processes on the same machine

One-line definition: A socket is a communication endpoint that allows processes to exchange data locally or over a network. 🚀
