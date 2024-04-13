#include "Form.hpp"

Form::Form() : isSigned_(false), signGrade_(150), executeGrade_(150)
{
}

Form::Form(std::string name, int signGrade, int executeGrade)
	: name_(name), isSigned_(false), signGrade_(signGrade),
	  executeGrade_(executeGrade)
{
	if (signGrade_ < 1 || executeGrade_ < 1)
		throw GradeTooHighException();
	else if (signGrade_ > 150 || executeGrade_ > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: name_(other.name_), isSigned_(false), signGrade_(other.signGrade_),
	  executeGrade_(other.executeGrade_)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		isSigned_ = other.isSigned_;
	}
	return *this;
}

Form::~Form()
{
}

const std::string Form::getName() const
{
	return name_;
}

bool Form::getIsSigned() const
{
	return isSigned_;
}

int Form::getSignGrade() const
{
	return signGrade_;
}

int Form::getExecuteGrade() const
{
	return executeGrade_;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (signGrade_ < bureaucrat.getGrade())
		throw GradeTooLowException();
	else
	{
		isSigned_ = true;
	}
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form Information" << std::endl;
	os << "Name: " << f.getName() << std::endl;
	os << "Status: " << (f.getIsSigned() ? "Signed" : "Not signed")
	   << std::endl;
	os << "Grade to Sign: " << f.getSignGrade() << std::endl;
	os << "Grade to Execute: " << f.getExecuteGrade();
	return os;
}
