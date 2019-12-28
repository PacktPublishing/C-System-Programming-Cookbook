#include <iostream>
#include <fstream>

int main ()
{
    std::fstream fstr;
    fstr.open("file_03.txt", std::ios::trunc | std::ios::out | std::ios::in);

    std::ifstream fiut;
    fiut.open("file_01.txt");
    std::string line;
    while (std::getline(fiut, line))
        fstr << line << std::endl;
    fiut.close();

    fstr.seekg(0, std::ios::beg);
    while (std::getline(fstr, line))
        std::cout << line << std::endl; 

    fstr.close();
}
