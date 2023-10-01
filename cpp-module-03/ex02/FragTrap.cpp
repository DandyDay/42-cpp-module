/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:15:02 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 11:08:02 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name_ << " constructor called" << std::endl;
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name_)
{
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
	std::cout << "FragTrap " << name_ << " requests for a HighFive" << std::endl;
}

