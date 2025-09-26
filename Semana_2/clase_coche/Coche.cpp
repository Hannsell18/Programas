#include "Coche.hpp"
#include <iostream>

// Implementación del constructor
Coche::Coche(const std::string& color, int velocidad)
    : color_(color), velocidad_(velocidad) {
    std::cout << "Se ha creado un coche de color " << color_ << "." << std::endl;
}
/*
Coche::Coche(const std::string& color, int velocidad) {
    color_ = color;
    velocidad_ = velocidad;
}
*/
// Implementación de los métodos
std::string Coche::getColor() const {
    return color_;
}

int Coche::getVelocidad() const {
    return velocidad_;
}

void Coche::acelerar(int kmh) {
    velocidad_ += kmh;
    std::cout << "El coche de color " << color_ << " ahora va a " << velocidad_ << " km/h." << std::endl;
}