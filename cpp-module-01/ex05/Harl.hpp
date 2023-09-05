/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:45:51 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/04 13:32:06 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
public:
	Harl(/* args */);
	~Harl();
	void complain(std::string level);
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	void (Harl::*fp[4])();
};

#endif
