#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
	clearStack();
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		(void)other;
		clearStack();
	}
	return *this;
}

RPN::~RPN()
{
	clearStack();
}

int RPN::evaluateExpression(std::string expression)
{
	std::stringstream ss(expression);
	char c;
	clearStack();

	while (ss >> c)
	{
		if (isValidNum(c))
			stack.push(c - '0');
		else if (isValidOperator(c))
		{
			if (stack.size() < 2)
				throw std::invalid_argument("not valid postfix");
			int op1 = stack.top();
			stack.pop();
			int op2 = stack.top();
			stack.pop();
			switch (c)
			{
			case '+':
				stack.push(op2 + op1);
				break;
			case '-':
				stack.push(op2 - op1);
				break;
			case '*':
				stack.push(op2 * op1);
				break;
			case '/':
				stack.push(op2 / op1);
				break;
			}
		}
		else
			throw std::invalid_argument("not valid input");
	}

	if (stack.size() != 1)
		throw std::invalid_argument("not valid postfix");

	return stack.top();
}

bool RPN::isValidNum(char c)
{
	if ('0' <= c && c <= '9')
		return true;
	else
		return false;
}

bool RPN::isValidOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

void RPN::clearStack()
{
	stack = std::stack<int>();
}
