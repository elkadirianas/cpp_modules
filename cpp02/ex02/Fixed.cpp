#include "Fixed.hpp"



Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    value = n << fractionalBits; 
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(f * 256);
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
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}



bool Fixed::operator>(const Fixed &other) const  { return this->value > other.value; }
bool Fixed::operator<(const Fixed &other) const  { return this->value < other.value; }
bool Fixed::operator>=(const Fixed &other) const { return this->value >= other.value; }
bool Fixed::operator<=(const Fixed &other) const { return this->value <= other.value; }
bool Fixed::operator==(const Fixed &other) const { return this->value == other.value; }
bool Fixed::operator!=(const Fixed &other) const { return this->value != other.value; }



Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++(void) {
    this->value++;
    return *this;
}


Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->value++;
    return temp;
}

Fixed& Fixed::operator--(void) {
    this->value--;
    return *this;
}


Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->value--;
    return temp;
}



Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}



std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}