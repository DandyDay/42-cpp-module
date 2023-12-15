/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:02:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/15 21:41:43 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria()
{
	type_ = "materia";
	isEquiped_ = false;
}

AMateria::AMateria(std::string const &type)
{
	type_ = type;
	isEquiped_ = false;
}

AMateria::AMateria(const AMateria &other)
{
	type_ = other.type_;
	isEquiped_ = other.isEquiped_;
	source_ = other.source_;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type_ = other.type_;
		isEquiped_ = other.isEquiped_;
		source_ = other.source_;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return type_;
}

MateriaSource *AMateria::getSource()
{
	return this->source_;
}

void AMateria::setSource(MateriaSource *matSrc)
{
	this->source_ = matSrc;
}

bool AMateria::getIsEquiped()
{
	return isEquiped_;
}

void AMateria::setIsEquiped(bool isEquiped)
{
	isEquiped_ = isEquiped;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* materia does something to " << target.getName() << " *"
			  << std::endl;
}
