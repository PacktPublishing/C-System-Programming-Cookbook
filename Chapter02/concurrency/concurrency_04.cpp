#include <iostream>
#include <future>

void asyncProducer(std::promise<int> &prom);
void asyncConsumer(std::future<int> &fut);

int main()
{
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::async(asyncProducer, std::ref(prom));
    std::async(asyncConsumer, std::ref(fut));

    std::cout << "Async Producer-Consumer ended!" << std::endl;
    return 0;
}
void asyncConsumer(std::future<int> &fut)
{
    std::cout << "Got " << fut.get() << " from the producer ... " << std::endl;
}

void asyncProducer(std::promise<int> &prom)
{
    std::cout << " sending 5 to the consumer ... " << std::endl;
    prom.set_value (5);
}


