/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:59:00 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/08/27 15:46:22 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx_(0), count_(0)
{

}

void	PhoneBook::add_contact()
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "First Name: ";
	getline(std::cin, first_name);
	if (check_stdin_err())
		return ;
	std::cout << "Last Name: ";
	getline(std::cin, last_name);
	if (check_stdin_err())
		return ;
	std::cout << "Nickname: ";
	getline(std::cin, nickname);
	if (check_stdin_err())
		return ;
	std::cout << "Phone Number: ";
	getline(std::cin, phone_number);
	if (check_stdin_err())
		return ;
	std::cout << "Darkest Secret: ";
	getline(std::cin, darkest_secret); 
	if (check_stdin_err())
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
	for (int i = 0; i < count_; i++)
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << get_fitted_string(contacts_[i].get_first_name()) << "|";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << get_fitted_string(contacts_[i].get_last_name()) << "|";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << get_fitted_string(contacts_[i].get_nickname()) << std::endl;
	}
	if (count_ == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	std::cout << "Which index: ";
	std::cin >> idx;
	std::cin.ignore();
	if (check_stdin_err())
		return ;
	if (std::cin.fail())
	{
		fflush(stdin);
		std::cout << "Not an integer input" << std::endl;
		std::cin.clear();
	}
	else if (0 <= idx && idx < count_)
		contacts_[idx].print_contact();
	else
		std::cout << "Input index out of range" << std::endl;
}

std::string	PhoneBook::get_fitted_string(std::string original)
{
	if (original.length() > 10)
		return (original.substr(0, 9) + ".");
	else
		return (original);
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
		std::cout << "Wrong input" << std::endl;
		return (true);
	}
	return (false);
}
