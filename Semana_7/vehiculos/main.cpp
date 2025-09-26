#include "Vehiculo.hpp"

int main() {
    // Crear un vehículo híbrido
    VehiculoHibrido miHibrido("Toyota Prius", 1000, 45.5);

    // Mostrar la información
    miHibrido.mostrarInfo();

    // Acceso directo a la variable marca (sin ambigüedad gracias a herencia virtual)
    miHibrido.marca = "Nissan";
    cout << "\nDespués de cambiar la marca directamente:\n";
    miHibrido.mostrarInfo();

    return 0;
}
