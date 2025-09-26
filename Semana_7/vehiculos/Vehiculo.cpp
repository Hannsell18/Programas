#include "Vehiculo.hpp"

// Implementación de Vehiculo
Vehiculo::Vehiculo(const string& marca) : marca(marca) {}

void Vehiculo::mostrarInfo() const {
    cout << "Marca: " << marca << endl;
}

// Implementación de VehiculoElectrico
VehiculoElectrico::VehiculoElectrico(const string& marca, int capacidadBateria)
    : Vehiculo(marca), capacidadBateria(capacidadBateria) {}

void VehiculoElectrico::mostrarInfo() const {
    Vehiculo::mostrarInfo();
    cout << "Capacidad de Bateria: " << capacidadBateria << " kWh" << endl;
}

// Implementación de VehiculoCombustion
VehiculoCombustion::VehiculoCombustion(const string& marca, double capacidadTanque)
    : Vehiculo(marca), capacidadTanque(capacidadTanque) {}

void VehiculoCombustion::mostrarInfo() const {
    Vehiculo::mostrarInfo();
    cout << "Capacidad del Tanque: " << capacidadTanque << " L" << endl;
}

// Implementación de VehiculoHibrido
VehiculoHibrido::VehiculoHibrido(const string& marca, int capacidadBateria, double capacidadTanque)
    : Vehiculo(marca),
      VehiculoElectrico(marca, capacidadBateria),
      VehiculoCombustion(marca, capacidadTanque) {}

void VehiculoHibrido::mostrarInfo() const {
    cout << "=== Vehículo Híbrido ===" << endl;
    cout << "Marca: " << marca << endl;
    cout << "Capacidad de Batería: " << capacidadBateria << " kWh" << endl;
    cout << "Capacidad del Tanque: " << capacidadTanque << " L" << endl;
}
