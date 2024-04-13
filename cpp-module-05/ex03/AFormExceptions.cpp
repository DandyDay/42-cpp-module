#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException()
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

AForm::GradeTooLowException::GradeTooLowException()
{
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

AForm::FormNotSignedException::FormNotSignedException()
{
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}
