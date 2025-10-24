#include <iostream>
#include <stdexcept>
#include <cmath>

double calcularRaiz(double numero) {
    if (numero < 0) {
        throw std::domain_error("No se puede calcular raiz de numero negativo");
    }
    return sqrt(numero);
}

int main() {
    try {
        std::cout << "Raíz de 16: " << calcularRaiz(16) << std::endl;    // OK
        std::cout << "Raíz de -9: " << calcularRaiz(-9) << std::endl;    // ERROR
    }
    catch (const std::domain_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*
Salida:
Raíz de 16: 4
Error: No se puede calcular raíz de número negativo
*/