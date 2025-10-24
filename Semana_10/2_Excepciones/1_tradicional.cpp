#include <iostream>
#include <string>
using namespace std;

// Forma antigua: usando códigos de error
int dividir(int a, int b, double* resultado) {
    if (b == 0) {
        return -1;  // Código de error
    }
    *resultado = a / b;
    return 0;  // Éxito
}

int main() {
    double resultado;
    int codigo = dividir(10, 0, &resultado);
    
    if (codigo == -1) {
        std::cout << "Error: division por cero" << std::endl;
    } else {
        std::cout << "Resultado: " << resultado << std::endl;
    }
}