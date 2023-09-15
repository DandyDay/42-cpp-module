/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:39:24 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/15 15:56:04 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

#include <iostream>
#include <cstdlib>

Sed::Sed()
{
	file_content_ = "";
}

Sed::~Sed()
{
}

bool Sed::ReadFile(std::string file_name)
{
	std::string temp;

	file_name_ = file_name;
	std::ifstream fin(file_name_.c_str());
	if (!fin.is_open())
		return false;
	else
	{
		while (std::getline(fin, temp))
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
	while ((pos = file_content_.find(s1, pos)) != std::string::npos)
	{
		file_content_ = file_content_.substr(0, pos) + s2 + file_content_.substr(pos + s1.length());
		pos += + s2.length();
	}
}

void Sed::WriteFile()
{
	std::ofstream fout((file_name_ + ".replace").c_str());

	if (fout.is_open())
	{
		fout << file_content_;
	}
	else
	{
		std::cout << "file open error" << std::endl;
		exit(1);
	}
}
