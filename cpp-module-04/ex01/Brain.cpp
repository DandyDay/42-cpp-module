/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:03 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/16 14:53:02 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas_[i] = other.ideas_[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas_[i] = other.ideas_[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::printIdeas()
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas_[i].length() != 0)
			std::cout << "idea " << i << ": " << ideas_[i] << std::endl;
	}
}

void Brain::setIdeas(int idx, std::string idea)
{
	if (0 <= idx && idx < 100)
		ideas_[idx] = idea;
}
