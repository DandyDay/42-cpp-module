/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:15:02 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/09 18:49:51 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

const unsigned int ScavTrap::kHitPoints = 100;
const unsigned int ScavTrap::kEnergyPoints = 50;
const unsigned int ScavTrap::kAttackDamage = 20;

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hit_points_ = kHitPoints;
	energy_points_ = kEnergyPoints;
	attack_damage_ = kAttackDamage;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name_ << " constructor called" << std::endl;
	hit_points_ = kHitPoints;
	energy_points_ = kEnergyPoints;
	attack_damage_ = kAttackDamage;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name_)
{
	std::cout << "ScavTrap " << name_ << " constructor called" << std::endl;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name_ = other.name_;
		hit_points_ = other.hit_points_;
		energy_points_ = other.energy_points_;
		attack_damage_ = other.attack_damage_;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name_ << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hit_points_ > 0 && energy_points_ > 0)
	{
		--energy_points_;
		std::cout << "ScavTrap " << name_ << " attacks " << target
				  << " causing " << attack_damage_ << " points of damage!"
				  << "(energy_point: " << energy_points_ << ")" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode."
			  << std::endl;
}
