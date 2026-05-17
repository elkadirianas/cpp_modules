#include "Data.hpp"

Data::Data(){}
Data::Data(int attr) : attr(attr){}
Data::Data(const Data &other) : attr(other.attr){}
Data &Data::operator=(const Data &other)
{
	if(this!=&other)
        attr=other.attr;
    return *this ; 
}
Data::~Data(){}
