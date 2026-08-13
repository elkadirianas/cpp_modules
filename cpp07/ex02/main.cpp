#include "Array.hpp"
#include <iostream>

int main(){
    Array<int> arr(10);
    std::cout << "Array size : " << arr.size() << std::endl ; 

    for(unsigned int i = 0 ; i<arr.size() ; i++)
        arr[i]=i;

    std::cout << "Array elments : "; 
    for(unsigned int i = 0 ; i<arr.size() ; i++)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    std::cout << std::endl ;

    std::cout << " Deep Copy" <<std::endl;
    Array<int> arr1(arr);
    for(unsigned int i = 0 ; i<arr.size() ; i++)
        arr1[i]++;
    std::cout << "Original Array elments : "; 
    for(unsigned int i = 0 ; i<arr.size() ; i++)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    std::cout << "Modified Array elments : "; 
    for(unsigned int i = 0 ; i<arr.size() ; i++)
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
    std::cout << "test failure" << std::endl;
    try{
        arr[12]=1;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl; 
    }
}
