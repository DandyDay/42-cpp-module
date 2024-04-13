#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("presidential pardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("presidential pardon", 25, 5), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &other)
	: AForm(other), target_(other.target_)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::beExecuted()
{
	std::cout << "Zaphod Beeblebrox, in his infinite wisdom, has graciously "
				 "pardoned "
			  << target_ << "." << std::endl;
}
