/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:20:06 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/09/03 19:20:23 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	void		add_contact();
	void		search_contact();

private:
	Contact contacts_[8];
	std::string get_fitted_string(std::string original);
	bool check_stdin_err();
	bool check_string_input(std::string str);
	bool check_numeric_input(std::string str);

	int idx_;
	int count_;
};

#endif