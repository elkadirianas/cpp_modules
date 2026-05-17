#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		int attr;
    public:
		Data();
		Data(int attr);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();
};

#endif