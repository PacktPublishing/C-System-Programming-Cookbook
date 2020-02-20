#include <iostream>

class User 
{
public: 
	User(){};

	~User(){};

	void cheers() {std::cout << " hello!" << std::endl;};
};

int main()
{
	std::cout << "Start ... " << std::endl;
	{
		User* developer = new User(); 
		developer->cheers();
		delete developer;
	}
	std::cout << "End ... " << std::endl;
}

