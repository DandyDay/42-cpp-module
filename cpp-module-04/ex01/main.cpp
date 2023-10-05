/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:02:23 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 13:45:40 by jinhchoi         ###   ########.fr       */
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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// const Animal* k = new Animal();

	// delete k;
	delete j;//should not create a leak
	delete i;

	// atexit(leakCheck);
	return 0;
}

