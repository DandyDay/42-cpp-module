/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:45:56 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/13 19:30:42 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>
#include <string>

Harl::Harl()
{
	fp[570] = &Harl::debug;
	fp[396] = &Harl::info;
	fp[337] = &Harl::warning;
	fp[5] = &Harl::error;

	commands_[570] = "DEBUG";
	commands_[396] = "INFO";
	commands_[337] = "WARNING";
	commands_[5] = "ERROR";
}

Harl::~Harl()
{

}

void Harl::complain(std::string level)
{
	unsigned int string_hash = Harl::djb2_hash(level.c_str());
	if (level.compare(commands_[string_hash]) == 0)
		(this->*(fp[string_hash]))();
}

void Harl::complain(char *level)
{
	if (level == nullptr)
		return ;
	else
		Harl::complain(std::string(level));
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

unsigned int Harl::djb2_hash(const char* str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % 1009;
}
