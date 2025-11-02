#ifndef Contact_hpp
#define Contact_hpp

#include <iostream>

class Contact 
{
	private :
		std::string first_name ;
		std::string last_name ; 
		std::string phone_number; 
		std::string nick_name ;
		std::string darkest_secret ; 
	public : 
		Contact();
		~Contact();

		std::string GetFirstName(void);
        std::string GetLastName(void);
        std::string GetPhoneNum(void);
        std::string GetDarkestSecret(void);
        std::string GetNickName(void);

        void        SetFirstName(std::string first_name);
        void        SetLastName(std::string last_name);
		void        SetPhoneNumber(std::string phone_number);
        void        SetNickName(std::string nick_name);
        void        SetDarkestSecret(std::string darkest_secret);	
};

#endif
