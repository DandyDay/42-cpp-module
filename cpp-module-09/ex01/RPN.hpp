#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int evaluateExpression(std::string expression);

private:
	bool isValidNum(char c);
	bool isValidOperator(char c);

	void clearStack();

	std::stack<int> stack;
};

#endif
