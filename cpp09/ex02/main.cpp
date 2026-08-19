#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: ./PmergeMe [......]" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe p;
        for (long i = 1; i <= ac -1; i++)
        {
            std::string arg = av[i];
            p.parse(arg);
        }
        p.showBefore();
        p.sort();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}