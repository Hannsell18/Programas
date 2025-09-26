#include <iostream>

int main() {
    int edad = 25;
    bool esClientePremium = false;
    bool tieneCompraReciente = true;
    bool tieneDeudaPendiente = false;

    // Si es mayor a 18 Y, es cliente premium O tiene una compra reciente, Y NO tiene deudas pendientes
    if ((edad > 18) && (esClientePremium || tieneCompraReciente) && (!tieneDeudaPendiente)) {
        std::cout << "¡Felicidades! Eres elegible para la promocion." << std::endl;
    } else {
        std::cout << "Lo sentimos, no eres elegible para la promocion." << std::endl;
    }

    return 0;
}

