#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
    private : 
        std::string name ; 
        unsigned int hit_point ; 
        unsigned int energy_point ;
        unsigned int attack_damage ; 
    public : 
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        std::string get_name() const ; 
        unsigned int get_hit_point() const ; 
        unsigned int get_energy_point() const ; 
        unsigned int get_attack_damage() const ;



        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
