#include "Sed.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:39:24 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/03 19:39:25 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

#include <iostream>

void Sed::OpenFile(std::string file_name)
{
	fin_ = std::ifstream(file_name);
	if (fin_.is_open())
	{

	}
	else
	{
		std::cout << "file not found" << std::endl;
	}
}
