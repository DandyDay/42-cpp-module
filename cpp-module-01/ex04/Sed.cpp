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
		{
			if (file_content_.length() != 0)
				file_content_ += "\n";
			file_content_ += temp;
		}
	}
	return true;
}

void Sed::ReplaceWords(std::string s1, std::string s2)
{
	std::size_t pos = 0;

	if (s1.length() == 0)
		return ;
	while ((pos = file_content_.find(s1, pos + s2.length())) != std::string::npos)
	{
		file_content_ = file_content_.substr(0, pos) + s2 + file_content_.substr(pos + s1.length());
	}
}

void Sed::WriteFile()
{
	std::ofstream fout(file_name_ + ".replace");

	if (fout.is_open())
	{
		fout << file_content_;
	}
	else
	{
		std::cout << "file open error" << std::endl;
		std::exit(1);
	}
}
