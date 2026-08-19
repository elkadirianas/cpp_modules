#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): db(other.db) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    db = other.db;
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(std::string date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (m < 1 || m > 12 || d < 1)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        daysInMonth[1] = 29;
    return d <= daysInMonth[m - 1];
}

bool BitcoinExchange::isValidValue(std::string str, double& value)
{
    char* endptr;
    value = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' && !isspace(*endptr))
        return false;
    return true;
}

void BitcoinExchange::loadDatabase(std::string filename)
{
    if (filename.size() >= 4)
    {
        std::string last = filename.substr(filename.size() - 4, filename.size());
        if (last != ".csv")
            throw std::runtime_error("Error: not a valid file format ");
    }
    else
        throw std::runtime_error("Error: file name size too short");
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could'nt open file.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t sep = line.find(',');
        if (sep != std::string::npos)
        {
            db[line.substr(0, sep)] = std::atof(line.substr(sep + 1).c_str());
        }
    }
}

void BitcoinExchange::processInput(std::string filename)
{
    if (filename.size() >= 4)
    {
        std::string last = filename.substr(filename.size() - 4, filename.size());
        if (last != ".txt")
            throw std::runtime_error("Error: not a valid file format ");
    }
    else
        throw std::runtime_error("Error: file name size too short");
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could'nt open file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t sep = line.find('|');
        if (sep == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, sep);
        date.erase(date.find_last_not_of(" \t") + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        std::string valStr = line.substr(sep + 1);
        double val;
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
        }
        else if (!isValidValue(valStr, val))
        {
            std::cout << "Error: not a valid number." << std::endl;
        }
        else if (val < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
        }
        else if (val > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
        }
        else
        {
            std::map<std::string, double>::iterator it = db.upper_bound(date);
            if (it == db.begin())
            {
                std::cout << "Error: date predates database => " << date << std::endl;
            }
            else
            {
                --it;
                std::cout << date << " => " << val << " = " << (val * it->second) << std::endl;
            }
        }
    }
}