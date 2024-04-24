/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:25:02 by anayef            #+#    #+#             */
/*   Updated: 2024/04/24 19:40:57 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
	static const int maxContacts = 8;
	Contact contacts[maxContacts];

public:
	PhoneBook();
	void addContact();
	void displayContact();
	std::string truncateText(const std::string& text, std::string::size_type width);
	bool isEmpty(const std::string& str);
	std::string getInput(const std::string& feildName);
};

#endif
