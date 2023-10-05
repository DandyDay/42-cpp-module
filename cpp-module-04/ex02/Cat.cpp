/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:08:35 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 13:30:24 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type_ = "Cat";
	brain_ = new Brain();
}

Cat::Cat(const Cat &other)
{
	type_ = other.type_;
	brain_ = new Brain(*other.brain_);
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type_ = other.type_;
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
