#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("robotomy request", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target_(other.target_)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::beExecuted()
{
	std::cout << "drrrrrrrrrrr..." << std::endl;
	if (time(0) % 2 == 0)
		std::cout << target_ << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomizing " << target_ << " failed." << std::endl;
}
