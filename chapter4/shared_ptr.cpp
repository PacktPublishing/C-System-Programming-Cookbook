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
		shared2->cheers(); std::cout << " from shared2" << std::endl;
		shared1->cheers(); std::cout << " from shared1" << std::endl;
	}
	std::cout << "End ... " << std::endl;
}

