/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:24:41 by anayef            #+#    #+#             */
/*   Updated: 2024/03/17 21:24:42 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

void Contact::setFirstName(const std::string& newFirstName){
	this->firstName = newFirstName;
}

void Contact::setLastName(const std::string& newLastName){
	this->lastName = newLastName;
}

void Contact::setNickName(const std::string& newNickName){
	this->nickName = newNickName;
}

void Contact::setPhoneNumber(const std::string& newPhoneNumber){
	this->phoneNumber = newPhoneNumber;
}

void Contact::setDarkestSecret(const std::string& newDarkestSecret){
	this->darkestSecret = newDarkestSecret;
}

std::string Contact::getFirstName() const{
	return(this->firstName);
}

std::string Contact::getLastName() const{
	return(this->lastName);
}

std::string Contact::getNickName() const{
	return(this->nickName);
}

std::string Contact::getPhoneNumber() const{
	return(this->phoneNumber);
}

std::string Contact::getDarkestSecret() const{
	return(this->darkestSecret);
}
