/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:38:42 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/01 21:27:52 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *zombies = zombieHorde(5, "jinhchoi");

	for (int i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}
