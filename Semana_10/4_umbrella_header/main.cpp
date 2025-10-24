#include <iostream>
#include "Excepciones.hpp"  // Solo incluimos este umbrella header
using namespace std;

// Funciones de ejemplo que lanzan las excepciones
void retirarDinero(double saldo, double monto) {
    if (monto > saldo)
        throw SaldoInsuficienteException("Error: saldo insuficiente.");
    cout << "Retiro exitoso: " << saldo - monto << endl;
}

void buscarCuenta(bool existe) {
    if (!existe)
        throw CuentaNoEncontradaException("Error: la cuenta no existe.");
    cout << "Cuenta encontrada." << endl;
}

void verificarCuentaActiva(bool activa) {
    if (!activa)
        throw CuentaInactivaException("Error: la cuenta está inactiva.");
    cout << "Cuenta activa." << endl;
}

int main() {
    try {
        retirarDinero(500, 800);
    }
    catch (const SaldoInsuficienteException& e) {
        cout << e.what() << endl;
    }

    try {
        buscarCuenta(false);
    }
    catch (const CuentaNoEncontradaException& e) {
        cout << e.what() << endl;
    }

    try {
        verificarCuentaActiva(false);
    }
    catch (const CuentaInactivaException& e) {
        cout << e.what() << endl;
    }

    cout << "Programa finalizado correctamente." << endl;
}
