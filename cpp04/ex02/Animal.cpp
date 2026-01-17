#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal " << type << " Constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal Assignment Operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "* Generic animal noises *" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}