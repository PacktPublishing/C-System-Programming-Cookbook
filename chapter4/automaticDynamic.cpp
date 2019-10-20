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
		User developer;
		developer.cheers();
	}
	std::cout << "End ... " << std::endl;
}

