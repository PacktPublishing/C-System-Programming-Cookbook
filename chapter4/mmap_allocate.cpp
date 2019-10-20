#include <sys/mman.h>
#include <iostream>
#include <cstring>

constexpr auto SIZE = 1024;

int main(int argc, char *argv[])
{
    auto* mapPtr = (char*) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mapPtr == MAP_FAILED) 
    {
	std::cout << "Error mapping memory " << std::endl;
	return 1;
    }
    std::cout << "memory allocated availabe from: " << mapPtr << std::endl;

    strcpy (mapPtr, "this is a string!");
    std::cout << "mapPtr val =  " << mapPtr << std::endl;
 
    if (munmap(mapPtr, SIZE) == -1)
	std::cout << "Error un-mapping" << std::endl;

    return 0;
}

