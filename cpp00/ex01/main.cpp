#include "PhoneBook.hpp"

int main() {
	PhoneBook	myPhoneBook;
	std::string	userInput;

	std::cout<<"GUIDE:"<<std::endl;
	std::cout<<"ADD --> to a new contact"<<std::endl;
	std::cout<<"SEARCH --> to search for a contact"<<std::endl;
	std::cout<<"EXIT --> to exit obviously"<<std::endl;
	
    while (true) {
		std::cout<<"Enter a command: ";
		if(!std::getline(std::cin, userInput))
			return 0;
		if (userInput.empty()) {
			continue;
		}
		if (userInput == "ADD") {
			myPhoneBook.NewContact();
		} else if (userInput == "SEARCH") {
			myPhoneBook.Search();
		} else if (userInput == "EXIT") {
			return (0);
		} else {
			std::cout<<"Seems like you Tried a Non existing CMD"<<std::endl;
		}
	}
}