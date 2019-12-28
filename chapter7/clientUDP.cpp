#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>

constexpr unsigned int SERVER_PORT = 50544;
constexpr unsigned int MAX_BUFFER = 128;

int main(int argc, char *argv[])
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
    {
        std::cerr << "socket error" << std::endl;
        return 1;
    }

    struct hostent* server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        std::cerr << "gethostbyname, no such host" << std::endl;
        return 2;
    }

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr, 
          server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    std::string outBuffer (MAX_BUFFER, 0);
    std::cout << "What message for the server? : ";
    getline(std::cin, outBuffer);
    unsigned int len = sizeof(serv_addr);
    if (sendto(sockfd, outBuffer.c_str(), MAX_BUFFER, 0, (struct sockaddr *) &serv_addr, len) < 0)
    {
        std::cerr << "sendto failed" << std::endl;
        return 3;
    }

    std::string inBuffer (MAX_BUFFER, 0);
    if (recvfrom(sockfd, &inBuffer[0], MAX_BUFFER, 0, (struct sockaddr *) &serv_addr, &len) < 0)
    {
        std::cerr << "recvfrom failed" << std::endl;
        return 4;
    }
    std::cout << inBuffer << std::endl;

    close(sockfd);
    return 0;
}
