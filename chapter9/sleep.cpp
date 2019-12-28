#include <iostream>
#include <chrono>
#include <thread>    // sleep_for
#include <unistd.h>  // for sleep
#include <time.h>    // for nanosleep and clock_nanosleep

int main ()
{
    std::cout << "Starting ... " << std::endl;

    auto start = std::chrono::steady_clock::now();
    sleep (1);
    auto end = std::chrono::steady_clock::now();
    std::cout << "sleep() call cause me to sleep for: "
              << std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count()
              << " millisec" <<     std::endl;

    struct timespec reqSleep = {.tv_sec = 0, .tv_nsec = 99999999};
    start = std::chrono::steady_clock::now();
    int ret = nanosleep (&reqSleep, NULL);
    if (ret)
         std::cerr << "nanosleep issue" << std::endl;

    end = std::chrono::steady_clock::now();
    std::cout << "nanosleep() call cause me to sleep for: "
              << std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count()
              << " millisec" << std::endl;
  
    struct timespec reqClockSleep = {.tv_sec = 1, .tv_nsec = 99999999};
    start = std::chrono::steady_clock::now();
    ret = clock_nanosleep (CLOCK_MONOTONIC, 0, &reqClockSleep, NULL);
    if (ret)
        std::cerr << "clock_nanosleep issue" << std::endl;
    end = std::chrono::steady_clock::now();
    std::cout << "clock_nanosleep() call cause me to sleep for: " 
              << std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count() 
              << " millisec" << std::endl;

    start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    end = std::chrono::steady_clock::now();
    std::cout << "std::this_thread::sleep_for() call cause me to sleep for: "
              << std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count()
              << " millisec" << std::endl;
    std::cout << "End ... " << std::endl;
}

