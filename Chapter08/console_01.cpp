#include <iostream>
#include <string>

int main ()
{
	std::string name;
	std::cout << "name: ";
	std::cin >> name;

	std::string surname;
	std::cout << "surname: ";
	std::cin >> surname;

	int age;
	std::cout << "age: ";
	std::cin >> age;

	std::cout << "Hello " << name << ", " << surname << ": " << age << std::endl;
	return 0;
}
