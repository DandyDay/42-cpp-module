/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:52:31 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/15 03:57:11 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon()
{
	type_ = "";
}

Weapon::~Weapon()
{

}

Weapon::Weapon(std::string type) : type_(type)
{

}

const std::string &Weapon::getType()
{
	return type_;
}

void Weapon::setType(std::string type)
{
	type_ = type;
}
