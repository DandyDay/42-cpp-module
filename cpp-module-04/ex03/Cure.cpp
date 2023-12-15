/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:42:00 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 16:49:38 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

Cure::Cure()
{
	type_ = "cure";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		type_ = other.type_;
		isEquiped_ = false;
		source_ = other.source_;
	}
	return *this;
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
	Cure *cloneCure = new Cure(*this);
	return cloneCure;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
