#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}


std::string Contact::GetDarkestSecret(void) {
    return darkest_secret;
}

std::string Contact::GetFirstName(void) {
    return first_name;
}

std::string Contact::GetLastName(void) {
    return last_name;
}

std::string Contact::GetNickName(void) {
    return nick_name;
}

std::string Contact::GetPhoneNum(void) {
    return phone_number;
}

void    Contact::SetDarkestSecret(std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}

void    Contact::SetFirstName(std::string first_name) {
    this->first_name = first_name;
}

void    Contact::SetLastName(std::string last_name) {
    this->last_name = last_name;
}

void    Contact::SetNickName(std::string nick_name) {
    this->nick_name = nick_name;
}

void    Contact::SetPhoneNumber(std::string phone_number)
{
    this->phone_number = phone_number;
}
