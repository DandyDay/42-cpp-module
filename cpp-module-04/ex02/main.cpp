/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:02:23 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/11/06 17:37:16 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

// void leakCheck()
// {
// 	system("leaks animals");
// }

int main()
{
	AAnimal*	animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	// atexit(leakCheck);
	return 0;
}

