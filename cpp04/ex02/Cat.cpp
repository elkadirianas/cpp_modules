#include "Cat.hpp"

Cat::Cat():Animal("Cat"){
    std::cout << "Cat Default Constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
    std::cout << "Cat " << type << " Constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat Copy Constructor called" << std::endl;
    brain = new Brain();
    *brain = *other.brain ; 
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat Assignment Operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain ; 
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
    delete this->brain ; 
}

void Cat::makeSound() const {
    std::cout << "* Meao ? *" << std::endl;
}