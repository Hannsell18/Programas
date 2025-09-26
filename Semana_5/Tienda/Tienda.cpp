#include "Tienda.hpp"
#include <iostream>
using namespace std;

// Constructor: recibe un arreglo de punteros a Producto
Tienda::Tienda(Producto* lista[], int cant) {
    cantidad = (cant <= 10) ? cant : 10;
    for (int i = 0; i < cantidad; i++) {
        productos[i] = lista[i]; // Guardamos los punteros
    }
}

// Destructor: libera la memoria de cada producto
Tienda::~Tienda() {
    for (int i = 0; i < cantidad; i++) {
        delete productos[i]; // Liberamos lo que se creó con new
    }
}

// Muestra todos los productos de la tienda
void Tienda::mostrarProductos() const {
    cout << "Productos en la tienda:" << endl;
    for (int i = 0; i < cantidad; i++) {
        productos[i]->mostrar();
    }
}
