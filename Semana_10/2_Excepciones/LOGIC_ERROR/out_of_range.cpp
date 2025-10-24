#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    std::vector<int> numeros = {10, 20, 30};
    
    try {
        std::cout << "Elemento 1: " << numeros.at(1) << std::endl;  // Gucci
        std::cout << "Elemento 5: " << numeros.at(5) << std::endl;  // ERROR
    }
    catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*
Salida:
Elemento 1: 20
Error: vector::_M_range_check: __n (which is 5) >= this->size() (which is 3)
*/