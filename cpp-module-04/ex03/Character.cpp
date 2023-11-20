/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:41:26 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/11/11 16:04:22 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		materia_[i] = NULL;
}

Character::Character(std::string name)
{
	name_ = name;
	for (int i = 0; i < 4; i++)
		materia_[i] = NULL;
}

Character::Character(const Character &other)
{
	name_ = other.name_;
	for (int i = 0; i < 4; i++)
	{
		if (other.materia_[i] != NULL)
			materia_[i] = other.materia_[i]->clone();
		else
			materia_[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materia_[i] != NULL)
				delete materia_[i];
			if (other.materia_[i] != NULL)
				materia_[i] = other.materia_[i]->clone();
		}
		name_ = other.name_;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i] != NULL)
		{
			delete materia_[i];
			materia_[i] = NULL;
		}
	}
}

std::string const &Character::getName() const
{
	return name_;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i] == NULL)
		{
			materia_[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	materia_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (materia_[idx] != NULL)
		materia_[idx]->use(target);
}
