#include <iostream>

int main() {
    double colones;
    double tasaCambio = 525.5; // Valor de ejemplo
    double dolares;

    // Pedir la cantidad de colones al usuario
    std::cout << "Ingrese la cantidad en colones (₡): ";
    std::cin >> colones;

    // Realizar la conversion
    dolares = colones / tasaCambio;

    // Mostrar el resultado
    std::cout << colones << " colones son equivalentes a " << dolares << " dolares ($)." << std::endl;

    return 0;
}