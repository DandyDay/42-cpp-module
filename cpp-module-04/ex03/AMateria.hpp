/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:52:07 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/15 22:10:10 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class ICharacter;
class MateriaSource;

class AMateria
{
protected:
	std::string type_;
	MateriaSource *source_;
	bool isEquiped_;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const &getType() const;
	MateriaSource *getSource();
	void setSource(MateriaSource *matSrc);
	bool getIsEquiped();
	void setIsEquiped(bool isEquiped);

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
