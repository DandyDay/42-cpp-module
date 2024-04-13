#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

Form::GradeTooLowException::GradeTooLowException()
{
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
