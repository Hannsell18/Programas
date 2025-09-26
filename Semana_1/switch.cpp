#include <iostream>
using namespace std;

int main() {
    int opcion;
    cout << "Ingrese un numero (1-3): ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Lunes" << endl;
            break;
        case 2:
            cout << "Martes" << endl;
            break;
        case 3:
            cout << "Miercoles" << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
}



