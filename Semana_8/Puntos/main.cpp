#include <iostream>
#include "Punto.hpp"

int main() {
    // Creación de objetos en pila
    Punto p1(10, 5);
    Punto p2(3, 8);

    // Uso de operador +
    Punto p3 = p1 + p2;

    std::cout << "Punto 1: (" << p1.x << ", " << p1.y << ")\n";
    std::cout << "Punto 2: (" << p2.x << ", " << p2.y << ")\n";
    std::cout << "Punto 3 (p1 + p2): (" << p3.x << ", " << p3.y << ")\n";


    return 0;
}
