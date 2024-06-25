#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void printPriceChart();
	void evaluatePrices(const std::string &filename);

	class notValidDateException : public std::invalid_argument
	{
	public:
		notValidDateException() : invalid_argument("not valid date")
		{
		}
	};

	class databaseException : public std::invalid_argument
	{
	public:
		databaseException(const std::string &msg) : invalid_argument(msg)
		{
		}
	};

private:
	bool isValidDate(std::string date);
	void evaluatePrice(std::string line);
	float findCurrentPrice(std::string date);

	std::map<std::string, float> priceChart;
};

#endif
