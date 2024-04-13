#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";

	formMakingFuncs[0] = &Intern::makeShrubberyCreationForm;
	formMakingFuncs[1] = &Intern::makeRobotomyRequestForm;
	formMakingFuncs[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	for (int i = 0; i < kFormCount; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*(formMakingFuncs[i]))(target);
		}
	}
	throw std::logic_error("intern doesn't know how to create " + name);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
