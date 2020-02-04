#include <iostream>
#include <vector>

void print (std::string &&s)
{
    std::cout << "print (std::string &&s)" << std::endl;
    std::string str (std::move(s));
    std::cout << "universal reference ==> str = " << str << std::endl;
    std::cout << "universal reference ==> s = " << s << std::endl;
}

void print (std::string &s)
{
    std::cout << "print (std::string &s)" << std::endl;
}

int main()
{
    std::string str ("this is a string");
    print (str);
    std::cout << "==> str = " << str << std::endl;
    return 0;
}

