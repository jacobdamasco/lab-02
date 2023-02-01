# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Kobe Kodachi
- Jacob Damasco

## Lab Question Answers

Answer for Question 1: 

The reliability of the UDP decreased and the message was not recieved every time that I sent it.
This occured because UDP does a "best effort delivery" which does its best to deliver packages but does not guarantee their delivery.

Answer for Question 2:

The reliability of the TCP did not decrease because TCP has reliable delivery and congestion control.

Answer for Question 3:

The speed of TCP dropped due to the 50% loss added.
This happened because of congestion control which adapts the send rate to the current network bandwidth.

tcp_server.c answers:

1. argc - count of command line arguments passed
   argv[] - cstring representation of the command line arguments

2. A Unix file descriptor is an int used as a handle to identify files and io resources. A file descriptor table is a collection of these indeces created for each process.

3. A struct is a way to group data members of varying types together. The structure sockaddr_in has the serv_addr and cli_addr in it.

4. Socket has a return value of int and input parameters of: AF_INET, SOCK_STREAM, and 0.

5. bind(int socket, struct address, address length)
   listen(socket descriptor, max length for pending connections)

6. We use while(1) because we want to constantly check the socket. This code can't handle multiple connections because it never changes the value of sockfd so it can't check a new socket.

7. fork() creates a new process that runs concurrently with the process that makes the call.

8. A system call is a way for programmers to interact with the OS, in this case it is the Linux Kernel.

Sources:
- https://www.ibm.com/docs/en/aix/7.1?topic=volumes-using-file-descriptors
- https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-listen-prepare-server-incoming-client-requests
- https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-bind-bind-name-socket
- https://www.geeksforgeeks.org/fork-system-call/
