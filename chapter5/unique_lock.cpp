#include <iostream>
#include <mutex>
#include <thread>

struct ThreadInfo 
{
	std::mutex mutex;
	int counter;	
};

void increment(ThreadInfo &info)
{
	std::unique_lock<std::mutex> lock(info.mutex);
	std::cout << "Thread Started ... " << std::endl;

	if (info.counter < 0)
	{
		lock.unlock();
		return;
	}

	for (int i = 0; i < 100000; ++i) 
		info.counter++;

	std::cout << "Thread Finished ... " << std::endl;
} 

int main() 
{ 
	ThreadInfo thInfo;
	thInfo.counter = 0;

	std::thread t1 (increment, std::ref(thInfo));
	std::thread t2 (increment, std::ref(thInfo));

	t1.join();
	t2.join();

	std::cout << "Threads elaboration finished. Counter = " << thInfo.counter << std::endl;
	return 0; 
}

