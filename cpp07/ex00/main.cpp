#include "whatever.hpp"

#include "iostream"

int main(){
    int a = 1 ; 
    int b = 2 ; 
    swap(a,b);
    std::cout << a <<std::endl ;
    std::cout << max(a,b) <<std::endl ;
    std::cout << min(a,b) <<std::endl ;
}