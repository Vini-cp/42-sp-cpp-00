/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:43:54 by coder             #+#    #+#             */
/*   Updated: 2022/06/06 01:48:05 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "./include/PhoneBook.h"

static void presentation( void )
{
	std::cout << "Welcome!" << std::endl;
	std::cout << "Select one operation: ADD, SEARCH or EXIT..." << std::endl;
	std::cout << "ADD: to save a new contact." << std::endl;
	std::cout << "SEARCH: to display the saved contacts." << std::endl;
	std::cout << "EXIT: to quit." << std::endl;
	std::cout << ">> ";
}

static void newInput( void )
{
	std::cout << "Please, select one operation: ADD, SEARCH or EXIT..." << std::endl;
	std::cout << ">> ";
}

static void add( PhoneBook& prPhoneBook )
{
	Contact lContact;
	
	std::string lInput;
	std::cout << "First Name: ";
	std::getline( std::cin, lInput );
	lContact.setFirstName( lInput );

	std::cout << "Last Name: ";
	std::getline( std::cin, lInput );
	lContact.setLastName( lInput );

	std::cout << "Nickname: ";
	std::getline( std::cin, lInput );
	lContact.setNickname( lInput );

	std::cout << "Number: ";
	std::getline( std::cin, lInput );
	lContact.setNumber( lInput );

	std::cout << "Darkest Secret: ";
	std::getline( std::cin, lInput );
	lContact.setSecret( lInput );

	prPhoneBook.setNewContact( lContact );
	newInput();
}

static int string2Int( std::string pStr )
{
	size_t lStrLength = pStr.length();

	if ( lStrLength == 0 || lStrLength > 1 ) return -1;

	if ( !std::isdigit( pStr[0] ) ) return -1;
	
	return ( pStr[0] - '0' );
}

static void search( PhoneBook pPhoneBook )
{
	int lNumberOfContacts = pPhoneBook.getNumberOfContacts();
	
	if ( !lNumberOfContacts )
	{
		std::cout << "There are no contacts to display!" << std::endl;
		newInput();
		return ;
	}

	pPhoneBook.searchContact();

	std::string lInput;
	std::cout << "Contact index: ";
	std::getline( std::cin, lInput );

	int lIndex = string2Int( lInput );
	
	if ( lIndex >= 0 && lIndex < lNumberOfContacts )
		pPhoneBook.displayContactInformation( lIndex );
	else
		std::cout << "Index out of range!" << std::endl;

	newInput();
}

int main( void )
{
	PhoneBook pb = PhoneBook();
	std::string operation;
	
	presentation();
	while ( !std::cin.eof() )
	{
		std::getline( std::cin, operation );
		if ( operation == "ADD" )
			add( pb );
		else if ( operation == "SEARCH" )
			search( pb );
		else if ( operation == "" )
			std::cout << ">> ";
		else if ( operation == "EXIT" )
			break ;
		else
			newInput();
	}
	return 0;
}
