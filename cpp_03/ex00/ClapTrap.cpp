#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("whatever"),hit_point(10),energy_point(10),attack_damage(0){
    std::cout << "Default Constructor Called " << std::endl ; 
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor Called " << std::endl ; 
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << "Copy Constructor Called " << std::endl ;
    *this = other ; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << "Copy assignment operator Called " << std::endl ; 
    // if(this!=&other){
        name=other.get_name();
        energy_point = other.get_energy_point();
        hit_point = other.get_hit_point();
        attack_damage = other.get_attack_damage();
    // }
    return *this ; 
}

std::string ClapTrap::get_name() const {  return name ;}

unsigned int ClapTrap::get_hit_point() const { return hit_point ; }

unsigned int ClapTrap::get_energy_point() const {return energy_point ;}

unsigned int ClapTrap::get_attack_damage() const {return attack_damage ;} 