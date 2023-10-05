/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:42:00 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 17:20:08 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

Ice::Ice()
{
	type_ = "ice";
}

Ice::Ice(const Ice &other)
{
	type_ = other.type_;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		type_ = other.type_;
	}
	return *this;
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	Ice *cloneIce = new Ice(*this);
	return cloneIce;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
