#include <iostream>
#include <stdexcept>
#include <fstream>

void leerArchivo(const std::string& nombre) {
    std::ifstream archivo(nombre);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo");
    }
    std::cout << "Archivo abierto correctamente" << std::endl;
}

int main() {
    try {
        leerArchivo("datos.txt");      // Si existe: OK
        leerArchivo("noexiste.txt");   // Si no existe: ERROR
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*
Salida (si noexiste.txt no existe):**
Error: No se pudo abrir el archivo
*/