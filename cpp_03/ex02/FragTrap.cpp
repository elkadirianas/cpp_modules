#include "FragTrap.hpp"


FragTrap::FragTrap(){
    std::cout << "FragTrap Default constructed." << std::endl;
    this->hitPoints=100 ; 
    this->energyPoints = 100 ; 
    this->attackDamage = 30 ; 
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    std::cout << "FragTrap " << name << " constructed." << std::endl;
    this->hitPoints=100 ; 
    this->energyPoints = 100 ; 
    this->attackDamage = 30 ; 
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " <<name <<" Destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << name <<" Copy constructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other){
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap Copy  " << name <<" assignment operator called." << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "FragTrap " << name << " can't attack." << std::endl;
    }
}

void FragTrap::highFivesGuys(void){
    std::cout << name << " request a postive highfives " << std::endl ; 
};