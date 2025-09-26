#include <iostream>
#include <string>

class Coche {
public:
    // Constructor con parámetros
    Coche(const std::string& color, int velocidad) {
        color_ = color;
        velocidad_ = velocidad;
    }

    // Constructor por defecto (sin parámetros)
    Coche() {
        color_ = "Blanco";
        velocidad_ = 0;
    }

    // Métodos "get" (accesores) para obtener los valores
    std::string getColor() const {
        return color_;
    }

    int getVelocidad() const {
        return velocidad_;
    }

    // Métodos "set" (mutadores) para modificar los valores
    void setColor(const std::string& nuevoColor) {
        color_ = nuevoColor;
    }

    void setVelocidad(int nuevaVelocidad) {
        if (nuevaVelocidad >= 0) { // Validación de datos
            velocidad_ = nuevaVelocidad;
        }
    }

private:
    std::string color_;
    int velocidad_;
};

int main() {
    // Se usa el constructor con parámetros
    Coche miCoche("Rojo", 80);
    std::cout << "Mi coche es de color " << miCoche.getColor() 
        << " y va a " << miCoche.getVelocidad() << " km/h." << std::endl;

    // Usamos los métodos "set" para cambiar el estado del objeto
    miCoche.setColor("Azul");
    miCoche.setVelocidad(120);

    // Se usa el constructor por defecto
    Coche otroCoche;
    std::cout << "El otro coche es de color " << otroCoche.getColor() 
        << " y va a " << otroCoche.getVelocidad() << " km/h." << std::endl;

    return 0;
}