#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char* msg1 = "Message sent from Child to Parent"; 
char* msg2 = "Message sent from Parent to Child"; 
#define MSGSIZE 34
#define IN      0
#define OUT     1

int main() 
{ 
    char inbufToParent[MSGSIZE]; 
    char inbufToChild[MSGSIZE]; 
    int childToParent[2], parentToChild[2], pid, nbytes; 
  
    inbufToParent[0] = 0;
    inbufToChild[0] = 0;
    if (pipe(childToParent) < 0) 
        return 1;
 
    if (pipe(parentToChild) < 0) 
        return 1;

    if ((pid = fork()) > 0) 
    { 
	printf("Created child with PID = %d\n", pid);
	close(childToParent[IN]);
        write(childToParent[OUT], msg1, strlen(msg1));
	close(childToParent[OUT]);

	close (parentToChild[OUT]);

	read(parentToChild[IN], inbufToChild, strlen(msg2));
        printf("%s\n", inbufToChild); 
	close (parentToChild[IN]);
        wait(NULL);
    } 
    else 
    { 
	close (childToParent[OUT]);
	read(childToParent[IN], inbufToParent, strlen(msg1));
        printf("%s\n", inbufToParent); 
	close (childToParent[IN]);

	close (parentToChild[IN]);
	write(parentToChild[OUT], msg2, strlen(msg2));
	close (parentToChild[OUT]);
    } 
    return 0; 
} 

