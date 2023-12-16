/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:08:35 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/16 15:00:13 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat()
{
	type_ = "Cat";
	brain_ = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type_ = other.type_;
	brain_ = new Brain(*other.brain_);
}

Cat &Cat::operator=(const Cat &other)
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

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain_;
}

void Cat::makeSound() const
{
	std::cout << "meow.." << std::endl;
}

void Cat::printBrain()
{
	this->brain_->printIdeas();
}

void Cat::setBrain(int idx, std::string idea)
{
	this->brain_->setIdeas(idx, idea);
}
