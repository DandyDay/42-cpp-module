#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./RPN [postfix expression]" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn;
		std::string expression(argv[1]);
		std::cout << rpn.evaluateExpression(expression) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << "." << std::endl;
	}

	return 0;
}
