#include <iostream>

int main() {
    int opcion;

    do {
        std::cout << "--- MENU PRINCIPAL ---" << std::endl;
        std::cout << "1. Jugar" << std::endl;
        std::cout << "2. Opciones" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
    } while (opcion != 3);

    std::cout << "Saliendo del programa. ¡Hasta pronto!" << std::endl;

    return 0;
}