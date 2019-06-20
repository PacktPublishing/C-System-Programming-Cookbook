#include <iostream>
#include <vector>

int main () {
	std::vector<int> a = {1, 2, 3, 4, 5};
	auto b = std::move(a);
	std::cout << "a: " << a.size() << std::endl;
	std::cout << "b: " << b.size() << std::endl;
}

