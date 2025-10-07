#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> numeros = {10, 20, 30, 40, 50};
    // Crear un iterador
    vector<int>::iterator it;
    // Posicionarlo al inicio
    it = numeros.begin();
    // Ver el elemento actual
    cout << *it << endl;  // Imprime: 10
    // Avanzar al siguiente
    ++it;
    cout << *it << endl;  // Imprime: 20
    // Avanzar otra vez
    ++it;
    cout << *it << endl;  // Imprime: 30
}