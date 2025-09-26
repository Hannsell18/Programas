/* Modificar el dato al que apunta (contenido)

Si tienes un puntero apuntando a una variable, con * accedes al valor y lo puedes cambiar:
*/
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;   // p apunta a x

    *p = 20;       // modificamos el valor de x a través del puntero

    cout << "x = " << x << endl;   // imprime 20
    cout << "*p = " << *p << endl; // imprime 20
    return 0;
}


// *p = 20; significa:
// "vaya a la dirección que guarda p y guarda ahí el valor 20".