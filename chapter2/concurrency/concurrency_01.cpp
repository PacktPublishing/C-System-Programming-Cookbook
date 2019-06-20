#include <iostream>
#include <thread>


void threadFunction1 ();
int main()
{
    std::thread t1 {threadFunction1};

    t1.join();
    return 0;
}

void threadFunction1 ()
{
    std::cout << "starting thread 1 ... " << std::endl;
    std::cout << "end thread 1 ... " << std::endl;
}


