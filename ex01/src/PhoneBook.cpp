/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:46:46 by coder             #+#    #+#             */
/*   Updated: 2022/02/16 01:05:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _noContacts(0)
{
	// std::cout << "Void constructor of PhoneBook called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook( void )
{
	// std::cout << "Destructor of PhoneBook called" << std::endl;
	return ;
}

void	PhoneBook::setNewContact( Contact &contact )
{
	if (_noContacts == 8)
		_contact[7] = contact;
	else
	{
		_contact[_noContacts] = contact;
		_noContacts++;
	}
}

int		PhoneBook::getNoContacts( void )
{
	return (_noContacts);
}

std::string*	PhoneBook::getContactsName( void )
{
	std::string *names = new std::string[_noContacts];
	for (int i = 0; i < _noContacts; i++)
		names[i] = _contact[i].getContactName();
	return (names);
}

std::string*	PhoneBook::getContactsNickname( void )
{
	std::string *nicknames = new std::string[_noContacts];
	for (int i = 0; i < _noContacts; i++)
		nicknames[i] = _contact[i].getContactNickname();
	return (nicknames);
}

std::string*	PhoneBook::getContactsNumber( void )
{
	std::string *numbers = new std::string[_noContacts];
	for (int i = 0; i < _noContacts; i++)
		numbers[i] = _contact[i].getContactNumber();
	return (numbers);
}
