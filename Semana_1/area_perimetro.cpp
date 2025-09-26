#include <iostream>

int main() {
    double largo, ancho;
    double area, perimetro;

    // Pedir los valores al usuario
    std::cout << "Ingrese el largo del rectangulo: ";
    std::cin >> largo;

    std::cout << "Ingrese el ancho del rectangulo: ";
    std::cin >> ancho;

    // Realizar las operaciones aritmeticas
    area = largo * ancho;
    perimetro = 2 * (largo + ancho);

    // Mostrar los resultados
    std::cout << "El area del rectangulo es: " << area << std::endl;
    std::cout << "El perimetro del rectangulo es: " << perimetro << std::endl;

    return 0;
}