#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <string>
using namespace std;

// Clase Producto: representa un artículo con nombre y precio
class Producto {
private:
    string nombre;
    double precio;

public:
    Producto(string n, double p);  // Constructor
    void mostrar() const;          // Muestra datos del producto
};

#endif
