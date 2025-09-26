#include <iostream>
#include <string>

std::string obtenerClasificacionIMC(double peso, double altura) {
    double imc = peso / (altura * altura);
    
    if (imc < 18.5) {
        return "Peso bajo";
    } else if (imc >= 18.5 && imc < 25.0) {
        return "Peso normal";
    } else if (imc >= 25.0 && imc < 30.0) {
        return "Sobrepeso";
    } else {
        return "Obesidad";
    }
}

int main() {
    double peso, altura;
    
    std::cout << "Ingrese su peso en kilogramos: ";
    std::cin >> peso;
    
    std::cout << "Ingrese su altura en metros: ";
    std::cin >> altura;
    
    std::string clasificacion = obtenerClasificacionIMC(peso, altura);
    
    std::cout << "Su clasificacion de IMC es: " << clasificacion << std::endl;
    
    return 0;
}