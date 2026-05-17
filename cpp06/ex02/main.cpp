#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate(void){
    srand(time(NULL)); 
    int rand = std::rand() % 3 ;
    switch(rand){
        case 0 :
            return (new A);
        case 1 : 
            return (new B);
        case 2 : 
            return (new C);
    }
    return NULL ; 
}


void identify(Base* p){
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);

    if(a)
        std::cout << "The actual type of the object pointed to by p: A" << std::endl ;
    else if (b)
        std::cout << "The actual type of the object pointed to by p: B" << std::endl ;
    else if (c)
        std::cout << "The actual type of the object pointed to by p: C" << std::endl ;
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "The actual type of the object pointed to by p: A" << std::endl ;
    }catch(std::exception &e){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "The actual type of the object pointed to by p: B" << std::endl ;
    }catch(std::exception &e){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "The actual type of the object pointed to by p: C" << std::endl ;
    }catch(std::exception &e){}
    
}

int main(){
    Base *b = generate();
    identify(*b);

}