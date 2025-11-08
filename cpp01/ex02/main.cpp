#include <iostream>

int main(){
    std::string S="HI THIS IS BRAIN";
    std::string *stringPTR=&S;
    std::string &stringREF=S;

    std::cout<<"The memory address of the string variable "<<&S<<std::endl;
    std::cout<<"The memory address held by stringPTR      "<<stringPTR<<std::endl;
    std::cout<<"The memory address held by stringREF      "<<&stringREF<<std::endl;

    std::cout<<"The value of the string variable "<<S<<std::endl;
    std::cout<<"The value held by stringPTR      "<<*stringPTR<<std::endl;
    std::cout<<"The value held by stringREF      "<<stringREF<<std::endl;
}