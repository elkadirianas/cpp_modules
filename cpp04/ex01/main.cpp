#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



int main()
{

    const Animal* zoo[10];
    std::cout << "--- creating Dogs ---" << std::endl;
    for (int i = 0; i < 10 / 2; i++) {
        zoo[i] = new Dog();
    }
    std::cout << "--- creating Cats ---" << std::endl;
    for (int i = 10 / 2; i < 10; i++) {
        zoo[i] = new Cat();
    }

    std::cout << "--- Testing Sounds ---" << std::endl;
    zoo[0]->makeSound();
    zoo[10 - 1]->makeSound(); 

    std::cout << "\n--- Deleting Zoo ---" << std::endl;
    for (int i = 0; i < 10; i++) {
        delete zoo[i];
    }


    Dog basic; 
    
    {
        std::cout << "[Scope Start] Creating copy named 'tmp'" << std::endl;
        Dog tmp = basic;
        std::cout << "[Scope End] Destroying 'tmp' now..." << std::endl;
    } 

    std::cout << "[Back in Main] 'basic' is still alive." << std::endl;
    std::cout << "If Deep Copy failed, program will crash when 'basic' is destroyed below." << std::endl;



    return 0;
}