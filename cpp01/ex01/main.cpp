#include "Zombie.hpp"

int main(){
    Zombie *Zombies = zombieHorde(4,"random_name");
    for(int i =0 ;i<4;i++)
    {
        Zombies[i].announce();
    }
    delete[] Zombies ; 
}