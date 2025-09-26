#include <iostream>

int main() {
    int a = 10;
    int b = 3;

    // Suma
    int suma = a + b;
    std::cout << "Suma: " << suma << std::endl; // Resultado: 13

    // Resta
    int resta = a - b;
    std::cout << "Resta: " << resta << std::endl; // Resultado: 7

    // Multiplicación
    int multiplicacion = a * b;
    std::cout << "Multiplicación: " << multiplicacion << std::endl; // Resultado: 30

    // División entera
    int divisionEntera = a / b;
    std::cout << "División entera: " << divisionEntera << std::endl; // Resultado: 3

    // División con decimales (convertimos los números a double)
    double divisionDecimal = static_cast<double>(a) / b;
    std::cout << "División decimal: " << divisionDecimal << std::endl; // Resultado: 3.333...

    // Módulo (residuo)
    int modulo = a % b;
    std::cout << "Módulo: " << modulo << std::endl; // Resultado: 1

    return 0;
}