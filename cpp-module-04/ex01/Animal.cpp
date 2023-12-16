/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:03:33 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/16 15:12:23 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	type_ = "Animal";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type_ = other.type_;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type_ = other.type_;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return type_;
}

void Animal::makeSound() const
{
	std::cout << "Ani,, Ani,," << std::endl;
}

void Animal::printBrain()
{
	std::cout << "Animal Class doesn't have brain" << std::endl;
}

void Animal::setBrain(int idx, std::string idea)
{
	std::cout << "Animal Class doesn't have brain" << std::endl;
	std::cout << "Can't set idea[" << idx << "] to '" << idea << "'"
			  << std::endl;
}
