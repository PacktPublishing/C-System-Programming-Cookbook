#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
 
#define MAX_LENGTH 128

int main() 
{ 
    char* myfifo = "/tmp/chat"; 
    mkfifo(myfifo, 0600); 
  
    char msgReceived[MAX_LENGTH], msgToSend[MAX_LENGTH]; 
    while (1) 
    { 
        int fdUser2 = open(myfifo, O_RDONLY); 
        read(fdUser2, msgReceived, sizeof(msgReceived)); 
        printf("User1: %s\n", msgReceived); 
        close(fdUser2); 

        int fdUser1 = open(myfifo, O_WRONLY); 
	printf("User2: ");
        fgets(msgToSend, MAX_LENGTH, stdin); 
        write(fdUser1, msgToSend, strlen(msgToSend)+1); 
        close(fdUser1); 
    } 
    return 0; 
} 

