#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void sonido() =0;
        /*
        Un destructor virtual asegura que primero se destruya el objeto derivado, 
        luego la clase base. Es decir, declarar un destructor como virtual garantiza que, al borrar 
        un objeto a través de un puntero a la clase base, se llamen correctamente los destructores 
        de todas las clases de la jerarquía, evitando fugas de memoria y liberando recursos de manera 
        segura.
        */
        virtual ~Animal() {
            cout << "Destructor Animal\n";
        }
};

class Perro : public Animal {
    public:
        void sonido() override { // buena práctica usar override
            cout << "Guau guau" << endl;
        }
};

int main() {
    Animal* a = new Perro();
    a->sonido(); // Llama Perro::sonido() por enlace dinámico
    delete a;  // Llama destructores de Perro y luego Animal
}
