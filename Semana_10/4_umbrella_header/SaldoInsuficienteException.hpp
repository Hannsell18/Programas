#ifndef SALDO_INSUFICIENTE_EXCEPTION_HPP
#define SALDO_INSUFICIENTE_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class SaldoInsuficienteException : public exception {
private:
    string mensaje;

public:
    SaldoInsuficienteException(const string& msg) { mensaje = msg; }
    const char* what() const noexcept override { return mensaje.c_str(); }
};

#endif // SALDO_INSUFICIENTE_EXCEPTION_HPP
