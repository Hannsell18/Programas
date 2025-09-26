#include <iostream>

int main() {
    int a = 5;
    int b = 10;

    std::cout << "Valores iniciales:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    // --- Lógica del intercambio ---
    int temp = a; // Paso 1: Guardar el valor de 'a' en una variable temporal
    a = b;        // Paso 2: Copiar el valor de 'b' en 'a'
    b = temp;     // Paso 3: Copiar el valor de la variable temporal en 'b'

    std::cout << "\nValores después del intercambio:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}