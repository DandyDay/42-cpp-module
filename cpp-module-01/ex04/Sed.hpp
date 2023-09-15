/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:37:38 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/15 03:50:23 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <fstream>

class Sed
{
public:
	Sed();
	~Sed();
	bool ReadFile(std::string file_name);
	void ReplaceWords(std::string s1, std::string s2);
	void WriteFile();
private:
	std::string file_name_;
	std::string file_content_;
};

#endif
