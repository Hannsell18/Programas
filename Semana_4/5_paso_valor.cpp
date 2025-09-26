/*
Paso por valor (lo normal)
Cuando pasas una variable normal a una función, en realidad pasa una copia:
*/

#include <iostream>
using namespace std;

void duplicar(int n) {  
    n = n * 2; // modifica la copia
}

int main() {
    int x = 10;
    duplicar(x);
    cout << "x = " << x << endl; // sigue siendo 10
}
