#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	// Test 1
	std::cout << "----------Test 1----------" << std::endl;
	try
	{
		Bureaucrat b1("Bureaucrat A", 1);
		ShrubberyCreationForm f1("targetA");
		RobotomyRequestForm f2("targetB");
		PresidentialPardonForm f3("targetC");

		b1.executeForm(f1);
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << std::endl;

		b1.executeForm(f2);
		b1.signForm(f2);
		b1.executeForm(f2);
		b1.executeForm(f2);
		b1.executeForm(f2);
		b1.executeForm(f2);
		b1.executeForm(f2);
		std::cout << std::endl;

		b1.executeForm(f3);
		b1.signForm(f3);
		b1.executeForm(f3);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test 2
	std::cout << "----------Test 2----------" << std::endl;
	try
	{
		Bureaucrat b1("Bureaucrat B", 150);
		Bureaucrat b2("Signer", 1);
		ShrubberyCreationForm f1("targetD");
		RobotomyRequestForm f2("targetE");
		PresidentialPardonForm f3("targetF");

		b2.signForm(f1);
		b1.executeForm(f1);
		std::cout << std::endl;

		b2.signForm(f2);
		b1.executeForm(f2);
		std::cout << std::endl;

		b2.signForm(f3);
		b1.executeForm(f3);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
