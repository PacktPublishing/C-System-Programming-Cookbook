 #include <iostream>

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
    print ("this is a string");
    return 0;
}


