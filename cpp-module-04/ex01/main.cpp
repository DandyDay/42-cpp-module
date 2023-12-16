/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:02:23 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/12/16 15:23:10 by jinhchoi         ###   ########.fr       */
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
	Animal *animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << std::endl;

	animals[0]->setBrain(0, "first idea");
	animals[0]->setBrain(1, "second idea");
	animals[0]->setBrain(2, "third idea");

	animals[0]->printBrain();
	std::cout << std::endl;

	Animal *copyAnimal = new Dog(*(Dog *)animals[0]);
	copyAnimal->setBrain(1, "new second idea");

	std::cout << std::endl;
	std::cout << "animals[0]'s idea" << std::endl;
	animals[0]->printBrain();
	std::cout << std::endl;
	std::cout << "copyAnimal's idea" << std::endl;
	copyAnimal->printBrain();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];
	delete copyAnimal;
	// atexit(leakCheck);
	return 0;
}
