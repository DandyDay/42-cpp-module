#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("shrubbery creation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("shrubbery creation", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target_(other.target_)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::beExecuted()
{
	std::ofstream ofs((target_ + "_shrubbery").c_str());
	ofs << "              v .   ._, |_  .,                \n"
		   "           `-._\\/  .  \\ /    |/_              \n"
		   "               \\\\  _\\, y | \\//                \n"
		   "         _\\_.___\\\\, \\\\/ -.\\||                        _-_\n"
		   "           `7-,--.`._||  / / ,                    /~~   ~~\\\n"
		   "           /'     `-. `./ / |/_.'              /~~         ~~\\\n"
		   "                     |    |//                 {               }\n"
		   "                     |_    /                   \\  _-     -_  /\n"
		   "                     |-   |                      ~  \\\\ //  ~\n"
		   "                     |   =|                   _- -   | | _- _\n"
		   "                     |    |                     _ -  | |   -_\n"
		   "--------------------/ ,  . \\------------------------// \\\\----\n"
		<< std::endl;
	ofs.close();
}
