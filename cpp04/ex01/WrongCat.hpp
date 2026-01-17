#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);

        ~WrongCat();

        virtual void makeSound() const;
};

#endif