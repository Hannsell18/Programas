#include <iostream>

void invertirNumero(int &numero) {
    int numeroInvertido = 0;
    
    // Bucle para extraer y reorganizar los digitos
    while (numero > 0) {
        int digito = numero % 10; // Extrae el ultimo digito
        numeroInvertido = numeroInvertido * 10 + digito; // Construye el numero invertido
        numero = numero / 10; // Elimina el ultimo digito del numero original
    }
    
    // Asigna el numero invertido a la variable original
    numero = numeroInvertido;
}

int main() {
    int miNumero;

    std::cout << "Ingrese un numero entero para invertirlo: ";
    std::cin >> miNumero;

    std::cout << "Numero original: " << miNumero << std::endl;

    invertirNumero(miNumero); // Se pasa la variable por referencia

    std::cout << "Numero invertido: " << miNumero << std::endl;

    return 0;
}