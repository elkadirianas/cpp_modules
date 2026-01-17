#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta; 
    delete j ; 
    delete i ; 

    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* wrong_i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    wrong_i->makeSound();
    wrongmeta->makeSound();

    delete wrong_i; 
    delete wrongmeta ; 

    return 0;
}