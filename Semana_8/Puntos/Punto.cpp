#include "Punto.hpp"

// Constructor
Punto::Punto(int x, int y) : x(x), y(y) {}

// Implementación del operador +
// resultado = pt1+pt2
Punto Punto::operator+(const Punto& otroPunto) {
    Punto resultado;
    resultado.x = this->x + otroPunto.x;
    resultado.y = this->y + otroPunto.y;
    return resultado;
}

Punto Punto::operator+(int numero){
    Punto resultado;
    resultado.x = this->x + numero;
    resultado.y = this->y+ numero;
    return resultado;
}

Punto operator+(int numero, const Punto& puntoSumar){
    Punto resultado;
    resultado.x = puntoSumar.x + numero;
    resultado.y = puntoSumar.y + numero;
    return resultado;
}