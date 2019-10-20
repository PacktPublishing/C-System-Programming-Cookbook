#include <stdio.h> 
#include <string.h>
#include <mqueue.h>

#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256

int main() 
{ 
    mqd_t user1Desc, user2Desc; 
    char message[MAX_MSG_SIZE]; 
    char message2[MAX_MSG_SIZE]; 

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    if ((user1Desc = mq_open ("/user1", O_RDONLY, "0660", &attr)) == -1) 
    {
        perror ("User1: mq_open error");
        return (1);
    }
    if ((user2Desc = mq_open ("/user2", O_WRONLY, "0660", &attr)) == -1)
    {
        perror ("User2: mq_open error");
        return (1);
    }
 
    while (1)
    {
        // send message to server
	printf("USER 2: ");
	fgets(message, MAX_MSG_SIZE, stdin);
        if (mq_send (user2Desc, message, strlen(message) + 1, 0) == -1) 
	{
            perror ("Not able to send message to User 1");
            continue;
        }

        if (mq_receive (user1Desc, message2, MAX_MSG_SIZE, NULL) == -1) 
	{
            perror ("tried to receive a message from User 1  but I've failed!");
            continue;
        }
	printf("USER 1: %s\n", message2);
    }

    return 0; 
} 

