/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:02:18 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 11:24:36 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	name_ = "NO_NAME";
	hit_points_ = 10;
	energy_points_ = 10;
	attack_damage_ = 0;
}

ClapTrap::ClapTrap(std::string name) : name_(name)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
	hit_points_ = 10;
	energy_points_ = 10;
	attack_damage_ = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name_ << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hit_points_ > 0 && energy_points_ > 0)
	{
		--energy_points_;
		std::cout << "ClapTrap " << name_ << " attacks " << target << " causing " <<
					 attack_damage_ << " points of damage! " <<
					 "(energy_point: " << energy_points_ << ")" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hit_points_)
		hit_points_ = 0;
	else
		hit_points_ -= amount;
	std::cout << "ClapTrap " << name_ << " takes " << amount << " points of damage! " <<
				hit_points_ << " remains. (energy_point: " << energy_points_ << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points_ > 0 && energy_points_ > 0)
	{
		--energy_points_;
		hit_points_ += amount;
	std::cout << "ClapTrap " << name_ << " is repaired " << amount << " points of damage! " <<
				hit_points_ << " remains. (energy_point: " << energy_points_ << ")" << std::endl;
	}
}
