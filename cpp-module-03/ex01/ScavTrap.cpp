/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:15:02 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 00:29:53 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name_ << " constructor called" << std::endl;
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name_ << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_points_ > 0 && energy_points_ > 0)
	{
		--energy_points_;
		std::cout << "ScavTrap " << name_ << " attacks " << target << " causing " <<
					 attack_damage_ << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode." << std::endl;
}
