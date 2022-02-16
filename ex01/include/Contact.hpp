/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:45:07 by coder             #+#    #+#             */
/*   Updated: 2022/02/16 15:06:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include "Contact.hpp"

class Contact
{
	private:

		std::string		_name;
		std::string		_nickname;
		std::string		_number;

	public:

		Contact( void );
		Contact( std::string name, std::string number );
		~Contact( void );

		void		setContact( std::string name, std::string number, std::string nickname );
		std::string	getContactName( void );
		std::string	getContactNickname( void );
		std::string	getContactNumber( void );
};

#endif
