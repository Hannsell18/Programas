#include <iostream>

int main() {
    int numeros[] = {10, 20, 30, 40, 50};

    int* p1 = &numeros[1]; // Puntero al segundo elemento (20)
    int* p2 = &numeros[4]; // Puntero al último elemento (50)

    // La resta de punteros
    long long diferencia = p2 - p1;

    // Salida: La diferencia es 3
    std::cout << "La diferencia entre los punteros es: " << diferencia << " elementos." << std::endl;

    return 0;
}