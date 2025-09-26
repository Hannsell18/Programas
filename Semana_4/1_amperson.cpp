/* El operador & (dirección de memoria)
Sirve para obtener la dirección de memoria de una variable.
Toda variable está guardada en algún lugar de la RAM, y con & podemos ver dónde.
*/
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    cout << "Valor de x: " << x << endl;
    cout << "Direccion de x: " << *(&x)<< endl;
    return 0;
}