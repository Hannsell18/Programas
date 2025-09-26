/*
Matriz 3x3 con enteros: 

[  1   2   3  ]
[  4   5   6  ]
[  7   8   9  ]

*/

#include <iostream>
using namespace std;

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "La matriz es:" << endl;

    for (int i = 0; i < 3; i++) {         // recorrer filas
        for (int j = 0; j < 3; j++) {     // recorrer columnas
            cout << matriz[i][j] << " ";
        }
        cout << endl; // salto de línea por fila
    }

    return 0;
}

/*
int main() {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int filas = sizeof(matriz) / sizeof(matriz[0]);
    int columnas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    cout << "Filas: " << filas << endl;
    cout << "Columnas: " << columnas << endl;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

*/
