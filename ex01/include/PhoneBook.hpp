/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:43:21 by coder             #+#    #+#             */
/*   Updated: 2022/02/16 00:35:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
	private:

		Contact			_contact[8];
		int				_noContacts;

	public:

		PhoneBook( void );
		~PhoneBook( void );

		void			setNewContact( Contact &contact );
		int				getNoContacts( void );
		std::string		*getContactsName( void );
		std::string		*getContactsNickname( void );
		std::string		*getContactsNumber( void );

};

void	presentation( void );
void	searchContact( PhoneBook &pb );
void	addContact( PhoneBook &pb, Contact *contacts );

#endif
