#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

// Función 1: División
double dividir(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("División por cero");
    }
    return a / b;
}

// Función 2: Validar edad
void establecerEdad(int edad) {
    if (edad < 0) {
        throw std::invalid_argument("La edad no puede ser negativa");
    }
    if (edad > 150) {
        throw std::invalid_argument("La edad no puede ser mayor a 150");
    }
    std::cout << "Edad establecida: " << edad << " años" << std::endl;
}

// Función 3: Calcular raíz cuadrada
double calcularRaiz(double numero) {
    if (numero < 0) {
        throw std::domain_error("No se puede calcular raíz de número negativo");
    }
    return sqrt(numero);
}

// Función 4: Crear contraseña
void crearPassword(int longitud) {
    if (longitud > 100) {
        throw std::length_error("La contraseña no puede tener más de 100 caracteres");
    }
    if (longitud < 8) {
        throw std::length_error("La contraseña debe tener al menos 8 caracteres");
    }
    std::cout << "Contraseña de " << longitud << " caracteres creada" << std::endl;
}

int main() {
    std::cout << "=== INICIANDO PROGRAMA ===" << std::endl;
    
    // PROBLEMA 1: División por cero
    std::cout << "\n--- Prueba 1: Divisiones ---" << std::endl;
    double resultado1 = dividir(10, 2);
    std::cout << "10 / 2 = " << resultado1 << std::endl;
    
    double resultado2 = dividir(15, 0);  // ¡ERROR!
    std::cout << "15 / 0 = " << resultado2 << std::endl;
    
    
    // PROBLEMA 2: Edad inválida
    std::cout << "\n--- Prueba 2: Validar edades ---" << std::endl;
    establecerEdad(25);
    establecerEdad(-5);      // ¡ERROR!
    establecerEdad(200);     // ¡ERROR!
    
    
    // PROBLEMA 3: Vector fuera de rango
    std::cout << "\n--- Prueba 3: Acceso a vector ---" << std::endl;
    std::vector<int> numeros = {10, 20, 30, 40, 50};
    std::cout << "Elemento en índice 2: " << numeros.at(2) << std::endl;
    std::cout << "Elemento en índice 10: " << numeros.at(10) << std::endl;  // ¡ERROR!
    
    
    // PROBLEMA 4: Conversión de string
    std::cout << "\n--- Prueba 4: Conversión de texto ---" << std::endl;
    std::string texto1 = "123";
    int numero1 = std::stoi(texto1);
    std::cout << "Texto '" << texto1 << "' convertido a: " << numero1 << std::endl;
    
    std::string texto2 = "abc";
    int numero2 = std::stoi(texto2);  // ¡ERROR!
    std::cout << "Texto '" << texto2 << "' convertido a: " << numero2 << std::endl;
    
    
    // PROBLEMA 5: Raíz cuadrada de negativo
    std::cout << "\n--- Prueba 5: Raíces cuadradas ---" << std::endl;
    double raiz1 = calcularRaiz(16);
    std::cout << "Raíz de 16 = " << raiz1 << std::endl;
    
    double raiz2 = calcularRaiz(-25);  // ¡ERROR!
    std::cout << "Raíz de -25 = " << raiz2 << std::endl;
    
    
    // PROBLEMA 6: Longitud de contraseña
    std::cout << "\n--- Prueba 6: Crear contraseñas ---" << std::endl;
    crearPassword(12);
    crearPassword(5);        // ¡ERROR!
    crearPassword(150);      // ¡ERROR!
    
    
    // PROBLEMA 7: String fuera de rango
    std::cout << "\n--- Prueba 7: Acceso a string ---" << std::endl;
    std::string palabra = "Hola";
    std::cout << "Carácter en posición 1: " << palabra.at(1) << std::endl;
    std::cout << "Carácter en posición 20: " << palabra.at(20) << std::endl;  // ¡ERROR!
    
    
    std::cout << "\n=== PROGRAMA TERMINADO EXITOSAMENTE ===" << std::endl;
    return 0;
}