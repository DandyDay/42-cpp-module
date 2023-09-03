/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:31:48 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/03 19:31:18 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

std::string read_file(std::ifstream fin)
{
	std::string file_string;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return EXIT_FAILURE;
	std::ifstream fin(argv[1]);
	if (fin.is_open())
	{

	}
	else
	{
		std::cout << "file not found" << std::endl;
	}
}