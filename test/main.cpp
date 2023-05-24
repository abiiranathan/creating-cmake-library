#include <add/add.h>

#include <iostream>

int main(void) {
    int a = 10;
    int b = 30;

    std::cout << "a +b =" << add(a, b) << "\n";
    std::cout << "a  - b =" << sub(a, b) << "\n";
}