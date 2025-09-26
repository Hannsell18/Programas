/*
Paso por referencia con & (sintaxis moderna de C++)

C++ tiene una forma más directa: referencias (& en parámetros).
Esto no usa punteros explícitos, pero hace lo mismo:
*/

#include <iostream>
using namespace std;

void duplicar(int& n) {  
    n = n * 2; // referencia directa a la variable original
}

int main() {
    int x = 10;
    duplicar(x); // no hace falta &
    cout << "x = " << x << endl; // cambia a 20
}

// Más limpio y usado en código moderno, pero internamente se basa en punteros.