/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:45:56 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/13 23:54:13 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>
#include <string>

Harl::Harl()
{
	commands_[570] = "DEBUG";
	commands_[396] = "INFO";
	commands_[337] = "WARNING";
	commands_[5] = "ERROR";
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destoryed" << std::endl;
}

void Harl::complain(std::string level)
{
	unsigned int string_hash = Harl::djb2_hash(level.c_str());
	if (level.compare(commands_[string_hash]) == 0)
		switch (string_hash)
		{
			case 570:
				Harl::debug();
			case 396:
				Harl::info();
			case 337:
				Harl::warning();
			case 5:
				Harl::error();
				break;
			default:
				Harl::undefined();
				break;
		}
}

void Harl::complain(const char *level)
{
	if (level == NULL)
		return ;
	else
		Harl::complain(std::string(level));
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::undefined(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
}

unsigned int Harl::djb2_hash(const char* str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % 1009;
}
