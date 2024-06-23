#include "functions.hpp"
#include <iostream>

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
	}
	return 0;
}
