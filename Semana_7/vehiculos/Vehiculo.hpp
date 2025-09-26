#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <iostream>
#include <string>
using namespace std;

// Clase base
class Vehiculo {
public:
    string marca;

    Vehiculo(const string& marca);
    virtual void mostrarInfo() const;
};

// Clase intermedia: Vehículo Eléctrico
class VehiculoElectrico : virtual public Vehiculo {
public:
    int capacidadBateria;

    VehiculoElectrico(const string& marca, int capacidadBateria);
    void mostrarInfo() const override;
};

// Clase intermedia: Vehículo de Combustión
class VehiculoCombustion : virtual public Vehiculo {
public:
    double capacidadTanque;

    VehiculoCombustion(const string& marca, double capacidadTanque);
    void mostrarInfo() const override;
};

// Clase derivada: Vehículo Híbrido
class VehiculoHibrido : public VehiculoElectrico, public VehiculoCombustion {
public:
    VehiculoHibrido(const string& marca, int capacidadBateria, double capacidadTanque);
    void mostrarInfo() const override;
};

#endif
