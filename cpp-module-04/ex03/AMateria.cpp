/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:02:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 14:35:18 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const &type)
{
	type_ = type;
}

AMateria::AMateria(const AMateria &other)
{
	type_ = other.type_;
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
}
