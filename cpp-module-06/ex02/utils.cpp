#include "Base.hpp"
#include <cstdlib>
#include <iostream>

unsigned int myrand(long seedin)
{
	static long seed = 0;
	if (seed == 0)
		seed = seedin;
	const unsigned int a = 1664525;
    const unsigned int c = 1013904223;
	seed = a * seed + c;
    return seed;
}


Base *generate(void)
{
	int num = myrand(time(NULL));
	if (num % 3 == 0)
	{
		A *a = new A();
		std::cout << "generating A..." << std::endl;
		return dynamic_cast<Base *>(a);
	}
	else if (num % 3 == 1)
	{
		B *b = new B();
		std::cout << "generating B..." << std::endl;
		return dynamic_cast<Base *>(b);
	}
	else
	{
		C *c = new C();
		std::cout << "generating C..." << std::endl;
		return dynamic_cast<Base *>(c);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "this is class A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "this is class B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "this is class C" << std::endl;
	else
		std::cout << "unknown error" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "this is class A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			B b = dynamic_cast<B &>(p);
			std::cout << "this is class B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				C c = dynamic_cast<C &>(p);
				std::cout << "this is class C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "unknown error" << std::endl;
			}
		}
	}
}
