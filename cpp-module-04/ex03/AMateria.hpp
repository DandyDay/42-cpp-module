/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:52:07 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 14:35:21 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type_;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
