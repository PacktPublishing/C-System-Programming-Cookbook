#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main ()
{
    std::stringstream sline;
    for (int i = 0; i < 10; ++i)
        sline << "name = name_" << i << ", age = " << i*7 << std::endl;

    std::cout << sline.str();
	return 0;
}
