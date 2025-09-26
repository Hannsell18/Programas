#include <iostream>

int main() {
    bool esEstudiante = true;
    int edad = 20;
    bool haUsadoDescuentoEsteMes = false;

    // Condición combinada
    if (esEstudiante && (edad >= 18 && edad <= 25) && !haUsadoDescuentoEsteMes) {
        std::cout << "¡Felicidades! Usted es elegible para el descuento de estudiante." << std::endl;
    } else {
        std::cout << "Lo sentimos, no cumple con todos los requisitos para el descuento." << std::endl;
    }

    return 0;
}