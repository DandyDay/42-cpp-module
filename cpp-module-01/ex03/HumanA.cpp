/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:51:19 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/15 04:02:42 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

Weapon HumanA::defaultWeapon = Weapon();

HumanA::HumanA() : weapon_(HumanA::defaultWeapon)
{

}

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_(weapon), name_(name)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
