/*Pasar un array a una función con punteros

Cuando pasas un array a una función, realmente pasas la dirección de su primer elemento.
Esto significa que puedes modificar el array dentro de la función.
*/

#include <iostream>
using namespace std;

void doblarElementos(int* numeros, int size) {
    for(int i = 0; i < size; i++) {
        numeros[i] *= 2; // arr[i] es lo mismo que *(numeros+i)
    }
}

int main() {
    int numeros[5] = {1, 2, 3, 4, 5};

    doblarElementos(numeros, 5); // se pasa como puntero automáticamente

    for(int i = 0; i < 5; i++) {
        cout << numeros[i] << " "; // ahora 2 4 6 8 10
    }

    return 0;
}

// La función recibe int* arr, pero se puede usar como si fuera un array.