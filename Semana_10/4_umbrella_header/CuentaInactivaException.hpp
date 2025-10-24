#ifndef CUENTA_INACTIVA_EXCEPTION_HPP
#define CUENTA_INACTIVA_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class CuentaInactivaException : public exception {
private:
    string mensaje;

public:
    CuentaInactivaException(const string& msg) { mensaje = msg; }
    const char* what() const noexcept override { return mensaje.c_str(); }
};

#endif // CUENTA_INACTIVA_EXCEPTION_HPP
