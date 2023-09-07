/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:59:00 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/03 19:41:59 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cstdio>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : idx_(0), count_(0)
{

}

void	PhoneBook::add_contact()
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "First Name: ";
	getline(std::cin, first_name);
	if (check_stdin_err() || check_string_input(first_name))
		return ;
	std::cout << "Last Name: ";
	getline(std::cin, last_name);
	if (check_stdin_err() || check_string_input(last_name))
		return ;
	std::cout << "Nickname: ";
	getline(std::cin, nickname);
	if (check_stdin_err() || check_string_input(nickname))
		return ;
	std::cout << "Phone Number(Only Digits): ";
	getline(std::cin, phone_number);
	if (check_stdin_err() || check_numeric_input(phone_number))
		return ;
	std::cout << "Darkest Secret: ";
	getline(std::cin, darkest_secret); 
	if (check_stdin_err() || check_string_input(darkest_secret))
		return ;
	contacts_[idx_] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	idx_ = (idx_ + 1) % 8;
	if (count_ < 8)
		count_++;
}

void	PhoneBook::search_contact()
{
	int	idx;

	std::cout << "     index|first_name| last_name|  nickname" << std::endl;
	std::cout << std::setfill(' ');
	for (int i = 0; i < count_; i++)
	{
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setw(10);
		std::cout << get_fitted_string(contacts_[i].get_first_name()) << "|";
		std::cout << std::setw(10);
		std::cout << get_fitted_string(contacts_[i].get_last_name()) << "|";
		std::cout << std::setw(10);
		std::cout << get_fitted_string(contacts_[i].get_nickname()) << std::endl;
	}
	if (count_ == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	std::cout << "Which index?: ";
	std::cin >> idx;
	std::cin.ignore();
	if (std::cin.fail())
	{
		fflush(stdin);
		std::cout << "Not an integer input" << std::endl;
		std::cin.clear();
		clearerr(stdin);
	}
	else if (check_stdin_err())
		return ;
	else if (0 <= idx && idx < count_)
		contacts_[idx].print_contact();
	else
		std::cout << "Input index out of range" << std::endl;
}

std::string	PhoneBook::get_fitted_string(std::string original)
{
	std::string str;

	str = original;
	for (std::size_t i = 0; i < str.length(); i++)
		if (str[i] == '\t')
			str[i] = ' ';
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

bool PhoneBook::check_stdin_err()
{
	if (std::cin.eof())
	{
		clearerr(stdin);
		std::cin.clear();
		std::cout << "EOF detected" << std::endl;
		return (true);
	}
	else if (std::cin.fail())
	{
		clearerr(stdin);
		std::cin.clear();
		fflush(stdin);
		std::cout << "Wrong input" << std::endl;
		return (true);
	}
	return (false);
}

bool PhoneBook::check_string_input(std::string str)
{
	if (str.length() > 0)
		return false;
	else
	{
		std::cout << "Empty argument not allowed" << std::endl;
		return true;
	}
}

bool PhoneBook::check_numeric_input(std::string str)
{
	if (check_string_input(str))
		return true;
	for (std::size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (!std::isdigit(c) && !std::isspace(c))
		{
			std::cout << "Numeric arguments required" << std::endl;
			return true;
		}
	}
	return false;
}
