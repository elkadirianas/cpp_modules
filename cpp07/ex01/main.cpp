#include "iter.hpp"

#include "iostream"

void print(const int &x)
{
    std::cout << x << " ";
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    iter(arr, 5, print);
}