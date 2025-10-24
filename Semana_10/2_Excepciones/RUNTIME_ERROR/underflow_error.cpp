#include <iostream>
#include <stdexcept>

void restarSaldo(double& saldo, double monto) {
    if (saldo - monto < 0) {
        throw std::underflow_error("El saldo quedaría negativo");
    }
    saldo -= monto;
}

int main() {
    try {
        double saldo = 100.0;
        
        restarSaldo(saldo, 50.0);   // OK
        std::cout << "Saldo: $" << saldo << std::endl;
        
        restarSaldo(saldo, 80.0);   // ERROR
    }
    catch (const std::underflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*
Salida:
Saldo: $50
Error: El saldo quedaría negativo
*/