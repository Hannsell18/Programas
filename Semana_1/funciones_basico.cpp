#include <iostream>

// --- Funcion que no recibe parametros y no retorna nada ---
void saludar() {
    std::cout << "¡Hola desde la funcion saludar!" << std::endl;
}

// --- Funcion que recibe dos parametros y retorna un entero ---
int sumar(int a, int b) {
    int resultado = a + b;
    return resultado;
}

int main() {
    // Invocar la funcion 'saludar'. Solo la llamamos por su nombre
    saludar();

    // Invocar la funcion 'sumar' y pasarle dos valores (argumentos)
    int suma = sumar(5, 3); // La funcion se ejecuta y retorna 8
    std::cout << "El resultado de la suma es: " << suma << std::endl;

    return 0;
}




