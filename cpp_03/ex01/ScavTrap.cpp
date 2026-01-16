#include "ScavTrap.hpp"


ScavTrap::ScavTrap(){
    std::cout << "ScavTrap Default constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " <<name <<" Destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << name <<" Copy constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScarvTrap Copy  " << name <<" assignment operator called." << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << name << " can't attack." << std::endl;
    }
}
