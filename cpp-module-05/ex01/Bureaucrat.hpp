#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(Form &form);

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
	int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
