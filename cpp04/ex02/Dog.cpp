#include "Dog.hpp"

Dog::Dog():Animal("dog"){
    std::cout << "Dog Default Constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
    std::cout << "Dog " << type << " Constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog Copy Constructor called" << std::endl;
    brain = new Brain();
    *brain = *other.brain ; 
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
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain ; 
}

void Dog::makeSound() const {
    std::cout << "* Baw waw ? *" << std::endl;
}
