#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
}

PhoneBook::~PhoneBook() {

}

int	is_printable(std::string str) {
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!std::isprint(str[i]))
			return (0);
	}
	return (1);
}

void    PhoneBook::NewContact() {
	std::string input;
	Contact newContact;

	while (true) {
		std::cout<<"Enter the first name: ";
		if (!std::getline(std::cin, input) || input.empty() || !is_printable(input))
		{
			std::cerr<<"incorrect input"<<std::endl;
			return;
		} else {
			newContact.SetFirstName(input);
			break;
		}
	}
	while (true) {
		std::cout<<"Enter the last name: ";
		if (!std::getline(std::cin, input) || input.empty() || !is_printable(input))
		{
			std::cerr<<"incorrect input"<<std::endl;
			return;
		} else {
			newContact.SetLastName(input);
			break;
		}
	}
	while (true) {
		std::cout<<"Enter the Phone number: ";
		if (!std::getline(std::cin, input) || input.empty() || !is_printable(input))
		{
			std::cerr<<"Wrong Entry"<<std::endl;
			return;
		} else {
			newContact.SetPhoneNumber(input);
			break;
		}
	}
	while (true) {
		std::cout<<"enter the nickname: ";
		if (!std::getline(std::cin, input) || input.empty() || !is_printable(input))
		{
			std::cerr<<"Wrong Entry"<<std::endl;
			return;
		} else {
			newContact.SetNickName(input);
			break;
		}
	}
	while (true) {
		std::cout<<"enter the Darkest secret: ";
		if (!std::getline(std::cin, input) || input.empty() || !is_printable(input))
		{
			std::cerr<<"Wrong Entry"<<std::endl;
			return;
		} else {
			newContact.SetDarkestSecret(input);
			break;
		}
	}
	contacts[index++ % 8] = newContact;
	std::cout<<"Done !"<<std::endl;
}
void PhoneBook::Search() {
	std::string str_index;

	if (index == 0)
	{
		std::cerr<<"no contacts in the phonebook!"<<std::endl;
		std::cerr<<"try add one"<<std::endl;
		return;
	}
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"|";
	std::cout<<std::setw(10)<<"index";
	std::cout<<"|";
	std::cout<<std::setw(10)<<"first name";
	std::cout<<"|";
	std::cout<<std::setw(10)<<"last name";
	std::cout<<"|";
	std::cout<<std::setw(10)<<"nickname";
	std::cout<<"|"<<std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;
	for (int i = 0; i < index && i < 8; i-=-1)
	{
		std::string FirstName = contacts[i].GetFirstName();
		std::string LastName = contacts[i].GetLastName();
		std::string NickName = contacts[i].GetNickName();
		std::cout<<"|";
		std::cout<<std::setw(10)<<i;
		std::cout<<"|";
		FirstName.length() >= 10 ? std::cout<<FirstName.substr(0, 9)<<"." : std::cout<<std::setw(10)<<FirstName;
		std::cout<<"|";
		LastName.length() >= 10 ? std::cout<<LastName.substr(0, 9)<<"." : std::cout<<std::setw(10)<<LastName;
		std::cout<<"|";
		NickName.length() >= 10 ? std::cout<<NickName.substr(0, 9)<<"." : std::cout<<std::setw(10)<<NickName;
		std::cout<<"|"<<std::endl;
		std::cout<<"---------------------------------------------"<<std::endl;

	}
	std::cout<<std::endl;
	std::cout<<"enter index: ";
	if (!std::getline(std::cin, str_index) || str_index.empty() || !is_printable(str_index))
	{
		std::cerr<<"error"<<std::endl;
		return;
	}
	if (str_index.length() > 1)
	{
		std::cerr<<"index must be between 0-7"<<std::endl;
		return;
	}
	int i_index = str_index[0] - '0';
	if (i_index >= index || i_index >=8)
	{
		std::cerr<<"index invalid/out of range"<<std::endl;
		return;
	}
	std::cout<<"First name: "<<contacts[i_index].GetFirstName()<<std::endl;
	std::cout<<"Last name: "<<contacts[i_index].GetLastName()<<std::endl;
	std::cout<<"Nickname: "<<contacts[i_index].GetNickName()<<std::endl;
	std::cout<<"darkest secret: "<<contacts[i_index].GetDarkestSecret()<<std::endl;
	std::cout<<"Phone number: "<<contacts[i_index].GetPhoneNum()<<std::endl;
}
