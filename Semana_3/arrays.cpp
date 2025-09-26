#include <iostream>
using namespace std;

int main() {
    int notas[5] = {85, 90, 70, 95, 100};

    cout << "Notas del estudiante:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nota " << i << ": " << notas[i] << endl;
    }

    return 0;
}
/*
Resumen: 
    - Array = conjunto de datos del mismo tipo.
    - Índices van de 0 a tamaño-1.
    - Se usa para manejar muchos datos del mismo tipo más fácilmente.
*/


// Como puedo obtener el tamanio automaticamente
#include <iostream>
using namespace std;

int main() {
    int notas[] = {85, 90, 70, 95, 100};
    // sizeof(notas) = 4 bytes * 5 = 20
    // sizeof(notas[0] = 4 bytes
    int limite = sizeof(notas) / sizeof(notas[0]);

    cout << "El array tiene " << limite << " elementos." << endl;

    for (int i = 0; i < limite; i++) {
        cout << "Nota " << i << ": " << notas[i] << endl;
    }

    return 0;
}
