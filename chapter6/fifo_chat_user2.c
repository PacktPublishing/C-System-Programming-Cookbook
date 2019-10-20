#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
 
#define MAX_LENGTH 128

int main() 
{ 
    int fd; 
    char* myfifo = "/tmp/chat"; 
    mkfifo(myfifo, 0600); 
  
    char msgReceived[MAX_LENGTH], msgToSend[MAX_LENGTH]; 
    while (1) 
    { 
        fd = open(myfifo, O_RDONLY); 
        read(fd, msgReceived, sizeof(msgReceived)); 
        printf("User2: %s\n", msgReceived); 
        close(fd); 

        fd = open(myfifo, O_WRONLY); 
	printf("Uset1: ");
        fgets(msgToSend, MAX_LENGTH, stdin); 
        write(fd, msgToSend, strlen(msgToSend)+1); 
        close(fd); 
    } 
    return 0; 
} 
