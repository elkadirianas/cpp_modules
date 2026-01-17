#include "Dog.hpp"

Dog::Dog():Animal("dog"){
    this->brain = new Brain();
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    this->brain = new Brain();
    std::cout << "Dog " << type << " Constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    brain = new Brain();
    *brain = *other.brain ; 
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog Assignment Operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain ; 
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain ; 
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "* Baw waw ? *" << std::endl;
}