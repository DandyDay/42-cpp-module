/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:59:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/07/02 15:08:12 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact {
public:
	Contact();
private:
	std::string	first_name_;
	std::string	last_name_;
	std::string	nickname_;
};
