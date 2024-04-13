#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Test 1
	std::cout << "----------Test 1----------" << std::endl;
	try
	{
		Bureaucrat b1("bureaucrat A", 1);
		Form f1("Form A", 10, 5);

		std::cout << b1 << std::endl;
		std::cout << std::endl;
		std::cout << f1 << std::endl;
		std::cout << std::endl;

		b1.signForm(f1);

		std::cout << std::endl;
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 2
	std::cout << "----------Test 2----------" << std::endl;
	try
	{
		Bureaucrat b1("bureaucrat A", 10);
		Form f1("Form A", 10, 5);
		Bureaucrat b2("bureaucrat B", 11);
		Form f2("Form B", 10, 5);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << std::endl;

		b1.signForm(f1);
		std::cout << std::endl;
		std::cout << f1 << std::endl;
		std::cout << std::endl;

		b2.signForm(f2);
		std::cout << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
