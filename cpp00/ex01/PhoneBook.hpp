#ifndef Phone_boo_hpp
#define Phone_book_hpp 

#include "Contact.hpp"
#include <string>
#include <iomanip>
class PhoneBook 
{
	private : 
		Contact contacts[8];
		int index;
	public : 
		PhoneBook();
		~PhoneBook(); 
		void NewContact(); 
		void Search(); 
};



#endif
