/*El operador * (desreferencia o indirection)
Sirve para acceder al valor guardado en la dirección de memoria a la que apunta un puntero.
*/
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* p = &x; // p es un puntero que guarda la direccion de x

    cout << "Direccion guardada en p: " << p << endl;
    cout << "Valor al que apunta p: " <<  *p << endl; // aqui usamos * y desreferencia 

    // Que pasa si las combino?
    x = 10;

    cout << *(&x); // primero &x (direccion de x), luego * (valor en esa direccion) -> 10

    return 0;
}