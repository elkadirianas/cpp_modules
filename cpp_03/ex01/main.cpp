#include "ScavTrap.hpp"
int main() {
    ClapTrap *a = new ScavTrap("robot_1");
    a->attack("target");
    a->takeDamage(12);
    a->beRepaired(20);

    delete a ; 

    ScavTrap *b = new ScavTrap("robot_2");
    b->attack("target");
    b->takeDamage(12);
    b->beRepaired(20);
    b->guardGate();
    delete b ; 

    ClapTrap c = ScavTrap("robot_3");
    c.attack("target");
    c.takeDamage(12);
    c.beRepaired(20); 

    return 0;
}