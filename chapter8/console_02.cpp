#include <iostream>
#include <string>

int main ()
{
	std::string fullNameWithCin;
	std::cout << "full Name got with cin: ";
	std::cin >> fullNameWithCin;

	std::cout << "hello " << fullNameWithCin << std::endl;
	return 0;
}
