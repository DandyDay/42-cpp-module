/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:02:23 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/01 12:03:46 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diaTrap("DT");

	diaTrap.whoAmI();
	diaTrap.attack("ENEMY");
	diaTrap.beRepaired(10);
	diaTrap.takeDamage(5);
	diaTrap.highFivesGuys();
	diaTrap.guardGate();

	return 0;
}
