#include <type_traits>
#include <iostream>

int main()
{
    std::cout << "int alignment = " << std::alignment_of<int>::value << std::endl;
    std::cout << "double alignment = " << std::alignment_of<double>::value << std::endl;

    return (0);
}

