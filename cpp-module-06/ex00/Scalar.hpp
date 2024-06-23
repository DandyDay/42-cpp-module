#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>

#define UNDEFINED 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

union value {
	char c;
	int i;
	float f;
	double d;
};

class Scalar
{
public:
	Scalar();
	Scalar(std::string &literal);
	Scalar(const Scalar &other);
	Scalar &operator=(const Scalar &other);
	~Scalar();

	int getType();
	union value getValue();

private:
	bool parseChar(std::string &literal);
	bool parseInt(std::string &literal);
	bool parseFloat(std::string &literal);
	bool parseDouble(std::string &literal);

	int type;
	union value value;
};

#endif
