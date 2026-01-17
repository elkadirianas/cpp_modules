#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name("whatever"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap Default constructed." << std::endl;
}


ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20) {
    std::cout << "ClapTrap " << name << " constructed." << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << "ClapTrap " << name << " Copy constructed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name <<" Copy assignment operator called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;

}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > amount) {
        hitPoints -= amount;
    } else {
        hitPoints = 0;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage! Current HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount 
                  << " points! Current HP: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't repair (Low HP or Energy)." << std::endl;
    }
}