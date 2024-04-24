/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:24:54 by anayef            #+#    #+#             */
/*   Updated: 2024/03/17 21:24:55 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
int main() {
	PhoneBook myPhoneBook;

	std::cout << "|=====================================|" << std::endl;
	std::cout << "|      WELCOME TO THE PHONE BOOK      |" << std::endl;
	std::cout << "|=====================================|" << std::endl;
	std::cout << "| PLEASE SELECT ONE OF THE FOLLOWINGS |" << std::endl;
	std::cout << "|               1.ADD                 |" << std::endl;
	std::cout << "|               2.SEARCH              |" << std::endl;
	std::cout << "|               3.EXIT                |" << std::endl;
	std::cout << "|=====================================|" << std::endl;
	std::string option; 
	std::cout << "ENTER YOUR OPTION :" << std::endl;
	while(true){
		std::cout << ">" ;
		std::getline(std::cin, option);
		if (option == "ADD"){
			myPhoneBook.addContact();
		}
		else if(option == "SEARCH"){
			myPhoneBook.displayContact();
		}
		else if (option == "EXIT"){
			return(1);
		}
	}
	return(0);
}


