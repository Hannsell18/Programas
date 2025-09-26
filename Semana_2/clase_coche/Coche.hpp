#ifndef COCHE_HPP
#define COCHE_HPP

#include <string>

class Coche {
    public:
        // Constructor con parámetros
        Coche(const std::string& color, int velocidad);

        // Métodos públicos (la interfaz)
        std::string getColor() const;
        int getVelocidad() const;
        void acelerar(int kmh);

    private:
        // Atributos privados
        std::string color_;
        int velocidad_;
};

#endif // COCHE_HPP