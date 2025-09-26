#include <iostream>
using namespace std;

int main() {
    int A[2][2], B[2][2], Suma[2][2];

    cout << "Ingresa los valores de la matriz A (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "Ingresa los valores de la matriz B (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    // Sumar matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            Suma[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "La suma de A + B es:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << Suma[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
