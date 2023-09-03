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

Sed::Sed()
{
	file_content_ = "";
}

Sed::~Sed()
{
	if (fin_.is_open())
		fin_.close();
}

bool Sed::ReadFile(std::string file_name)
{
	std::string temp;

	file_name_ = file_name;
	fin_ = std::ifstream(file_name);
	if (!fin_.is_open())
		return false;
	else
	{
		while (std::getline(fin_, temp))
			file_content_ += temp;
	}
	return true;
}

void Sed::ReplaceWords(std::string s1, std::string s2)
{
	if (s1.length() == 0)
		return ;
	if (s2.length() == 0)
		return ;
}

void Sed::WriteFile()
{
	std::cout << file_content_ << std::endl;
}
