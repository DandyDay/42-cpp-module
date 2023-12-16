/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:08:35 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/16 15:00:36 by jinhchoi         ###   ########.fr       */
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

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type_ = other.type_;
	brain_ = new Brain(*other.brain_);
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type_ = other.type_;
		if (this->brain_)
			delete this->brain_;
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

void Dog::printBrain()
{
	this->brain_->printIdeas();
}

void Dog::setBrain(int idx, std::string idea)
{
	this->brain_->setIdeas(idx, idea);
}
