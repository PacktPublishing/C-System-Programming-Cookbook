#include <iostream>
#include <time.h>
#include <vector>

void timespec_diff(struct timespec* start, struct timespec* stop, struct timespec* result);

int main ()
{
    std::cout << "Starting ..." << std::endl;
    struct timespec tsRealTime, tsMonotonicStart;
    clock_gettime(CLOCK_REALTIME, &tsRealTime);
    clock_gettime(CLOCK_MONOTONIC_RAW, &tsMonotonicStart);

    std::cout << "Real Time clock (i.e.: wall clock):" << std::endl;
    std::cout << " sec :" << tsRealTime.tv_sec << std::endl;
    std::cout << " nanosec :" << tsRealTime.tv_nsec << std::endl;

    std::cout << "Monotonic clock:" << std::endl;
    std::cout << " sec :" << tsMonotonicStart.tv_sec << std::endl;
    std::cout << " nanosec :" << tsMonotonicStart.tv_nsec << std::endl;

    std::vector <int> elements;
    for (int i = 0; i < 100000000; ++i)
        elements.push_back(i);

    struct timespec tsMonotonicEnd;
    clock_gettime(CLOCK_MONOTONIC_RAW, &tsMonotonicEnd);

    struct timespec duration;
    timespec_diff (&tsMonotonicStart, &tsMonotonicEnd, &duration);

    std::cout << "Time elapsed to populate a vector with 100M elements:" << std::endl;
    std::cout << " sec :" << duration.tv_sec << std::endl;
    std::cout << " nanosec :" << duration.tv_nsec << std::endl;
    std::cout << "Finished ..." << std::endl;
}

// helper method
void timespec_diff(struct timespec* start, struct timespec* stop, struct timespec* result)
{
    if ((stop->tv_nsec - start->tv_nsec) < 0)
    {
        result->tv_sec = stop->tv_sec - start->tv_sec - 1;
        result->tv_nsec = stop->tv_nsec - start->tv_nsec + 1000000000;
    }
    else
    {
        result->tv_sec = stop->tv_sec - start->tv_sec;
        result->tv_nsec = stop->tv_nsec - start->tv_nsec;
    }
    return;
}

