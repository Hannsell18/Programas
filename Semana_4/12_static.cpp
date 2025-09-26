#include <iostream>

void contarLlamadas() {
    // Esta variable se inicializa solo una vez
    static int contador = 0; 
    contador++;
    std::cout << "Esta funcion ha sido llamada " << contador << " veces." << std::endl;
}

int main() {
    contarLlamadas(); // 1
    contarLlamadas(); // 2
    contarLlamadas(); // 3
    return 0;
}