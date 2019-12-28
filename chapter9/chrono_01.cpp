#include <iostream>
#include <vector>
#include <chrono>

int main ()
{
    std::cout << "Starting ... " << std::endl;
    std::vector <int> elements;
    auto start = std::chrono::system_clock::now();

    for (auto i = 0; i < 100000000; ++i)
        elements.push_back(i);

    auto end = std::chrono::system_clock::now();

    // default seconds
    std::chrono::duration<double, std::milli> diff = end-start;
    std::cout << "Time Spent for populating a vector with 100M of integer ..." 
              << diff.count() << "msec" << std::endl;

    std::time_t tp = std::chrono::system_clock::to_time_t(start);
    std::cout << "Start: " << std::ctime(&tp) << std::endl;

    tp = std::chrono::system_clock::to_time_t(end);
    std::cout << "End: " << std::ctime(&tp) << std::endl;
    std::cout << "Ended ... " << std::endl;
}

