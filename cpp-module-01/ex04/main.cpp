/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:31:48 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/03 20:08:13 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char *argv[])
{
	Sed sed;	
	if (argc != 4)
		return EXIT_FAILURE;
	if (!sed.ReadFile(argv[1]))
		return EXIT_FAILURE;
	sed.WriteFile();
	return 0;
}