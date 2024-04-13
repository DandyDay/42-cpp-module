#include "AForm.hpp"

AForm::AForm() : isSigned_(false), signGrade_(150), executeGrade_(150)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: name_(name), isSigned_(false), signGrade_(signGrade),
	  executeGrade_(executeGrade)
{
	if (signGrade_ < 1 || executeGrade_ < 1)
		throw GradeTooHighException();
	else if (signGrade_ > 150 || executeGrade_ > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name_(other.name_), isSigned_(false), signGrade_(other.signGrade_),
	  executeGrade_(other.executeGrade_)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		isSigned_ = other.isSigned_;
	}
	return *this;
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return name_;
}

bool AForm::getIsSigned() const
{
	return isSigned_;
}

int AForm::getSignGrade() const
{
	return signGrade_;
}

int AForm::getExecuteGrade() const
{
	return executeGrade_;
}

void AForm::beSigned(Bureaucrat &signer)
{
	if (signGrade_ < signer.getGrade())
		throw GradeTooLowException();
	else
	{
		isSigned_ = true;
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm Information" << std::endl;
	os << "Name: " << f.getName() << std::endl;
	os << "Status: " << (f.getIsSigned() ? "Signed" : "Not signed")
	   << std::endl;
	os << "Grade to Sign: " << f.getSignGrade() << std::endl;
	os << "Grade to Execute: " << f.getExecuteGrade();
	return os;
}

void AForm::execute(Bureaucrat const &executor)
{
	if (executeGrade_ < executor.getGrade())
		throw GradeTooLowException();
	else if (!isSigned_)
		throw FormNotSignedException();
	else
		beExecuted();
}
