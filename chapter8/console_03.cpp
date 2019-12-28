#include <iostream>
#include <string>

int main ()
{
	std::string fullName;
	std::cout << "full Name: ";
	std::getline (std::cin, fullName);
	std::cout << "Hello " << fullName << std::endl;
	return 0;
}
