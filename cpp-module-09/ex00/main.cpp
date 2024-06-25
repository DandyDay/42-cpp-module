#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./btc [filename]" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc("data.csv");
		std::string filename(argv[1]);
		btc.evaluatePrices(filename);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << "." << std::endl;
	}

	return 0;
}
