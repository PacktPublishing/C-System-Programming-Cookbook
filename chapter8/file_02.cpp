#include <iostream>
#include <fstream>

int main ()
{
    std::ifstream fiut;
    fiut.open("file_01.txt");

    std::string line;
    while (std::getline(fiut, line))
    {
        std::cout << line << std::endl;
    }

    fiut.close();
}
