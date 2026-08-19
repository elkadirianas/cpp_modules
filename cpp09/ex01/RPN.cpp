
#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& o) : _stack(o._stack) {}

RPN& RPN::operator=(const RPN& o) {
    if (this != &o) {
        _stack = o._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool isnotDigit(char n)
{
    return !(n >= '0' && n <= '9');
}


bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::doOperation(char op, int first, int last) const {
    switch (op) {
        case '+': return first + last;
        case '-': return first - last;
        case '*': return first * last;
        case '/':
            if (last == 0) throw std::runtime_error("Division by zero");
            return first / last;
        default: throw std::runtime_error("Invalid operator");
    }
}

int RPN::evaluate(const std::string& expression) {    
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error - insufficient operands");
            }
            
            int last = _stack.top(); _stack.pop();
            int first = _stack.top(); _stack.pop();
            
            int result = doOperation(token[0], first, last);
            _stack.push(result);
        } else {
            char* end;
            long num = std::strtol(token.c_str(), &end, 10);
            
            if (*end != '\0' || num < 0 || num > 9) {
                throw std::runtime_error("Error - invalid token");
            }

            _stack.push(num);
        }

    }
    if (_stack.size() != 1) {
        throw std::runtime_error("Error - too many operands");
    }

    return _stack.top();
}