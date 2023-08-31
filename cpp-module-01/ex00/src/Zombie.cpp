/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:57:30 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/08/31 18:28:31 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name) : name_(name)
{

}

Zombie::~Zombie()
{
	std::cout << name_ << " Destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
