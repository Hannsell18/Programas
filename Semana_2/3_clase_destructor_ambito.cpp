#include <iostream>
#include <string>

class Recurso {
public:
    // Constructor con parámetros
    Recurso(const std::string& nombre) {
        nombre_ = nombre;
        // Simulamos la adquisición de un recurso (ej. memoria, archivo)
        std::cout << "Recurso '" << nombre_ << "' adquirido." << std::endl;
    }

    // Destructor
    ~Recurso() {
        // Se ejecuta automáticamente al final de la vida del objeto
        std::cout << "Recurso '" << nombre_ << "' liberado." << std::endl;
    }

private:
    std::string nombre_;
};

// La función main crea y destruye objetos
int main() {
    std::cout << "Inicio del programa." << std::endl;
    
    // Se crea un objeto 'r1' en este ámbito
    Recurso r1("Archivo de configuración");
    {
        // Se crea un nuevo ámbito
        std::cout << "Dentro de un nuevo ámbito." << std::endl;
        Recurso r2("Conexión de red");
        std::cout << "Saliendo del nuevo ámbito." << std::endl;
    } // Aquí se destruye 'r2'

    std::cout << "De vuelta en el ámbito principal." << std::endl;
    
    return 0;
} // Aquí se destruye 'r1'