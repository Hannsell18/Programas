#include "Tienda.hpp"
#include "Producto.hpp"

int main() {
    // Creamos productos en memoria dinámica con "new"
    Producto* p1 = new Producto("Pan", 500);
    Producto* p2 = new Producto("Leche", 700);
    Producto* p3 = new Producto("Queso", 1200);

    // Creamos un arreglo de punteros a productos
    Producto* lista[3] = { p1, p2, p3 };

    // Creamos la tienda pasándole la lista
    Tienda miTienda(lista, 3);

    // Mostramos los productos
    miTienda.mostrarProductos();

    // No hace falta delete aquí, porque el destructor de Tienda
    // se encarga de liberar los productos automáticamente.

    return 0;
}
