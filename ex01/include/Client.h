// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef CLIENT_H
#define CLIENT_H

#include "PhoneBook.h"

class Client
{
public:

    Client( void );
    ~Client( void );

    int newOperation( std::string pOperation );

private:

    PhoneBook mPhoneBook;

    void add( void );
    void search( void ) const;

    void presentation( void ) const;
    void newInput( void ) const;

    int string2Int( std::string pStr ) const;

    std::string getContactInformation( std::string pInfoToAsk );
    
};

#endif
