#include "utils.hpp"
#include <iostream>

int main()
{
	for (int i = 0; i < 5; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
	}
	return 0;
}
