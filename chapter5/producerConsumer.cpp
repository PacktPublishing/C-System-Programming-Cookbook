#include <pthread.h> 
#include <semaphore.h>
#include <iostream>
#include <vector>

constexpr auto MAX_ITEM_IN_QUEUE = 5;

struct QueueInfo 
{
	sem_t mutex;
	sem_t full;
	sem_t empty;
        std::vector<int> queue;
};

void* producer(void *arg) 
{ 
	QueueInfo* info = (QueueInfo*)arg;
	std::cout << "Thread Producer Started ... " << std::endl;
    	for (int i = 0; i < 1000; i++) 
	{
        	sem_wait(&info->full);
 
        	sem_wait(&info->mutex);
		info->queue.push_back(i);
		std::cout << "Thread Producer Started ... size = " << info->queue.size() << std::endl;
        	sem_post(&info->mutex);

        	sem_post(&info->empty);
    	}

	std::cout << "Thread Producer Finished ... " << std::endl;
	return nullptr; 
} 


void* consumer(void *arg) 
{ 
	QueueInfo* info = (QueueInfo*)arg;
	std::cout << "Thread Consumer Started ... " << std::endl;
    	for (int i = 0; i < 1000; i++) 
	{
        	sem_wait(&info->empty);

        	sem_wait(&info->mutex);
		if (!info->queue.empty())
		{
			int b = info->queue.back();
			info->queue.pop_back();
		}
		std::cout << "Thread Consumer Started ... size = " << info->queue.size() << std::endl;
        	sem_post(&info->mutex);

        	sem_post(&info->full);
    	}

	std::cout << "Thread Consumer Finished ... " << std::endl;
	return nullptr; 
} 

int main() 
{ 
	QueueInfo thInfo;
	if (sem_init(&thInfo.mutex, 0, 1) != 0 ||
	    sem_init(&thInfo.full, 0, MAX_ITEM_IN_QUEUE) != 0 || 
	    sem_init(&thInfo.empty, 0, 0) != 0) 
	{ 
		std::cout << "sem_init failed!" << std::endl;
		return 1; 
	} 

	pthread_t producerPthread; 
	if (pthread_create(&producerPthread, nullptr, &producer, &thInfo) != 0) 
	{
		std::cout << "pthread_create for producer failed! " << std::endl;
		return 2;
	}

	pthread_t consumerPthread; 
	if (pthread_create(&consumerPthread, nullptr, &consumer, &thInfo) != 0) 
	{
		std::cout << "pthread_create for consumer failed! " << std::endl;
		return 3;
	}

	pthread_join(producerPthread, nullptr); 
	pthread_join(consumerPthread, nullptr); 

	sem_destroy(&thInfo.mutex); 
	sem_destroy(&thInfo.full); 
	sem_destroy(&thInfo.empty); 
	return 0; 
}

