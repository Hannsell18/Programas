#include <iostream>
#include <string>
using namespace std;

// SOBRECARGA DE FUNCIONES (Function Overloading)
// Permite tener múltiples funciones con el MISMO NOMBRE
// pero con DIFERENTES PARÁMETROS (cantidad o tipos)

class Calculadora {
    public:
        // Sobrecarga #1: suma de dos enteros
        int sumar(int a, int b) {
            cout << "Sumando dos enteros..." << endl;
            return a + b;
        }
        
        // Sobrecarga #2: suma de tres enteros
        int sumar(int a, int b, int c) {
            cout << "Sumando tres enteros..." << endl;
            return a + b + c;
        }
        
        // Sobrecarga #3: suma de dos decimales
        double sumar(double a, double b) {
            cout << "Sumando dos decimales..." << endl;
            return a + b;
        }
        
        // Sobrecarga #4: concatenar strings
        string sumar(string a, string b) {
            cout << "Concatenando strings..." << endl;
            return a + " " + b;
        }
};

class Figura {
    public:
        // Sobrecarga: calcular área de diferentes formas
        
        // Área de un cuadrado (un parámetro)
        double calcularArea(double lado) {
            cout << "Calculando área del cuadrado..." << endl;
            return lado * lado;
        }
        
        // Área de un rectángulo (dos parámetros)
        double calcularArea(double base, double altura) {
            cout << "Calculando área del rectángulo..." << endl;
            return base * altura;
        }
        
        // Área de un triángulo (dos parámetros + indicador)
        double calcularArea(double base, double altura, bool esTriangulo) {
            if (esTriangulo) {
                cout << "Calculando área del triángulo..." << endl;
                return (base * altura) / 2;
            }
            return 0;
        }
};

int main() {
    cout << "_____EJEMPLO 1: CALCULADORA_________" << endl;
    Calculadora calc;
    
    // El compilador elige automáticamente la función correcta
    // según los parámetros que pasemos
    cout << "Resultado: " << calc.sumar(5, 3) << endl;
    cout << "Resultado: " << calc.sumar(5, 3, 2) << endl;
    cout << "Resultado: " << calc.sumar(5.5, 3.2) << endl;
    cout << "Resultado: " << calc.sumar("Hola", "Mundo") << endl;
    
    cout << "_____EJEMPLO 2: FIGURAS GEOMÉTRICAS_______" << endl;
    Figura fig;
    
    cout << "Área: " << fig.calcularArea(5.0) << " unidades²" << endl;
    cout << "Área: " << fig.calcularArea(4.0, 6.0) << " unidades²" << endl;
    cout << "Área: " << fig.calcularArea(4.0, 6.0, true) << " unidades²" << endl;
    
    return 0;
}


/* 
    RECORDAR QUE:
    1. ¿Qué es la sobrecarga?
    - Tener múltiples funciones con el mismo nombre
    - Cada una tiene diferentes parámetros
    
    2. ¿Cómo el compilador sabe cuál usar?
    - Por la cantidad de parámetros
    - Por el tipo de parámetros
    - Por el orden de los parámetros
    
    3. Ventajas:
    - Código más limpio y legible
    - Misma operación, diferentes tipos de datos
    - Más intuitivo para el programador
    
    4. IMPORTANTE:
    - NO se puede sobrecargar solo por el tipo de retorno
    - Los parámetros DEBEN ser diferentes
    
    5. Errores comunes:
    - Funciones ambiguas (el compilador no puede decidir)
    - Olvidar que const también diferencia funciones
*/