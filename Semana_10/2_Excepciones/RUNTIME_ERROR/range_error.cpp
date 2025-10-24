#include <iostream>
#include <stdexcept>

int calcularPorcentaje(int parte, int total) {
    if (total == 0) {
        throw std::range_error("No se puede calcular porcentaje de un total cero");
    }
    return (parte * 100) / total;
}

int main() {
    try {
        std::cout << "50 de 200: " << calcularPorcentaje(50, 200) << "%" << std::endl;  // OK
        std::cout << "30 de 0: " << calcularPorcentaje(30, 0) << "%" << std::endl;      // ERROR
    }
    catch (const std::range_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*Salida:

50 de 200: 25%
Error: No se puede calcular porcentaje de un total cero
*/