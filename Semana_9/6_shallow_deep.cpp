#include <iostream>
using namespace std;

class Persona {
private:
    int* edad; // se usa puntero para mostrar la diferencia
public:
    // Constructor
    Persona(int e) {
        edad = new int(e);
    }

    // Constructor de copia (Deep Copy)
    Persona(const Persona& p) {
        // copiamos el valor, no la dirección
        edad = new int(*p.edad);
        cout << "Deep copy constructor llamado\n";
    }

    // Destructor
    ~Persona() {
        delete edad;
    }

    void setEdad(int e) { *edad = e; }
    int getEdad() const { return *edad; }
};

int main() {
    Persona p1(25);

    // Copia superficial (shallow) sería esta:
    // Persona p2 = p1;
    // PERO como implementamos nuestro propio constructor de copia,
    // ahora es una copia profunda (deep copy).

    Persona p2 = p1; // Se llama al constructor de copia (deep copy)
    // p2.setEdad(30);

    cout << "Edad de p1: " << p1.getEdad() << endl; // No cambia
    cout << "Edad de p2: " << p2.getEdad() << endl;

    return 0;
}

/*
RESUMEN
- Shallow copy (copia superficial):
Si no defines un constructor de copia, el compilador copia la dirección del puntero, no el valor.
Entonces, ambos objetos apuntan al mismo bloque de memoria, y si uno se modifica o se destruye, afecta al otro.

- Deep copy (copia profunda):
Al sobrecargar el constructor de copia, creamos un nuevo espacio en memoria y copiamos el valor del puntero original.
Así, cada objeto tiene su propia copia independiente.

*/
