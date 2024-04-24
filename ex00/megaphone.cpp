/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:59:05 by anayef            #+#    #+#             */
/*   Updated: 2024/03/24 20:14:47 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string toUpper(const std::string& str) {
	std::string result;
	result = str;
	for (size_t i = 0; i < str.length(); i++) {
		if(std::isalpha(result[i])) {
			result[i] = std::toupper(str[i]);
		}
	}
	return (result);
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			std::string str;
			str = toUpper(argv[i]);
			std::cout << toUpper(str);
			if(i == argc - 1){
				std::cout << std::endl;
			}
		}
	}
	return (0);
}
