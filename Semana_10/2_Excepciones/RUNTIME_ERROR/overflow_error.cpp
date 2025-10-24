#include <iostream>
#include <stdexcept>
#include <limits>

void incrementarContador(int& contador, int cantidad) {
    if (contador > std::numeric_limits<int>::max() - cantidad) {
        throw std::overflow_error("El contador excedería el valor máximo");
    }
    contador += cantidad;
}

int main() {
    try {
        int contador = 2147483640;  // Cerca del máximo de int
        
        incrementarContador(contador, 5);     // OK
        std::cout << "Contador: " << contador << std::endl;
        
        incrementarContador(contador, 10);    // ERROR - excede máximo
    }
    catch (const std::overflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*
Salida:
Contador: 2147483645
Error: El contador excedería el valor máximo
*/