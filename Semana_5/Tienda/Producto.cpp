#include "Producto.hpp"
#include <iostream>
using namespace std;

// Constructor
Producto::Producto(string n, double p) {
    nombre = n;
    precio = p;
}

// Mostrar producto
void Producto::mostrar() const {
    cout << "Producto: " << nombre << " | Precio: " << precio << endl;
}
