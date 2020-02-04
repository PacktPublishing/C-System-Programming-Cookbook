#include <iostream>
#include <queue>
#include <condition_variable>
#include <thread>

struct Item
{
	int age;
	std::string name;
	std::string surname;
};

std::queue<Item> queue;
std::condition_variable cond;
std::mutex mut;

void producer();
void consumer();

int main()
{
    std::thread t1 (producer);
    std::thread t2 (consumer);

    t1.join();
    t2.join();

    return 0;
}

void consumer()
{
	std::cout << "Consumer ... " << std::endl;
	while(true)
	{
		std::unique_lock<std::mutex> lck{mut};
		std::cout << "Consumer ... loop ... START" << std::endl;
		cond.wait(lck);
		// cond.wait(lck, []{ return !queue.empty();});
          	auto item = queue.front();
          	queue.pop();
		std::cout << "Age = " << item.age << " Name = " << item.name << " Surname = " << item.surname << std::endl;
		std::cout << "Queue Size = " << queue.size() << std::endl;
		std::cout << "Consumer ... loop ... END" << std::endl;
		lck.unlock();
	}
}

void producer()
{
	std::cout << "Producer ... " << std::endl;
	while(true)
	{
        	Item item;
        	item.age = 35;
		item.name = "Jack";
		item.surname = "Sparrow";
		std::lock_guard<std::mutex> lock {mut};
		std::cout << "Producer ... loop ... START" << std::endl;
          	queue.push(item);
          	cond.notify_one();
		std::cout << "Producer ... loop ... END" << std::endl;
     	}
}

