// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include <cstdlib>
#include "./include/Client.h"

int main( void )
{
    Client cl;

    std::string operation;

    while ( !std::cin.eof() )
    {
        std::getline( std::cin, operation );
        if ( cl.newOperation( operation ) )
        {
            break;
        }
    }
    return 0;
}
