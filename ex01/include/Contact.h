// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
public:

    Contact( void );
    Contact( std::string pFirstName, std::string pLastName, std::string pNickname, std::string pNumber, std::string pSecret );
    Contact( const Contact &prContact );
    ~Contact( void );

    Contact &operator=( const Contact &prContact );

    void setFirstName( std::string pName );
    std::string getFirstName( void ) const;

    void setLastName( std::string pName );
    std::string getLastName( void ) const;

    void setNickname( std::string pName );
    std::string getNickname( void ) const;

    void setNumber( std::string pNumber );
    std::string getNumber( void ) const;

    void setSecret( std::string pSecret );
    std::string getSecret( void ) const;

private:

    std::string mFirstName;
    std::string mLastName;
    std::string mNickname;
    std::string	mNumber;
    std::string mSecret;
};

#endif