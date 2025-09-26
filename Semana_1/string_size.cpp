#include <iostream>
#include <string>

int main() {
    std::string mensaje = "Hola, mundo!";

    // Usando .length()
    std::cout << "El tamanio con .length() es: " << mensaje.length() << std::endl;

    // Usando .size()
    std::cout << "El tamanio con .size() es: " << mensaje.size() << std::endl;

    // Porqué existen los dos, porque length es específico de string.
    // En cambio, size es para los contenedores de c++ en C++ como vectores o maps.
    return 0;
}