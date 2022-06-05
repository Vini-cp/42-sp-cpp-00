// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#pragma once

#include "Contact.h"

class PhoneBook
{
public:

	PhoneBook( void );
	~PhoneBook( void );

	void setNewContact( const Contact &prContact );

	int getNumberOfContacts( void ) const;

	std::string* getContactsFirstName( void ) const;
	std::string* getContactsLasttName( void ) const;
	std::string* getContactsNickname( void ) const;
	std::string* getContactsNumber( void ) const;
	std::string* getContactsSecret( void ) const;

	void displayContactInformation( int pIndex ) const;
	void searchContact( void ) const;

private:

	int mActiveContacts;
	static int const mMaximumContacts = 8;
	Contact mContacts[8];

	void displayHeaderInfo( void ) const;
	void displayContatsInfo( void ) const;
	std::string formatName(std::string pName) const;
};
