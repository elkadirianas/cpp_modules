#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Anas");

    robot.attack("Target"); 
    robot.takeDamage(5);    
    robot.beRepaired(3);   
    

    for (int i = 0; i < 12; i++) {
        robot.attack("Elkadiri");
    }

    return 0;
}