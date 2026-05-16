#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}; 
ScalarConverter::ScalarConverter(const ScalarConverter &other){
    (void)other; 
};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void)other; 
    return *this; 
}; 
ScalarConverter::~ScalarConverter(){};


void Print_Int(double number,bool flag){
    std::cout << "int: ";
    if((flag && number ==0)||  std::isnan(number) || number > 2147483647 || number < -2147483648 )
        std::cout << "impossible" <<std::endl;
    else {
        int res = static_cast<int>(number);
        std::cout << res <<std::endl; 
    }
}

void Print_Char(double number,bool flag){
    std::cout << "char: "; 
    if((flag && number ==0)||std::isnan(number) || number > 127 || number < 0)
        std::cout << "impossible" <<std::endl;
    else {
        char res = static_cast<char>(number);
        if(std::isprint(res))
            std::cout << "'" << res <<"'" << std::endl;
        else
            std::cout << "Non displayable" <<std::endl;
    }
}

void Print_Float(double number,bool flag){
    std::cout << "float: ";
    float res = static_cast<float>(number);
    if((flag && number ==0))
        std::cout << "impossible" <<std::endl;
    else{
        if(std::isinf(res)){
            if(res>0)
                std::cout <<"+inff" <<std::endl;
            else
                std::cout <<"-inff" <<std::endl;
        }
        else
            std::cout << std::fixed<< std::setprecision(1) << res << "f" << std::endl;      
    }
}

void Print_Double(double number,bool flag){
    std::cout << "double: ";
    if((flag && number ==0))
        std::cout << "impossible" <<std::endl;
    else{
        if(std::isinf(number)){
            if(number>0)
                std::cout <<"+inf" <<std::endl;
            else
                std::cout <<"-inf" <<std::endl;
        }
        else
            std::cout << std::fixed<< std::setprecision(1) << number << std::endl;      
    }
}

void ScalarConverter::convert(std::string number){
    bool flag= number.compare("0");
    double num = std::atof(number.c_str());
    if(number.length()==1 && !std::isdigit(number[0]))
        num = static_cast<double>(number[0]); 
    Print_Int(num,flag);
    Print_Char(num,flag);
    Print_Float(num,flag);
    Print_Double(num,flag);
}