/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:02:23 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 00:29:38 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("ST");

	scavTrap.attack("ENEMY");
	scavTrap.beRepaired(10);
	scavTrap.takeDamage(5);
	scavTrap.guardGate();

	ClapTrap clapTrap("CT");

	clapTrap.attack("ENEMY");
	clapTrap.beRepaired(10);
	clapTrap.takeDamage(5);
	// clapTrap.guardGate();

	return 0;
}
