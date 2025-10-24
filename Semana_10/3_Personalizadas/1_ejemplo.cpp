#include <iostream>
#include <exception>
#include <string>
using namespace std;

class SaldoInsuficienteException : public exception {
    private:
        string mensaje;

    public:
        // Constructor
        SaldoInsuficienteException(string msg) {
            mensaje = msg;
        }
        // Método what() que devuelve el mensaje de error
        const char* what() const noexcept override {
            return mensaje.c_str();
        }
};

void retirarDinero(double saldo, double monto) {
    if (monto > saldo)
        throw SaldoInsuficienteException("Error: saldo insuficiente para realizar la transaccion.");
    cout << "Retiro exitoso. Saldo restante: " << saldo - monto << endl;
}

int main() {
    try {
        double saldo = 500.0;
        double monto = 800.0;
        retirarDinero(saldo, monto);
    }
    catch (const SaldoInsuficienteException& e) {
        cout << e.what() << endl;
    }

    cout << "Programa finalizado correctamente." << endl;
}
