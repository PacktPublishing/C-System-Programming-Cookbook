#include <iostream>
#include <memory>

class User
{
public:
    User()
    {
        std::cout << "User costructor" << std::endl;
    };
    ~User()
    {
        std::cout << "User Destructor" << std::endl;
    };

    void cheers() 
    {
        std::cout << " hello!" << std::endl;
    };
};

int main()
{
	std::cout << "Start ... " << std::endl;
	{
		std::unique_ptr<User> developer = std::make_unique<User>();
		developer->cheers();
	}	
	std::cout << "End ... " << std::endl;
}

