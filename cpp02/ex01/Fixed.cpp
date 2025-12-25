#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    value = other.getRawBits();
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    value = n << fractionalBits; 
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(f * (1 << fractionalBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

float Fixed::toFloat(void) const {
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}