/*
Paso por referencia usando punteros

Si en lugar de pasar el valor pasamos la dirección de memoria con & y la función recibe un puntero, entonces sí modificamos el original:
*/

#include <iostream>
using namespace std;

void duplicar(int* n) {  
    *n = *n * 2; // modificamos el valor en esa dirección
}

int main() {
    int x = 10;
    duplicar(&x); // pasamos la dirección de x
    cout << "x = " << x << endl; // ahora sí cambia a 20
}

/*
- Pasamos &x (dirección de x).
- La función recibe int* n (un puntero a int).
- Usamos *n para acceder al valor original y cambiarlo
*/
