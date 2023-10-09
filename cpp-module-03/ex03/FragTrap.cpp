/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:15:02 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/09 18:50:23 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

const unsigned int FragTrap::kHitPoints = 100;
const unsigned int FragTrap::kEnergyPoints = 100;
const unsigned int FragTrap::kAttackDamage = 30;

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	hit_points_ = kHitPoints;
	energy_points_ = kEnergyPoints;
	attack_damage_ = kAttackDamage;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name_ << " constructor called" << std::endl;
	hit_points_ = kHitPoints;
	energy_points_ = kEnergyPoints;
	attack_damage_ = kAttackDamage;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name_)
{
	std::cout << "FragTrap " << name_ << " constructor called" << std::endl;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name_ << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name_ << " requests for a HighFive"
			  << std::endl;
}
