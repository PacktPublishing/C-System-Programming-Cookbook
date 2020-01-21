#include<stdio.h>
#include<signal.h>
#include <iostream>

void handleSigTerm (int sig);

int main()
{
    std::cout << "Starting ..." << std::endl;
    signal(SIGTERM, handleSigTerm);
    while (true) ;
    std::cout << "Ending ..." << std::endl;
    return 0;
}


void handleSigTerm (int sig)
{
   std::cout << "Just got " << sig << " signal" << std::endl;
   std::cout << "cleaning up some used resources ..." << std::endl; 
   abort();
}

