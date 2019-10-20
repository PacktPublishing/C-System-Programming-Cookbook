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
	auto shared1 = std::make_shared<User>();
	{
		auto shared2 = shared1;
	        User* newAllocation = new User();
		std::unique_ptr<User> uniqueAllocation = std::make_unique<User>();

                std::cout << "shared2 size = " << sizeof (shared2) << std::endl;
                std::cout << "newAllocation size = " << sizeof (newAllocation) << std::endl;
                std::cout << "uniqueAllocation size = " << sizeof (uniqueAllocation) << std::endl;
                delete newAllocation;
	}
	std::cout << "End ... " << std::endl;
}

