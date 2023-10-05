/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:05:50 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/10/05 13:33:43 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	Brain &operator=(const Brain &other);
	~Brain();
private:
	std::string ideas_[100];
};

#endif
