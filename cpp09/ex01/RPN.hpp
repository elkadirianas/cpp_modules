#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN {
    private:
        std::stack<int> _stack;
        
        bool isOperator(char c) const;
        int doOperation(char op, int first, int last) const;
        
    public:
        RPN();
        RPN(const RPN& o);
        RPN& operator=(const RPN& o);
        ~RPN();
        
        int evaluate(const std::string& expression);
};

#endif