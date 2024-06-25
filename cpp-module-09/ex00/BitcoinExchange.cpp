#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream ifs(filename);
	if (ifs.fail())
		throw databaseException("could not open data.csv");

	std::string buffer;
	float exchangeRate;

	std::getline(ifs, buffer);
	if (buffer.compare("date,exchange_rate"))
		throw databaseException("wrong database format");

	while (std::getline(ifs, buffer))
	{
		std::string dateBuffer;
		std::string exchangeRateBuffer;
		std::getline(ifs, dateBuffer, ',');
		std::getline(ifs, exchangeRateBuffer);
		if (!ifs.eof() && (ifs.bad() || ifs.fail()))
			throw databaseException("database exception");
		exchangeRate = std::atof(exchangeRateBuffer.c_str());
		if (!isValidDate(dateBuffer) || exchangeRate < 0)
			throw databaseException("wrong data format");
		priceChart.insert(std::make_pair(dateBuffer, exchangeRate));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::map<std::string, float>::const_iterator it;
	for (it = other.priceChart.begin(); it != other.priceChart.end(); it++)
	{
		priceChart[it->first] = it->second;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		priceChart.clear();
		std::map<std::string, float>::const_iterator it;
		for (it = other.priceChart.begin(); it != other.priceChart.end(); it++)
		{
			priceChart[it->first] = it->second;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	priceChart.clear();
}

void BitcoinExchange::printPriceChart()
{
	std::map<std::string, float>::const_iterator it;
	for (it = priceChart.begin(); it != priceChart.end(); it++)
	{
		std::cout << "item: " << it->first << ": " << it->second << std::endl;
	}
}

void BitcoinExchange::evaluatePrices(const std::string &filename)
{
	std::ifstream ifs(filename);
	if (ifs.fail())
		return; // error
	std::string lineBuffer;

	std::getline(ifs, lineBuffer);
	if (lineBuffer.compare("date | value"))
		throw std::invalid_argument("wrong input file format.");
	while (std::getline(ifs, lineBuffer))
	{
		try
		{
			evaluatePrice(lineBuffer);
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::isValidDate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) &&
		(day < 1 || day > 30))
		return false;
	if (month == 2)
	{
		bool isLeapYear =
			(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if ((isLeapYear && (day > 29)) || (!isLeapYear && (day > 28)))
			return false;
	}
	return true;
}

void BitcoinExchange::evaluatePrice(std::string line)
{
	if (line.find('|') == std::string::npos)
		throw std::invalid_argument("bad input => " + line);
	std::string dateBuffer;
	float coinCount;
	std::stringstream ss(line);
	std::getline(ss, dateBuffer, '|');
	dateBuffer.erase(dateBuffer.find_last_not_of(" \t\n") + 1);
	ss >> coinCount;
	if (!ss.eof())
		throw std::invalid_argument("bad input => " + line);
	if (!isValidDate(dateBuffer))
		throw std::invalid_argument("wrong date format => " + dateBuffer);
	if (coinCount <= 0)
		throw std::invalid_argument("not a positive number.");
	if (coinCount >= 1000)
		throw std::invalid_argument("too large a number.");

	float price = findCurrentPrice(dateBuffer) * coinCount;
	std::cout << dateBuffer << " => " << coinCount << " = " << price
			  << std::endl;
}

float BitcoinExchange::findCurrentPrice(std::string date)
{
	std::map<std::string, float>::const_iterator it;
	for (it = priceChart.begin(); it != priceChart.end(); it++)
	{
		if (it->first.compare(date) > 0)
			break;
	}
	if (it == priceChart.begin())
		throw std::invalid_argument("no exchange rate information on " + date);
	it--;
	return it->second;
}
