#include "Perro.hpp"
#include <iostream>
/*
Perro::Perro(const std::string nombre, int edad) 
    : nombre_(nombre), edad_(edad) {
}*/
Perro::Perro(const std::string nombre, int edad){
    this->nombre_ = nombre;
    this->edad_ = edad;
}
int Perro::get_edad() const{
    return this->edad_;
}
std::string Perro::get_nombre() const{
    return nombre_;
}
void Perro::set_edad(int edad){
    this->edad_ = edad;
}
void Perro::set_nombre(const std::string& nombre){
    nombre_ = nombre;
}
void Perro::ladrar(){
    std::cout << "Guau";
}
