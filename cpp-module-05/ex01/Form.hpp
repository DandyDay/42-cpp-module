#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(Bureaucrat &bureaucrat);

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

private:
	const std::string name_;
	bool isSigned_;
	const int signGrade_;
	const int executeGrade_;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
