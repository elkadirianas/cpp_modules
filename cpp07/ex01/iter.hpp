#ifndef ITER_HPP 
#define ITER_HPP
#include <stddef.h>

// template <typename T >
template <typename T, typename func>
void iter(T* adr , size_t len , func fn){
    for (size_t i =0 ; i <len ; i++ ){
        fn(adr[i]);
    }
}

#endif