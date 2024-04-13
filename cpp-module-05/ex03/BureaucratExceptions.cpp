#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too High!";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!";
}
