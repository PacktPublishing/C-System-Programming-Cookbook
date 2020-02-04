#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
	std::vector<int> v {1, 2, 3, 4, 5, 6};
	std::string prefix ("0");
	for_each (begin(v), end(v), [&prefix](int x) {std::cout << prefix << x << std::endl;});
	return 0;
}

