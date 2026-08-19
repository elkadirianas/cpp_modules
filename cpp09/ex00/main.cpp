#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: args passed not valid" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try
    {
        btc.loadDatabase("data.csv");
        btc.processInput(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}