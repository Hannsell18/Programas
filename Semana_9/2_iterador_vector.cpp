#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> numeros = {10, 20, 30, 40, 50};
    vector<int>::iterator it = numeros.begin();

    while(it != numeros.end()) {
        cout << *it << " ";
        ++it;
    }
    // Imprime: 10 20 30 40 
}