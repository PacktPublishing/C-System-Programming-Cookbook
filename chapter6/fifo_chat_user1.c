#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
 
#define MAX_LENGTH 128

int main() 
{ 
    char* fifoChat = "/tmp/chat"; 
    mkfifo(fifoChat, 0600); 
  
    char msgReceived[MAX_LENGTH], msgToSend[MAX_LENGTH]; 
    while (1) 
    { 
	// write section
        int fdUser1 = open(fifoChat, O_WRONLY); 
	printf("User1: ");
        fgets(msgToSend, MAX_LENGTH, stdin); 
        write(fdUser1, msgToSend, strlen(msgToSend)+1); 
        close(fdUser1); 
  
	// read section
        int fdUser2 = open(fifoChat, O_RDONLY); 
        read(fdUser2, msgReceived, sizeof(msgReceived)); 
        printf("User2: %s\n", msgReceived); 
        close(fdUser2); 
    } 
    return 0; 
} 
