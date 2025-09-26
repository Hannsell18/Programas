#include <iostream>

class Punto {
    public:
        // Constructor con parámetros
        Punto(double x, double y) {
            // Inicializamos los atributos directamente
            x = x;
            y = y;
        }

        // Método público para mostrar la posición
        void mostrarPosicion() const {
            std::cout << "Posición: (" << x << ", " << y << ")" << std::endl;
        }

    private:
        // Atributos privados
        double x;
        double y;
};

int main() {
    // Se crea un objeto 'Punto' y se inicializa con el constructor.
    Punto p(5.0, 10.0);
    p.mostrarPosicion(); // Salida: Posición: (5, 10)
    return 0;
}