#include <iostream>
#include "Coche.hpp"

int main() {
    std::cout << "Inicio del programa de gestión de coches." << std::endl;
    
    Coche miCoche("Azul", 0);
    miCoche.acelerar(50);
    miCoche.acelerar(30);

    std::cout << "Fin del programa." << std::endl;

    return 0;
}