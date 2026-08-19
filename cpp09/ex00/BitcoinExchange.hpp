#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> db;
        bool isValidValue(std::string str, double& value);
        bool isValidDate(std::string date);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& b);
        BitcoinExchange& operator=(const BitcoinExchange& b);
        ~BitcoinExchange();

        void loadDatabase(std::string filename);
        void processInput(std::string filename);
};

#endif