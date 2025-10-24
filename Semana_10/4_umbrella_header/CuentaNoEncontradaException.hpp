#ifndef CUENTA_NO_ENCONTRADA_EXCEPTION_HPP
#define CUENTA_NO_ENCONTRADA_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class CuentaNoEncontradaException : public exception {
private:
    string mensaje;

public:
    CuentaNoEncontradaException(const string& msg) { mensaje = msg; }
    const char* what() const noexcept override { return mensaje.c_str(); }
};

#endif // CUENTA_NO_ENCONTRADA_EXCEPTION_HPP
