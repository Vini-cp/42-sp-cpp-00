// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Client.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

//------------------------------------------------------------------------------

Client::Client( void )
{
    presentation();
}

//------------------------------------------------------------------------------

Client::~Client( void )
{
}

//------------------------------------------------------------------------------

void Client::presentation( void ) const
{
    std::cout << "Welcome!" << std::endl;
    std::cout << "Select one operation: ADD, SEARCH or EXIT..." << std::endl;
    std::cout << "ADD: to save a new contact." << std::endl;
    std::cout << "SEARCH: to display the saved contacts." << std::endl;
    std::cout << "EXIT: to quit." << std::endl;
    std::cout << ">> ";
}

//------------------------------------------------------------------------------

void Client::newInput( void ) const
{
    std::cout << "Please, select one operation: ADD, SEARCH or EXIT..." << std::endl;
    std::cout << ">> ";
}

//------------------------------------------------------------------------------

int Client::newOperation( std::string pOperation )
{
    if ( pOperation == "ADD" )
    {
        add();
    }
    else if ( pOperation == "SEARCH" )
    {
        search();
    }
    else if ( pOperation == "" )
    {
        std::cout << ">> ";
    }
    else if ( pOperation == "EXIT" )
    {
        return 1;
    }
    else
    {
        newInput();
    }

    return 0;
}

//------------------------------------------------------------------------------

std::string Client::getContactInformation( std::string pInfoToAsk )
{
    std::string lInput;

    std::cout << pInfoToAsk << ": ";

    std::getline( std::cin, lInput );

    while ( lInput == "" )
    {
        std::cout << ">> ~ Contact infromation must not be empty ! ~" << std::endl;
        std::cout << ">> ";
        std::getline( std::cin, lInput );
    }

    return lInput;
}

//------------------------------------------------------------------------------

int Client::string2Int( std::string pStr ) const
{
    size_t lStrLength = pStr.length();

    if ( lStrLength == 0 || lStrLength > 1 ) return -1;

    if ( !std::isdigit( pStr[0] ) ) return -1;
    
    return ( pStr[0] - '0' );
}

//------------------------------------------------------------------------------

void Client::add( void )
{
    Contact lContact;
    
    lContact.setFirstName( getContactInformation( "First Name" ) );
    lContact.setLastName( getContactInformation( "Last Name" ) );
    lContact.setNickname( getContactInformation( "Nickname" ) );
    lContact.setNumber( getContactInformation( "Number" ) );
    lContact.setSecret( getContactInformation( "Darkest Secret" ) );

    mPhoneBook.setNewContact( lContact );
    newInput();
}

//------------------------------------------------------------------------------

void Client::search( void ) const
{
    int lNumberOfContacts = mPhoneBook.getNumberOfContacts();
    
    if ( !lNumberOfContacts )
    {
        std::cout << "There are no contacts to display!" << std::endl;
        newInput();
        return ;
    }

    mPhoneBook.searchContact();

    std::string lInput;
    std::cout << "Contact index: ";
    std::getline( std::cin, lInput );

    int lIndex = string2Int( lInput );
    
    if ( lIndex >= 0 && lIndex < lNumberOfContacts )
    {
        mPhoneBook.displayContactInformation( lIndex );
    }
    else
    {
        std::cout << "Index out of range!" << std::endl;
    }

    newInput();
}

//------------------------------------------------------------------------------
