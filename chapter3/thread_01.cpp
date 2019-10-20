#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void threadFunction (std::vector<int> &speeds, int start, int end, int& res);

int main()
{
    std::vector<int> speeds (100000);
    std::generate(begin(speeds), end(speeds), [] () { return rand() % 10 ; });

    int th1Result = 0;
    std::thread t1 (threadFunction, std::ref(speeds), 0, 49999, std::ref(th1Result));

    int th2Result = 0;
    std::thread t2 (threadFunction, std::ref(speeds), 50000, 99999, std::ref(th2Result));

    t1.join();
    t2.join();
    std::cout << "Result = " << th1Result + th2Result << std::endl;
    return 0;
}

void threadFunction (std::vector<int> &speeds, int start, int end, int& res)
{
    std::cout << "starting thread 1 ... " << std::endl;
    for (int i = start; i <= end; ++i)
	res += speeds[i];
    std::cout << "end thread 1 ... " << std::endl;
}

