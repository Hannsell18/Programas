#ifndef PUNTO_HPP
#define PUNTO_HPP

class Punto {
    public:
        int x;
        int y;

        // Constructor
        Punto(int x = 0, int y = 0);

        // Sobrecarga del operador +
        // miPunto + otroPunto
        Punto operator+(const Punto& otroPunto);

        // miPunto + 5
        Punto operator+(int numero);
        // 5 + miPunto
        friend Punto operator+(int numero, const Punto& puntoSumar);
        
};

#endif
