#include "Serializer.hpp"

int main(){
    Data d(1);
    std::cout << &d <<std::endl ; 
    uintptr_t a = Serializer::serialize(&d);
    std::cout << a <<std::endl ;
    Data *b = Serializer::deserialize(a);
    std::cout << b <<std::endl ;
}