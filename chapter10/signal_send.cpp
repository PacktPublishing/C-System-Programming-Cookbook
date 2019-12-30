#include<stdio.h>
#include<signal.h>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Starting ..." << std::endl;
    if (argc <= 1)
    {
       std::cout << "Process pid missing ..." << std::endl;
       return 1;
    }
    int pid = std::atoi(argv[1]);

    kill (pid, SIGTERM);

    std::cout << "Ending ..." << std::endl;
    return 0;
}

