#include <stdio.h> 
#include <unistd.h> 
#include <string.h>

char* msg1 = "Message sent from Child to Parent"; 
char* msg2 = "Message sent from Parent to Child"; 
#define MSGSIZE 34

int main() 
{ 
    char inbuf1[MSGSIZE]; 
    char inbuf2[MSGSIZE]; 
    int childToParent[2], parentToChild[2], pid, nbytes; 
  
    inbuf1[MSGSIZE-1] = 0;
    inbuf2[MSGSIZE-1] = 0;
    if (pipe(childToParent) < 0) 
        return 1;
 
    if (pipe(parentToChild) < 0) 
        return 1;

    if ((pid = fork()) > 0) 
    { 
	printf("Created child with PID = %d\n", pid);
	close(childToParent[0]);
        write(childToParent[1], msg1, strlen(msg1));
	close(childToParent[1]);

	close (parentToChild[1]);

	read(parentToChild[0], inbuf2, strlen(msg2));
        printf("%s\n", inbuf2); 
	close (parentToChild[0]);
        wait(NULL);
    } 
    else 
    { 
	close (childToParent[1]);
	read(childToParent[0], inbuf1, strlen(msg1));
        printf("%s\n", inbuf1); 
	close (childToParent[0]);

	close (parentToChild[0]);
	write(parentToChild[1], msg2, strlen(msg2));
	close (parentToChild[1]);
    } 
    return 0; 
} 

