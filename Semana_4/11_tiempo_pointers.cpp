#include <iostream>

class Tiempo {
    public:
        // Constructor: Se llama automáticamente cuando se crea el objeto.
        Tiempo() {
            std::cout << "Se ha creado un objeto Tiempo." << std::endl;
        }

        // Destructor: Se llama automáticamente cuando se elimina el objeto.
        ~Tiempo() {
            std::cout << "Se ha destruido el objeto Tiempo." << std::endl;
        }

        void mostrarMensaje() {
            std::cout << "Hola desde el objeto Tiempo!" << std::endl;
        }
        void mostrarDespedida() {
            std::cout << "Adiooos" << std::endl;
        }
};

int main() {
    std::cout << "Inicio del programa." << std::endl;

    // 1. Declaración del puntero.
    Tiempo* tiempoPtr; 

    // 2. Asignación dinámica:
    //    - Se reserva memoria en el 'heap' para un objeto Tiempo.
    //    - Se llama al constructor de Tiempo.
    //    - La dirección de memoria se asigna a tiempoPtr.
    tiempoPtr = new Tiempo;
    
    // 3. Uso del objeto a través del puntero.
    //    Se usa el operador -> para acceder a los miembros.
    tiempoPtr->mostrarMensaje();
    tiempoPtr->mostrarDespedida();
    
    // 4. Liberación de memoria.
    //    - 'delete' libera la memoria.
    //    - Esto llama al destructor de Tiempo automáticamente.
    delete tiempoPtr;

    // 5. Buena práctica: Asignar nullptr para evitar 'dangling pointers'.
    tiempoPtr = nullptr;
    
    std::cout << "Fin del programa." << std::endl;

    return 0;
}