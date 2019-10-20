#include <iostream>
#include <future>

struct Item
{
	int age;
	std::string nameCode;
	std::string surnameCode;
};

void asyncProducer(std::promise<Item> &prom);
void asyncConsumer(std::future<Item> &fut);

int main()
{
    std::promise<Item> prom;
    std::future<Item> fut = prom.get_future();

    std::async(asyncProducer, std::ref(prom));
    std::async(asyncConsumer, std::ref(fut));

    return 0;
}

void asyncConsumer(std::future<Item> &fut)
{

	std::cout << "Consumer ... got the result " << std::endl;
	Item item = fut.get();
	std::cout << "Age = " << item.age << " Name = " << item.nameCode 
		  << " Surname = " << item.surnameCode << std::endl;
}

void asyncProducer(std::promise<Item> &prom)
{
	std::cout << "Producer ... computing " << std::endl;

	// just returning an item! In reality this thread most likely
	// perform a high intensive computation to retrive an item and 
	// returning the output to a client (future) which is waiting the 
	// results.
    	Item item;
        item.age = 35;
	item.nameCode = "Jack";
	item.surnameCode = "Sparrow";

        prom.set_value(item);
}

