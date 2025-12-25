#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int n);
    Fixed(const float f);

    ~Fixed();

    Fixed& operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

// This must be OUTSIDE the class definition because it takes two arguments
std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif