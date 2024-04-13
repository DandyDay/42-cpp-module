#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	~AForm();

	const std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(Bureaucrat &signer);
	void execute(Bureaucrat const &executor);
	virtual void beExecuted() = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();

		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();

		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		FormNotSignedException();

		const char *what() const throw();
	};

private:
	const std::string name_;
	bool isSigned_;
	const int signGrade_;
	const int executeGrade_;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
