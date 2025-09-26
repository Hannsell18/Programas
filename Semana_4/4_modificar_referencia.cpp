/*Modificar la dirección que guarda el puntero

Un puntero también se puede "mover" para apuntar a otra variable:
*/

#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 15;
    int* p = &a;   // p apunta a a

    cout << "p apunta a a: " << *p << endl; // 5

    p = &b;        // ahora p apunta a b
    *p = 30;       // modificamos b usando p

    cout << "a = " << a << endl; // 5 (no cambió)
    cout << "b = " << b << endl; // 30 (sí cambió)
    return 0;
}