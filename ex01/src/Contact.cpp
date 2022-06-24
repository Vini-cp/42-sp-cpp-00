// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include <iostream>
#include "../include/Contact.h"

//------------------------------------------------------------------------------

Contact::Contact( void ) :
    mFirstName(""),
    mLastName(""),
    mNickname(""),
    mNumber(""),
    mSecret("")
{
}

//------------------------------------------------------------------------------

Contact::Contact( std::string pFirstName, std::string pLastName, std::string pNickname, std::string pNumber, std::string pSecret ) :
    mFirstName( pFirstName ),
    mLastName( pLastName ),
    mNickname( pNickname ),
    mNumber( pNumber ),
    mSecret( pSecret )
{
}

//------------------------------------------------------------------------------

Contact::Contact( const Contact &prContact )
{
    mFirstName = prContact.getFirstName();
    mLastName = prContact.getLastName();
    mNickname = prContact.getNickname();
    mNumber = prContact.getNumber();
    mSecret = prContact.getSecret();
}

//------------------------------------------------------------------------------

Contact::~Contact( void )
{
}

//------------------------------------------------------------------------------

Contact& Contact::operator=( const Contact &prContact )
{
    if ( this == &prContact ) return *this;

    mFirstName = prContact.getFirstName();
    mLastName = prContact.getLastName();
    mNickname = prContact.getNickname();
    mNumber = prContact.getNumber();
    mSecret = prContact.getSecret();

    return *this;
}

//------------------------------------------------------------------------------

void Contact::setFirstName( std::string pName )
{
    mFirstName = pName;
}

//------------------------------------------------------------------------------

std::string Contact::getFirstName( void ) const
{
    return mFirstName;
}

//------------------------------------------------------------------------------


void Contact::setLastName( std::string pName )
{
    mLastName = pName;
}

//------------------------------------------------------------------------------

std::string Contact::getLastName( void ) const
{
    return mLastName;
}

//------------------------------------------------------------------------------


void Contact::setNickname( std::string pName )
{
    mNickname = pName;
}

//------------------------------------------------------------------------------

std::string Contact::getNickname( void ) const
{
    return mNickname;
}

//------------------------------------------------------------------------------


void Contact::setNumber( std::string pNumber )
{
    mNumber = pNumber;
}

//------------------------------------------------------------------------------

std::string Contact::getNumber( void ) const
{
    return mNumber;
}

//------------------------------------------------------------------------------


void Contact::setSecret( std::string pSecret )
{
    mSecret = pSecret;
}

//------------------------------------------------------------------------------

std::string Contact::getSecret( void ) const
{
    return mSecret;
}

//------------------------------------------------------------------------------
