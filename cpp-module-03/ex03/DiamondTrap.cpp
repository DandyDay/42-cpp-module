/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:08 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 12:15:21 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap()
{
	hit_points_ = FragTrap::kHitPoints;
	energy_points_ = ScavTrap::kEnergyPoints;
	attack_damage_ = FragTrap::kAttackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name), ScavTrap(name), FragTrap(name), name_(name)
{
	std::cout << "DiamondTrap " << ScavTrap::name_ << " constructor called"
			  << std::endl;
	ClapTrap::name_ = name + "_clap_name";
	hit_points_ = FragTrap::kHitPoints;
	energy_points_ = ScavTrap::kEnergyPoints;
	attack_damage_ = FragTrap::kAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
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

DiamondTrap::~DiamondTrap()
{
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << name_ << " and my ClapTrap name is "
			  << ClapTrap::name_ << std::endl;
}
