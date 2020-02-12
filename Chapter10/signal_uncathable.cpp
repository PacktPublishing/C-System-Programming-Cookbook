#include<stdio.h>
#include<signal.h>
#include <iostream>

int main()
{
    std::cout << "Starting ..." << std::endl;
    signal(SIGKILL, SIG_IGN);
    while (1) ;
    std::cout << "Ending ..." << std::endl;
    return 0;
}

