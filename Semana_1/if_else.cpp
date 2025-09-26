#include <iostream>

int main() {
    int dia = 2;

    if (dia == 1) {
        std::cout << "Lunes" << std::endl;
    } else if (dia == 2) {
        std::cout << "Martes" << std::endl;
    } else if (dia == 3) {
        std::cout << "Miercoles" << std::endl;
    } else {
        std::cout << "Dia no valido." << std::endl;
    }

    return 0;
}