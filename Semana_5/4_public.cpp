/*
Herencia Pública (public)
Mantiene el nivel de acceso de los miembros del padre. Es el tipo más común 
y modela una relación de "es un".
*/

#include <iostream>
#include <string>

class Animal { // Clase Padre
    private:
        std::string nombre; // No accesible para la clase hija
    protected:
        void hacerSonido() { 
            std::cout << "El animal hace un sonido." << std::endl;
        }
    public:
        void setNombre(const std::string& n) {
            nombre = n;
        }
        std::string getNombre() {
            return nombre;
        }
};

class Perro : public Animal { // Herencia pública
    public:
        void ladrar() {
            std::cout << getNombre() << " ladra: ¡Guau!" << std::endl;
            hacerSonido(); // Acceso a un miembro protected del padre
        }
};

int main() {
    Perro miPerro;
    miPerro.setNombre("Fido"); // Se puede acceder a un miembro public del padre
    miPerro.ladrar(); 
    // miPerro.hacerSonido(); // ERROR: No se puede acceder, porque es protected en la clase hija
    return 0;
}

/*
Fido ladra: ¡Guau! y El animal hace un sonido..
El método setNombre del padre es public y accesible desde fuera de la clase Perro.
*/