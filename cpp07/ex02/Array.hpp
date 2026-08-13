
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array {
private:
    T* elm;
    unsigned int a_size;

public:
    Array() : elm(NULL), a_size(0) {}
    Array(const Array& other) : elm(NULL), a_size(0) {*this = other;}
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elm;
            a_size = other.a_size;
            elm = new T[a_size];
            for (unsigned int i = 0; i < a_size; i++) {
                elm[i] = other.elm[i];
            }
        }
        return *this;
    }
    Array(unsigned int n) : a_size(n) {
        elm = new T[n]();
    }
    
    ~Array() {
        delete[] elm;
    }
    
    T& operator[](unsigned int index) {
        if (index >= a_size)
            throw OutOfRange();
        return elm[index];
    }
    
    const T& operator[](unsigned int index) const {
        if (index >= a_size)
            throw OutOfRange();
        return elm[index];
    }

    unsigned int size() const {
        return a_size;
    }

    class OutOfRange : public std::exception {
        public:
            const char *what() const throw(){
                return "Index out of range.";
            };
    };
};

#endif