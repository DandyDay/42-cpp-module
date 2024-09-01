#include "MutantStack.hpp"
#include <iostream>

int main()
{
	std::cout << "TEST 1 - basic test" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "stack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "stack.size(): " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "stack iterator" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "TEST 2 - reverse iterator test" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "stack reverse iterator" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "TEST 3 - const iterator test" << std::endl;
	MutantStack<int> cstack;
	for (int i = 0; i < 10; i++)
		cstack.push(i);
	MutantStack<int>::const_iterator cit = cstack.begin();
	MutantStack<int>::const_iterator cite = cstack.end();
	std::cout << "stack const iterator" << std::endl;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	return 0;
}
