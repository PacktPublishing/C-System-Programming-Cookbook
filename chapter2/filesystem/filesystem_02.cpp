#include <iostream>
#include <filesystem>
#include <fstream>

int main()
{
    std::filesystem::create_directories("test/src/config");
    std::ofstream("test/src/file.txt") << "This is an example!" << std::endl;
}


