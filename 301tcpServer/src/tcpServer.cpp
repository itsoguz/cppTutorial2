// tcpServer.cpp

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

int main(){
	// Create a socket
	int listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == -1){
		std::cerr << "Can't create a socket! Quitting." << std::endl;
		return -1;
	}
	
	// Bind ip address and port to the socket 'listening'
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

	bind(listening, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));

	// Tell, that the socket is for listening
	listen(listening, SOMAXCONN);

	// Wait for a connection
	sockaddr_in client;
	socklen_t clientSize = sizeof(client);

	int clientSocket = accept(listening, reinterpret_cast<sockaddr*>(&client), &clientSize);

	char host[NI_MAXHOST];		// Client's remote name
	char service[NI_MAXSERV];	// Service (i.e. port) the client is connected on

	memset(host, 0, NI_MAXHOST);
	memset(service, 0, NI_MAXSERV);

	if (getnameinfo(reinterpret_cast<sockaddr*>(&client), sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
		std::cout << host << " connected on port " << service << std::endl;
	}
	else{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on port " << ntohs(client.sin_port) << std::endl;
	}

	// Close listening socket
	close(listening);
	
	// While loop: accept and echo the message back to the client
	char buf[4096];

	while (true){
		memset(buf, 0, 4096);

		// Wait for the client to send data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == -1){
			std::cerr << "Error in recv(). Quitting." << std::endl;
			break;
		}
	
		if (bytesReceived == 0){
			std::cout << "Client disconnected." << std::endl;
			break;
		}

		std::cout << std::string(buf, 0, bytesReceived) << std::endl;

		// Echo the message back to the client
		send(clientSocket, buf, bytesReceived + 1, 0);
	}

	// Close the socket
	close(clientSocket);	

	return 0;
}
