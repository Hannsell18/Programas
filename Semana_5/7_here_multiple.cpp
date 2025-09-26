#include <iostream>

// Clase base 1: Define el comportamiento de volar
class Volador {
    public:
        void volar() {
            std::cout << "Estoy volando!\n";
        }
};

// Clase base 2: Define el comportamiento de nadar
class Nadador {
    public:
        void nadar() {
            std::cout << "Estoy nadando!\n";
        }
};

// Clase derivada: Hereda públicamente de ambas clases base
class Pato : public Volador, public Nadador {
    // El Pato hereda los métodos volar() y nadar()
    // y puede tener sus propios métodos y atributos.
    public:
        void graznar() {
            std::cout << "¡Cuac, cuac!\n";
        }
};

int main() {
    // Creamos un objeto Pato
    Pato miPato;

    // Llamamos a los métodos heredados
    miPato.volar(); // Método heredado de Volador
    miPato.nadar(); // Método heredado de Nadador
    
    // Llamamos a un método propio de la clase Pato
    miPato.graznar();

    return 0;
}