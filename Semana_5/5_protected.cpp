/*
Herencia Protegida (protected)
En la herencia protegida, los miembros public y protected del padre se vuelven protected
en el hijo, haciéndolos inaccesibles desde fuera de la jerarquía de herencia.
*/

#include <iostream>
#include <string>

class Computadora { // Clase Padre
    protected:
        std::string nombreProcesador;
    public:
        void encender() {
            std::cout << "Computadora encendida." << std::endl;
        }
};

class Laptop : protected Computadora { // Herencia protegida
    public:
        void mostrarInfo() {
            // Miembro público del padre ahora es protegido.
            // Lo podemos llamar desde aquí, pero no desde main().
            encender();
            nombreProcesador = "Intel i7"; // Acceso a un miembro protected del padre
            std::cout << "Procesador: " << nombreProcesador << std::endl;
        }
};

int main() {
    Laptop miLaptop;
    // miLaptop.encender(); // ERROR: encender() ahora es un miembro protegido en Laptop.
    miLaptop.mostrarInfo();
    
    return 0;
}

/*
Computadora encendida. y Procesador: Intel i7. El método encender() se puede llamar 
desde la clase Laptop, pero no desde main(), lo que muestra que su nivel de acceso ha cambiado a 
protected.
*/