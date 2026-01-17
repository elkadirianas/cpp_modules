#include "FragTrap.hpp"
int main() {
    ClapTrap *a = new FragTrap("robot_1");
    a->attack("target");
    a->takeDamage(12);
    a->beRepaired(20);

    delete a ; 

    FragTrap *b = new FragTrap("robot_2");
    b->attack("target");
    b->takeDamage(12);
    b->beRepaired(20);
    b->highFivesGuys();
    delete b ; 

    ClapTrap c = FragTrap("robot_3");
    c.attack("target");
    c.takeDamage(12);
    c.beRepaired(20); 

    return 0;
}