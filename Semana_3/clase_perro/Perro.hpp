#ifndef PERRO_HPP
#define PERRO_HPP

#include <string>

class Perro {
    public:
        Perro(const std::string nombre, int edad);
        // Especifica
        void ladrar();
        // GET
        int get_edad() const;
        std::string get_nombre() const;

        // SET
        void set_edad(int edad);
        void set_nombre(const std::string& nombre);
        

    private:
        std::string nombre_;
        int edad_;

};

#endif // PERRO_HPP