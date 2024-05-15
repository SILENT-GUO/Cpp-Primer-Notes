#include <iostream>

//compile with g++ -std=c++11 demo.cpp -o demo

int main(){
    int a = 5;
    const int &aa = 10;
    int *ptr = &a;
    std::cout << ptr << std::endl;
    a = 10;
    std::cout << ptr << std::endl;
    ptr = nullptr;

    int *const ptr2 = &a;
    std::cout << *ptr2 << std::endl;
    *ptr2 = 15;
    std::cout << *ptr2 << std::endl;
    //ptr2 = nullptr; //error

    return 0;
}