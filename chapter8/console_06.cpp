#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main ()
{
	std::ifstream inFile ("file_console_05.txt", std::ifstream::in);

	std::string line;
	while( std::getline(inFile, line) )
	{
		std::stringstream sline(line);
		std::string name, surname; int age;
		sline >> name >> surname >> age;
		std::cout << name << "-" << surname << "-"<< age << std::endl;
	}
	return 0;
}
