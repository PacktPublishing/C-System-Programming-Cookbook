#include <iostream>
#include <memory>

class User 
{
public: 
	User(){
		std::cout << "User Constructor" << std::endl;
	};

	~User(){
		std::cout << "User Destructor" << std::endl;
	};

	void cheers() {std::cout << " hello!" << std::endl;};
};

int main()
{
	std::cout << "Start ... " << std::endl;
	{
		auto developer = std::make_unique<User>();
		User* developer2 = new User();
		std::cout << "developer size = " << sizeof (developer) << std::endl; 
		std::cout << "developer2 size = " << sizeof (developer2) << std::endl; 
		delete developer2;
	}
	std::cout << "End ... " << std::endl;
}

