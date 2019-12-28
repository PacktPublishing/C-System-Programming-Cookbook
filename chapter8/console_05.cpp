#include <iostream>
#include <string>
#include <fstream>

int main ()
{
	std::ifstream inFile ("file_console_05.txt", std::ifstream::in);

	std::string line;
	while( std::getline(inFile, line) )
		std::cout << line << std::endl;

	return 0;
}
