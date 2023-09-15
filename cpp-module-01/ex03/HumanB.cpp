/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:51:19 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/03 17:29:15 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name)
{
	weapon_ = NULL;
}

HumanB::HumanB()
{

}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	if (weapon_ == NULL)
		std::cout << name_ << " attacks with their hand" << std::endl;
	else
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	weapon_ = &weapon;
}
