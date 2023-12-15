/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:28:41 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/15 22:05:53 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materia_[i] = NULL;
	maxMateria = 10;
	myMateriasLen = 0;
	myMaterias = new AMateria *[maxMateria];
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materia_[i] != NULL)
			materia_[i] = other.materia_[i]->clone();
		else
			materia_[i] = NULL;
	}
	maxMateria = 10;
	myMateriasLen = 0;
	myMaterias = new AMateria *[maxMateria];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materia_[i] != NULL)
				delete materia_[i];
			if (other.materia_[i] != NULL)
				materia_[i] = other.materia_[i]->clone();
			else
				materia_[i] = NULL;
		}
		maxMateria = 10;
		myMateriasLen = 0;
		myMaterias = new AMateria *[maxMateria];
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i] != NULL)
			delete materia_[i];
		materia_[i] = NULL;
	}
	for (int i = 0; i < myMateriasLen; i++)
	{
		if (myMaterias[i]->getIsEquiped() == false)
			delete myMaterias[i];
	}
	delete[] myMaterias;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i] == NULL)
		{
			materia_[i] = m->clone();
			break;
		}
	}
}

void MateriaSource::addToMyMateria(AMateria *m)
{
	if (myMateriasLen == maxMateria)
	{
		AMateria **tempMaterias = new AMateria *[maxMateria + 10];
		for (int i = 0; i < maxMateria; i++)
		{
			tempMaterias[i] = myMaterias[i];
		}
		maxMateria += 10;
		delete[] myMaterias;
		myMaterias = tempMaterias;
	}
	myMaterias[myMateriasLen++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i] != NULL && materia_[i]->getType() == type)
		{
			AMateria *materia = materia_[i]->clone();
			materia->setSource(this);
			return (materia);
		}
	}
	return NULL;
}
