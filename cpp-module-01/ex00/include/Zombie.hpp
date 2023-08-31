/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:46:18 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/08/31 18:27:02 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce( void );
private:
	std::string name_;
};
