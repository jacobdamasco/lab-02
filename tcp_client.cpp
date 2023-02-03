// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024] ={'\0'};
	
	// TODO: Fill out the server ip and port
	std::string server_ip = "localhost";
	std::string server_port = "5000";
	// std::cout << "Here 1" << std::endl;

	int opt = 1;
	int client_fd = -1;

	// TODO: Create a TCP socket()
	// int client_fd;
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd < 0){
		std::cout << "Error opening socket" << std::endl;
		return -1;
	}
	// std::cout << "Here 2" << std::endl;
	// Enable reusing address and port
	if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}
	// std::cout << "Here 3" << std::endl;
	// Check if the client socket was set up properly
	if(client_fd == -1){
		std::cout << "Error- Socket setup failed" << std::endl;
		return -1;
	}
	// std::cout << "Here 4" << std::endl;
	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	// TODO: Connect() to the server (hint: you'll need to use server_addr)
	if (connect(client_fd,server_addr->ai_addr,server_addr->ai_addrlen) == -1) {
        std::cout << "ERROR connecting" << std:: endl;
		return -1;
	}
	// TODO: Retreive user input
	std::cout << "Enter Message: " << std::endl;
	std::string message;
	getline(std::cin, message);
	// TODO: Send() the user input to the server
	send(client_fd, message.c_str(), message.length(), 0);
	// TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!
	// socket_read_buffer = {'\0'};
	recv(client_fd, socket_read_buffer, 256,0);
	// TODO: Close() the socket
	close(client_fd);
	return 0; 
} 