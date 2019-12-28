#include <pthread.h> 
#include <iostream>

struct ThreadInfo 
{
	pthread_mutex_t lock;
	int counter;	
};

void* increment(void *arg) 
{ 
	ThreadInfo* info = static_cast<ThreadInfo*>(arg);
	pthread_mutex_lock(&info->lock);

	std::cout << "Thread Started ... " << std::endl;

	for (int i = 0; i < 100000; ++i) 
		info->counter++;

	std::cout << "Thread Finished ... " << std::endl;
	pthread_mutex_unlock(&info->lock); 
	return nullptr; 
} 

int main() 
{ 
	ThreadInfo thInfo;
	thInfo.counter = 0;
	if (pthread_mutex_init(&thInfo.lock, nullptr) != 0) 
	{ 
		std::cout << "pthread_mutex_init failed!" << std::endl;
		return 1; 
	} 

	pthread_t t1; 
	if (pthread_create(&t1, nullptr, &increment, &thInfo) != 0) 
	{
		std::cout << "pthread_create for t1 failed! " << std::endl;
		return 2;
	}

	pthread_t t2; 
	if (pthread_create(&t2, nullptr, &increment, &thInfo) != 0) 
	{
		std::cout << "pthread_create for t2 failed! " << std::endl;
		return 3;
	}

	pthread_join(t1, nullptr); 
	pthread_join(t2, nullptr); 

	std::cout << "Threads elaboration finished. Counter = " << thInfo.counter << std::endl;
	pthread_mutex_destroy(&thInfo.lock); 
	return 0; 
}

