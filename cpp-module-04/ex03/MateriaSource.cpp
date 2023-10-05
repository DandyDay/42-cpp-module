/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:28:41 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 18:57:42 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	// TODO: insert return statement here
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *m)
{
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i]->getType() == type)
			return (materia_[i]->clone());
	}
}
