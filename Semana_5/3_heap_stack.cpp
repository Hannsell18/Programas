#include <iostream>
#include <string>

class Gato {
    public:
        std::string nombre;

        // Constructor: Se llama cuando se crea un objeto Gato.
        Gato(const std::string& n) {
            nombre = n;
            std::cout << "Gato " << nombre << " ha sido creado." << std::endl;
        }

        // Destructor: Se llama cuando un objeto Gato es destruido.
        ~Gato() {
            std::cout << "Gato " << nombre << " ha sido destruido." << std::endl;
        }
};

// Función para crear un objeto en el stack (invocación normal)
void crearGatoStack() {
    std::cout << "\n--- Creando un objeto en el stack ---\n";
    // El objeto se crea aquí y se destruye automáticamente al salir de la función
    Gato gatoStack("Whiskers"); 
    std::cout << "Saliendo de la funcion crearGatoStack.\n";
}

// Función para crear un objeto en el heap (con new)
Gato* crearGatoHeap() {
    std::cout << "\n--- Creando un objeto en el heap ---\n";
    // El objeto se crea aquí, pero se devuelve su puntero.
    // El objeto existirá hasta que se llame a delete.
    Gato* gatoHeap = new Gato("Pelusa");
    std::cout << "Saliendo de la funcion crearGatoHeap.\n";
    return gatoHeap; // Devolvemos el puntero
}

int main() {
    // Demostración de objeto en el stack
    crearGatoStack();
    std::cout << "El objeto del stack ya no existe aqui.\n";

    std::cout << "------------------------------------------\n";

    // Demostración de objeto en el heap
    Gato* miGato = crearGatoHeap();
    std::cout << "El objeto del heap todavia existe en main.\n";

    // Se puede usar el objeto miGato aqui 
    std::cout << "El nombre del gato del heap es: " << miGato->nombre << std::endl;

    // Se libera la memoria del objeto del heap manualmente.
    std::cout << "\n--- Destruyendo el objeto del heap ---\n";
    delete miGato;
    miGato = nullptr; // Buena práctica para evitar punteros colgantes
    
    std::cout << "Saliendo de main. Todo el programa termina.\n";

    return 0;
}