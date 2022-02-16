#include "../include/PhoneBook.hpp"

static std::string strToPrint(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	else
		return (str);
}

static void	printContacts( std::string idx, std::string fn, std::string ln, std::string nn)
{
	std::cout << std::right << std::setw(10) << idx;
	std::cout << " | ";
	std::cout << std::right << std::setw(10) << fn;
	std::cout << " | ";
	std::cout << std::right << std::setw(10) << ln;
	std::cout << " | ";
	std::cout << std::right << std::setw(10) << nn; 
	std::cout << std::endl;
}

static void	printContacts( int idx, std::string fn, std::string ln, std::string nn)
{
	std::cout << std::right << std::setw(10) << idx;
	std::cout << " | ";
	std::cout << std::right << std::setw(10) << fn;
	std::cout << " | ";
	std::cout << std::right << std::setw(10) << ln;
	std::cout << " | ";
	std::cout << std::right << std::setw(10) << nn; 
	std::cout << std::endl;
}

static int	getContactIndex( int contact_nb )
{
	int	contact;

	std::cout << std::endl;
	std::cout << "Type the contact index to show his number: ";
	std::cin >> contact;
	while (contact < 0 || contact >= contact_nb)
	{
		std::cout << "This contact index is not on the list" << std::endl;
		std::cout << "Please, inform a contact index to show his number: ";
		std::cin >> contact;
	}
	std::cin.clear();
	return (contact);
}

void searchContact( PhoneBook &pb )
{
	int			contact_nb = pb.getNoContacts();
	std::string *names = pb.getContactsName(); 
	std::string *nicknames = pb.getContactsNickname();
	std::string *numbers = pb.getContactsNumber(); 

	printContacts( "Index", "First Name" ,"Last Name", "Nickname" );
	for (int i = 0; i < contact_nb; i++)
	{
		printContacts(
			i,
			strToPrint(names[i].substr(0, names[i].find(" "))),
			strToPrint(names[i].substr(names[i].find(" "), -1)),
			strToPrint(nicknames[i])
		);
	}
	if (contact_nb > 0)
	{
		int nbr = getContactIndex( contact_nb );

		std::cout << std::endl;
		std::cout << "Name: " << names[nbr] << std::endl;
		std::cout << "Nickname: " << nicknames[nbr] << std::endl;
		std::cout << "Number: " << numbers[nbr] << std::endl;
	}
	delete[] names;
	delete[] nicknames;
	delete[] numbers;
}
