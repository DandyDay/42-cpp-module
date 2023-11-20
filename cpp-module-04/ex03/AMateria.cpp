/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:02:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/11/11 15:39:55 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria()
{
	type_ = "materia";
}

AMateria::AMateria(std::string const &type)
{
	type_ = type;
}

AMateria::AMateria(const AMateria &other)
{
	type_ = other.type_;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type_ = other.type_;
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

void AMateria::use(ICharacter &target)
{
	std::cout << "* materia does something to " << target.getName() << " *"
	<< std::endl;
}
