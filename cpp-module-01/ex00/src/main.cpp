/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:28:46 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/08/31 18:32:58 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main(void)
{
	Zombie *zombie = newZombie("newZombie");

	randomChump("randomChump");
	zombie->announce();
	delete zombie;
	return 0;
}
