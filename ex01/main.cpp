/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:43:54 by coder             #+#    #+#             */
/*   Updated: 2022/02/16 15:04:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/PhoneBook.hpp"

int main( void )
{
	PhoneBook pb = PhoneBook();
	Contact *contacts = new Contact[8];
	std::string operation;
	
	presentation();
	std::getline (std::cin, operation);
	while (operation != "EXIT")
	{
		if (operation != "EXIT" && operation != "SEARCH" && operation != "ADD")
			std::cout << "Please, select one operation: ADD, SEARCH or EXIT..." << std::endl;
		else
		{
			if (operation == "ADD")
				addContact( pb, contacts );
			if (operation == "SEARCH")
				searchContact( pb );
			std::cout << std::endl;
			std::cout << "Select one operation: ADD, SEARCH or EXIT..." << std::endl;
		}
		std::getline (std::cin, operation);
	}
	delete[] contacts;
}
