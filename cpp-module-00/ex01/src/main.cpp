/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:58:00 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/08/29 17:26:39 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	command;

	while (true)
	{
		std::cout << "command(ADD, SEARCH, EXIT): ";
		getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "EOF detected" << std::endl;
			clearerr(stdin);
			std::cin.clear();
		}
		else if (command == "ADD")
		{
			phone_book.add_contact();
		}
		else if (command == "SEARCH")
		{
			phone_book.search_contact();
		}
		else if (command == "EXIT")
		{
			std::cout << "exit" << std::endl;
			return (0);
		}
		else
		{
			std::cout << "Wrong Command: ADD, SEARCH, EXIT expected" << std::endl;
		}
	}
	return (0);
}
