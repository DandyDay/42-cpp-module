#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : grade_(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name_(other.name_), grade_(other.grade_)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade_ = other.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return name_;
}

int Bureaucrat::getGrade() const
{
	return grade_;
}

void Bureaucrat::incrementGrade()
{
	if (grade_ <= 1)
		throw GradeTooHighException();
	--grade_;
}

void Bureaucrat::decrementGrade()
{
	if (grade_ >= 150)
		throw GradeTooLowException();
	++grade_;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name_ << " couldn't sign " << form.getName() << " because "
				  << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name_ << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
