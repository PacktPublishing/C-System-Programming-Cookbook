#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void threadFunction (std::vector<int> &speeds, int& res);
int main()
{
    std::vector<int> speeds = {1, 2, 3, 4, 5};
    int result = 0;
    std::thread t1 (threadFunction, std::ref(speeds), std::ref(result));

    t1.join();
    std::cout << "Result = " << result << std::endl;
    return 0;
}

void threadFunction (std::vector<int> &speeds, int& res)
{
    std::cout << "starting thread 1 ... " << std::endl;
    for_each(begin(speeds), end(speeds), [](int speed) {

                            std::cout << "speed is " << speed << std::endl;

    });
    res = 10;
    std::cout << "end thread 1 ... " << std::endl;
}


