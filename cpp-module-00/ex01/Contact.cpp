/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:59:18 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/03 19:41:41 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>

Contact::Contact()
{

}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	first_name_ = first_name;
	last_name_ = last_name;
	nickname_ = nickname;
	phone_number_ = phone_number;
	darkest_secret_ = darkest_secret;
}

std::string Contact::get_last_name()
{
	return (last_name_);
}

std::string Contact::get_first_name()
{
	return (first_name_);
}

std::string Contact::get_nickname()
{
	return (nickname_);
}

std::string Contact::get_phone_number()
{
	return (phone_number_);
}

std::string Contact::get_darkest_secret()
{
	return (darkest_secret_);
}

void	Contact::print_contact()
{
	std::cout << "first name:\t" << first_name_ << std::endl;
	std::cout << "last name:\t" << last_name_ << std::endl;
	std::cout << "nickname:\t" << nickname_ << std::endl;
	std::cout << "phone number:\t" << phone_number_ << std::endl;
	std::cout << "darkest secret:\t" << darkest_secret_ << std::endl;
}
