// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "../include/PhoneBook.h"

//------------------------------------------------------------------------------

PhoneBook::PhoneBook( void ) :
	mActiveContacts( 0 )
{
}

//------------------------------------------------------------------------------

PhoneBook::~PhoneBook( void )
{
}

//------------------------------------------------------------------------------

void PhoneBook::setNewContact( const Contact &prContact )
{
	if (mActiveContacts == mMaximumContacts)
		mContacts[ mActiveContacts - 1 ] = prContact;
	else
	{
		mContacts[ mActiveContacts ] = prContact;
		mActiveContacts++;
	}
}

//------------------------------------------------------------------------------

int PhoneBook::getNumberOfContacts( void ) const
{
	return mActiveContacts;
}

//------------------------------------------------------------------------------

std::string* PhoneBook::getContactsFirstName( void ) const
{
	std::string* lNames = new std::string[ mActiveContacts ];
	for (int i = 0; i < mActiveContacts; i++)
		lNames[ i ] = mContacts[ i ].getFirstName();
	return lNames;
}

//------------------------------------------------------------------------------

std::string* PhoneBook::getContactsLasttName( void ) const
{
	std::string* lNames = new std::string[ mActiveContacts ];
	for (int i = 0; i < mActiveContacts; i++)
		lNames[ i ] = mContacts[ i ].getLastName();
	return lNames;
}

//------------------------------------------------------------------------------

std::string* PhoneBook::getContactsNickname( void ) const
{
	std::string* lNicknames = new std::string[ mActiveContacts ];
	for (int i = 0; i < mActiveContacts; i++)
		lNicknames[ i ] = mContacts[ i ].getNickname();
	return lNicknames;
}

//------------------------------------------------------------------------------

std::string* PhoneBook::getContactsNumber( void ) const
{
	std::string* lNumbers = new std::string[ mActiveContacts ];
	for (int i = 0; i < mActiveContacts; i++)
		lNumbers[ i ] = mContacts[ i ].getNumber();
	return lNumbers;
}

//------------------------------------------------------------------------------

std::string* PhoneBook::getContactsSecret( void ) const
{
	std::string* lSecrets = new std::string[ mActiveContacts ];
	for (int i = 0; i < mActiveContacts; i++)
		lSecrets[ i ] = mContacts[ i ].getSecret();
	return lSecrets;
}

//------------------------------------------------------------------------------

void PhoneBook::displayContactInformation( int pIndex ) const
{
	std::cout << "First name: " << mContacts[ pIndex ].getFirstName() << std::endl;
	std::cout << "Last name : " << mContacts[ pIndex ].getLastName() << std::endl;
	std::cout << "Nick name : " << mContacts[ pIndex ].getNickname() << std::endl;
	std::cout << "Number    : " << mContacts[ pIndex ].getNumber() << std::endl;
	std::cout << "Secret    : " << mContacts[ pIndex ].getSecret() << std::endl;
}

//------------------------------------------------------------------------------

void PhoneBook::searchContact( void ) const
{
	displayHeaderInfo();
	displayContatsInfo();
}

//------------------------------------------------------------------------------

void PhoneBook::displayHeaderInfo( void ) const
{
	std::cout << std::right << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "First Name" << " | ";
	std::cout << std::right << std::setw(10) << "Last Name" << " | ";
	std::cout << std::right << std::setw(10) << "Nickame" << std::endl;
}

//------------------------------------------------------------------------------

std::string PhoneBook::formatName(std::string pName) const
{
	if (pName.length() > 10)
		return (pName.substr(0, 9) + '.');
	else
		return (pName);
}

//------------------------------------------------------------------------------

void PhoneBook::displayContatsInfo( void ) const
{
	for (int i = 0; i < mActiveContacts; i++)
	{
		std::cout << std::right << std::setw(10) << i;
		std::cout << " | ";
		std::cout << std::right << std::setw(10) << formatName( mContacts[ i ].getFirstName() );
		std::cout << " | ";
		std::cout << std::right << std::setw(10) << formatName( mContacts[ i ].getLastName() );
		std::cout << " | ";
		std::cout << std::right << std::setw(10) << formatName( mContacts[ i ].getNickname() );; 
		std::cout << std::endl;
	}
}

//------------------------------------------------------------------------------
