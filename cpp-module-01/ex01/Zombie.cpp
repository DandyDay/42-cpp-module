/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:57:30 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/01 21:47:48 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default Constructor called" << std::endl;
}

Zombie::Zombie(std::string name) : name_(name)
{
	std::cout << name << " Constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name_ << " Destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	name_ = name;
}
