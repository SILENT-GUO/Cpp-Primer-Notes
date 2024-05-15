#include <iostream>

//compile with g++ -std=c++11 demo.cpp -o demo

int main(){
    int a = 5;
    const int &b  = a;
    std::cout << "b: " << b << std::endl;
    int &c = a;
    c = 10;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    return 0;
}