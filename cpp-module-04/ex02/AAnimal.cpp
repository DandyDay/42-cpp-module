/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:03:33 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/16 15:12:23 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor called" << std::endl;
	type_ = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	type_ = other.type_;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		type_ = other.type_;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return type_;
}
