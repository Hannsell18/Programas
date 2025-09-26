#include <iostream>
using namespace std;

int main() {
    int altura;
    std::cout << "Ingrese el altura del cuadrado: ";
    std::cin >> altura;

    for (int fila = 0; fila < altura; fila++) {
        for (int columna = 0; columna < fila+1; columna++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}




/*
int main() {
    int altura = 0;
    std::cout <<"Digite la altura de la piramide";
    std::cin >> altura;
    for(int i = 0; i < altura; i++){
        std::cout << "*"<< endl;
        for(int y = 0; (y < i+1 && i != altura-1); y++){
            std::cout << "*";
        }
    }
}
*/