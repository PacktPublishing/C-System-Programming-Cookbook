#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>

constexpr unsigned int SERVER_PORT = 50544;
constexpr unsigned int MAX_BUFFER = 128;
constexpr unsigned int MSG_REPLY_LENGTH = 18;

int main(int argc, char *argv[])
{
     int sockfd =  socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
     {
          std::cerr << "open socket error" << std::endl;
          return 1;
     }

     int optval = 1;
     setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

     struct sockaddr_in serv_addr, cli_addr;
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;  
     serv_addr.sin_addr.s_addr = INADDR_ANY;  
     serv_addr.sin_port = htons(SERVER_PORT);
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
     {
          std::cerr << "bind error" << std::endl;
          return 2;
     }

     listen(sockfd, 5);
     socklen_t clilen = sizeof(cli_addr);
     int incomingSock = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (incomingSock < 0)
     {
          std::cerr << "accept error" << std::endl;
	     return 3;
     }

     std::cout << "server: got connection from = " 
	          << inet_ntoa(cli_addr.sin_addr)
	          << " and port = " << ntohs(cli_addr.sin_port) << std::endl;
     write(incomingSock, "You are connected!", MSG_REPLY_LENGTH);

     std::string buffer (MAX_BUFFER, 0);
     if (read(incomingSock, &buffer[0], MAX_BUFFER-1) < 0)
     {
          std::cerr << "read from socket error" << std::endl;
          return 4;
     }
     std::cout << "Got the message:" << buffer << std::endl;

     close(incomingSock);
     close(sockfd);
     return 0; 
}
