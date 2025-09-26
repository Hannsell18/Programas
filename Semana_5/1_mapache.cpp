#include <iostream>
using namespace std;

class Mapache {
    protected:
        int quesoAhorrado; // protected: accesible por las clases derivadas

    public:
        Mapache() {
            quesoAhorrado = 100; // inicialización del atributo
        }
};

class Junior : public Mapache { // Junior hereda de Mapache de forma PUBLICA
    public:
        void mostrarQueso() {
            std::cout << "Tengo acceso al queso de la familia: " << quesoAhorrado << " unidades.\n";
        }
};

int main() {
    Junior j;
    j.mostrarQueso(); // Imprime: Tengo acceso al queso de la familia: 100 unidades.
    return 0;
}
