#include <iostream>
#include <fstream>

int main ()
{
    std::ofstream fout;
    fout.open("file_01.txt");

    for (int i = 0; i < 10; ++i)
        fout << "User " << i << " => name_" << i << " surname_" << i << std::endl;

    fout.close();
}
