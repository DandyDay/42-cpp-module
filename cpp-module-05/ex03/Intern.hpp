#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	const static int kFormCount = 3;
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string name, std::string target);

	AForm *makeShrubberyCreationForm(std::string target);
	AForm *makeRobotomyRequestForm(std::string target);
	AForm *makePresidentialPardonForm(std::string target);

private:
	AForm *(Intern::*formMakingFuncs[kFormCount])(std::string target);
	std::string formNames[kFormCount];
};

#endif
