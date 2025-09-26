#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "Producto.hpp"

class Tienda {
private:
    Producto* productos[10]; // Máximo 10 productos
    int cantidad;

public:
    Tienda(Producto* lista[], int cant);
    ~Tienda(); // Destructor para liberar memoria

    void mostrarProductos() const;
};

#endif
