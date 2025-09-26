#include <iostream>
#include <iomanip> // Para formatear la salida decimal

double calcularImpuesto(double precio, double tasa) {
    return precio * tasa;
}

double calcularTotal(double precio, double impuesto) {
    return precio + impuesto;
}

int main() {
    double precioBase, tasaImpuesto;
    
    std::cout << "Ingrese el precio base del producto: ";
    std::cin >> precioBase;
    
    std::cout << "Ingrese la tasa de impuesto (ej. 0.13 para 13%): ";
    std::cin >> tasaImpuesto;
    
    double montoImpuesto = calcularImpuesto(precioBase, tasaImpuesto);
    double precioTotal = calcularTotal(precioBase, montoImpuesto);
    
    // Mostramos un 'recibo' formateado
    // Fix: Le dice a cout que imprima los números en formato de punto fijo. 
    // setprecision: Este es el que define cuántos dígitos después del punto decimal se mostrarán. 
    //    Al establecerlo en 2, cout redondeará los números para que solo tengan dos decimales.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Recibo de Compra ---" << std::endl;
    std::cout << "Precio base: $" << precioBase << std::endl;
    std::cout << "Impuesto:    $" << montoImpuesto << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Total a pagar: $" << precioTotal << std::endl;
    
    // Se revierte con std::defaultfloat y std::setprecision(6)
    return 0;
}