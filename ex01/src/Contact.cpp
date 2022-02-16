/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:49:38 by coder             #+#    #+#             */
/*   Updated: 2022/02/16 15:06:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact( void ) : _name(""), _number("")
{
	// std::cout << "Void constructor of Contact called" << std::endl;
	return ;
}

Contact::Contact( std::string name, std::string number )
	: _name(name), _number(number)
{
	// std::cout << "Constructor of Contact called" << std::endl;
	return ;
}

Contact::~Contact( void )
{
	// std::cout << "Destructor of Contact " <<  this->_name << " " << this->_number << " called" << std::endl;
	return ;
}

void	Contact::setContact( std::string name, std::string number, std::string nickname )
{
	_name = name;
	_nickname = nickname;
	_number = number;
}

std::string	Contact::getContactName( void )
{
	return (_name);
}

std::string	Contact::getContactNickname( void )
{
	return (_nickname);
}

std::string	Contact::getContactNumber( void )
{
	return (_number);
}
