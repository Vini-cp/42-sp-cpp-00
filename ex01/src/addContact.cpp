
#include "../include/PhoneBook.hpp"

void addContact( PhoneBook &pb, Contact *contacts )
{
	int			contact_nb;
	std::string name;
	std::string nickname;
	std::string number;

	contact_nb = pb.getNoContacts();
	std::cout << "Name: ";
	std::getline (std::cin, name);
	std::cout << "Number: ";
	std::getline (std::cin, number);
	std::cout << "Nickname: ";
	std::getline (std::cin, nickname);
	contacts[contact_nb].setContact(name, number, nickname);
	pb.setNewContact(contacts[contact_nb]);
}
