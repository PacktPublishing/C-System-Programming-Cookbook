#include <type_traits>
#include <iostream>

using intAligned8 = std::aligned_storage<sizeof(int), 8>::type;
using intAligned4 = std::aligned_storage<sizeof(int), 4>::type;

int main()
{
	intAligned8 i; new (&i) int();
	intAligned4 j; new (&j) int();
	int* iu = &reinterpret_cast<int&>(i);
	*iu = 12;

	int* ju = &reinterpret_cast<int&>(j);
	*ju = 13;

	if (reinterpret_cast<unsigned long>(iu) % 8 == 0)
		std::cout << "memory pointed by the <iu> variable aligned to 8 byte" << std::endl;
	else
		std::cout << "memory pointed by the <iu> variable NOT aligned to 8 bytes" << std::endl;
	if (reinterpret_cast<unsigned long>(ju) % 8 == 0)
		std::cout << "memory pointed by the <ju> variable aligned to 8 bytes" << std::endl;
	else
		std::cout << "memory pointed by the <ju> variable NOT aligned to 8 bytes" << std::endl;

    	return (0);
}

