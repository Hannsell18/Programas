/*
En la herencia privada, los miembros public y protected del padre se convierten en 
private en el hijo. Esto es útil para una relación de "implementación", no de "es un".
*/

#include <iostream>
#include <string>

class Motor { // Clase Padre
    public:
        void arrancar() {
            std::cout << "Motor arrancando." << std::endl;
        }
    protected:
        void apagar() {
            std::cout << "Motor apagandose." << std::endl;
        }
};

class Scooter : private Motor { // Herencia privada
public:
    void conducir() {
        // arrancar() y apagar() son miembros privados ahora,
        // pero podemos usarlos dentro de la clase Scooter.
        arrancar();
        std::cout << "Conduciendo..." << std::endl;
        apagar();
    }
};

int main() {
    Scooter miScooter;
    miScooter.conducir();
    // miScooter.arrancar(); // ERROR: arrancar() es un miembro privado en Scooter.
    // miScooter.apagar(); // ERROR: apagar() es un miembro privado en Scooter.
    return 0;
}

/*
Motor arrancando., Conduciendo... y Motor apagandose.. Los métodos de la clase Motor 
se usan internamente para implementar la funcionalidad de Scooter, pero están 
completamente ocultos para el mundo exterior.
 */