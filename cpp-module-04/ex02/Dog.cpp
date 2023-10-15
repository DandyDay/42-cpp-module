/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:08:35 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 13:30:46 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type_ = "Dog";
	brain_ = new Brain();
}

Dog::Dog(const Dog &other)
{
	type_ = other.type_;
	brain_ = new Brain(*other.brain_);
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type_ = other.type_;
		brain_ = other.brain_;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain_;
}

void Dog::makeSound() const
{
	std::cout << "bow-wow.." << std::endl;
}