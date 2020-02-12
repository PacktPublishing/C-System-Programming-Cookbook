#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

int main(void)
{
    pid_t child;
    int status;
    std::cout << "I am the parent, my PID is " << getpid() << std::endl;
    child = fork();
    std::cout << "Forked a child process with PID = " << child << std::endl;
    if (child == -1)
    {
       std::cout << "fork() failed." << std::endl;
       return 1;
    }
    else if (child == 0)
    {
        std::cout << "About to run the child process with PID = " << child << std::endl;
        if (execl("./child.out", "child.out", NULL) < 0)
        {
            std::cout << "error in executing child proceess " << std::endl;
            return 2;
        }
    }
    else
    {
        std::cout << "killing the child process with PID = " << child << std::endl;
        int status = kill (child, 9);
        if (status == 0)
            std::cout << "child process killed ...." << std::endl;
        else
            std::cout << "there was a problem killing the process with PID = " << child << std::endl;
    }
    return (0);
}

