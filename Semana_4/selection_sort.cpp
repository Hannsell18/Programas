
#include <iostream>
using namespace std;

void selectionSort(int* arr, int size) {
    // Ciclo principal que recorre todo el array, excepto el último elemento.
    // Con cada iteración 'i', movemos el elemento más pequeño a la posición 'i'.
    for(int i = 0; i < size-1; i++) {
        // Asumimos que el elemento en la posición actual 'i' es el más pequeño.
        int minIndex = i;

        // Bucle anidado para buscar el elemento más pequeño en el resto del array.
        // Comienza en 'i+1' para no comparar con los elementos ya ordenados.
        for(int j = i + 1; j < size; j++) {
            
            // Comparamos el valor del elemento actual 'j' con el mínimo que hemos encontrado.
            // *(arr + j) es la forma de puntero para arr[j].
            if(*(arr + j) < *(arr + minIndex)) {
                // Si encontramos un valor más pequeño, actualizamos el índice.
                minIndex = j;
            }
        }
        
        // --- Intercambio ---
        // Después de recorrer la sublista, si el índice del mínimo es diferente de 'i',
        // significa que encontramos un elemento más pequeño, así que lo intercambiamos.

        // Guardamos temporalmente el valor del elemento actual en 'i'.
        int temp = *(arr + i);
        // Ponemos el elemento más pequeño que encontramos en la posición 'i'.
        *(arr + i) = *(arr + minIndex);
        // Colocamos el valor temporal (el que estaba en 'i') en la posición donde estaba el mínimo.
        *(arr + minIndex) = temp;
    }
}

int main() {
    int numeros[5] = {64, 25, 12, 22, 11};

    cout << "Array original: ";
    for(int i = 0; i < 5; i++) cout << numeros[i] << " ";
    cout << endl;

    selectionSort(numeros, 5); // paso por referencia (puntero al primer elemento)

    cout << "Array ordenado: ";
    for(int i = 0; i < 5; i++) cout << numeros[i] << " ";
    cout << endl;

    return 0;
}
