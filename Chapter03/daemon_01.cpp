#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

int main(void)
{
    pid_t child;
    int status;
    std::cout << "I am the parent, my PID is " << getpid() << std::endl;
    std::cout << "I am going to create a new daemon process..." << std::endl;

    // clear file creation mask
    umask(0);

    child = fork();
    if (child == -1)
    {
	std::cout << "fork() failed." << std::endl;
        return (-1);
    }
    else if (child == 0)
    {
	setsid();
	if (chdir("/") < 0)
		std::cout << "Couldn't change directory" << std::endl;

	// Attach here the daemon specific long running tasks ...  sleep for now.
	sleep (10);
    }
    return (0);
}

