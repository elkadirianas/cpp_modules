#include "Zombie.hpp"

int main(){
    Zombie Z1("first_zombie");
    Z1.announce();
    Zombie *Z2 =newZombie("second_zombie");
    Z2->announce();
    randomChump("third_zombie");
    delete Z2 ; 
}