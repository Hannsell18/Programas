#ifndef EXCEPCIONES_HPP
#define EXCEPCIONES_HPP

// Incluye aquí los headers que los estudiantes deben crear
// Cada header debe definir una clase de excepción personalizada que herede de std::exception
#include "SaldoInsuficienteException.hpp"    // Maneja retiros mayores al saldo
#include "CuentaNoEncontradaException.hpp"   // Maneja búsqueda de cuentas inexistentes
#include "CuentaInactivaException.hpp"       // Maneja cuentas inactivas
#include "DivisorCeroException.hpp"          // Maneja divisiones por cero

#endif // EXCEPCIONES_HPP
