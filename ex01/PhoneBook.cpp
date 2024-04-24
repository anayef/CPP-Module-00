/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:24:59 by anayef            #+#    #+#             */
/*   Updated: 2024/04/24 21:03:18 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <limits>
#include <string>

PhoneBook::PhoneBook() {}

void PhoneBook::addContact() {
	static int i = 0;
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	firstName = getInput("FIRST NAME");
	this->contacts[i].setFirstName(firstName);

	lastName = getInput("LAST NAME");
	this->contacts[i].setLastName(lastName);

	nickName = getInput("NICK NAME");
	this->contacts[i].setNickName(nickName);

	bool validPhoneNumber = false;
	while (!validPhoneNumber) {
		std::cout << "ENTER PHONE NUMBER (digits only): ";
		std::getline(std::cin, phoneNumber);

		validPhoneNumber = true;
		for (size_t i = 0; i < phoneNumber.length(); ++i) {
			if (!isdigit(phoneNumber[i])) {
				validPhoneNumber = false;
				break;
			}
		}

		if (!validPhoneNumber) {
			std::cout << "Invalid phone number. Please enter digits only." << std::endl;
		}
	}

	this->contacts[i].setPhoneNumber(phoneNumber);

	darkestSecret = getInput("DARKEST SECRET");
	this->contacts[i].setDarkestSecret(darkestSecret);

	i = (i + 1) % maxContacts;
}

void PhoneBook::displayContact() {
	bool foundContact = false; 

	for (int i = 0; i < maxContacts; ++i) {
		if (!contacts[i].getFirstName().empty()) {
			foundContact = true;
			break;
		}
	}

	if (!foundContact) {
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "INDEX" << " | " << std::setw(10) << "FIRST NAME" << " | "
		<< std::setw(10) << "LAST NAME" << " | " << std::setw(10) << "NICK NAME" << std::endl;

	for (int i = 0; i < maxContacts; ++i) {
		if (!contacts[i].getFirstName().empty()) {
			std::cout << std::setw(10) << i+1 << " | "
				<< std::setw(10) << truncateText(contacts[i].getFirstName(), 10) << " | "
				<< std::setw(10) << truncateText(contacts[i].getLastName(), 10) << " | "
				<< std::setw(10) << truncateText(contacts[i].getNickName(), 10) << std::endl;
		}
	}

	int index;
	std::cout << "ENTER CONTACT INDEX TO DISPLAY INFORMATION: ";
	while (!(std::cin >> index) || std::cin.peek() != '\n'){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a valid index: ";
	}
	std::cin.ignore();
	index--;
	if (index >= 0 && index < maxContacts && !contacts[index].getFirstName().empty()) {
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "CONTACT " << index + 1 << ":" << std::endl;
		std::cout << "FIRST NAME     : " << contacts[index].getFirstName() << std::endl;
		std::cout << "LAST NAME      : " << contacts[index].getLastName() << std::endl;
		std::cout << "NICK NAME      : " << contacts[index].getNickName() << std::endl;
		std::cout << "PHONE NUMBER   : " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "DARKEST SECRET : " << contacts[index].getDarkestSecret() << std::endl;
		std::cout << "---------------------------------------" << std::endl;
	}
	else {
		std::cout << "Invalid contact index." << std::endl;
	}
}

std::string PhoneBook::truncateText(const std::string& text, std::string::size_type width){
	if (text.length() > width) {
		return text.substr(0, width - 1) + ".";
	}
	else {
		return (text);
	}
}

bool PhoneBook::isEmpty(const std::string& str){
	return(str.empty());
}

std::string PhoneBook::getInput(const std::string& fieldName){
	std::string input;
	while (true) {
		std::cout << "ENTER " << fieldName << ": ";
		std::getline(std::cin, input);
		if (!isEmpty(input)) {
			return (input);
		}
		std::cout << "Invalid input. " << fieldName << " cannot be empty." << std::endl;
	}
}

