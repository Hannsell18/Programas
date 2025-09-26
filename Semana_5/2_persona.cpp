#include <iostream>
#include <string>
using namespace std;

// Clase base
class Persona {
    protected:
        string nombre;
        int edad;

    public:
        // Constructor usando asignación dentro del cuerpo
        Persona(string n, int e) {
            nombre = n;
            edad = e;
        }

        void mostrar() const {
            cout << "Nombre: " << nombre << ", Edad: " << edad;
        }
};

// Clase derivada Cliente
class Cliente : public Persona {
    public:
        Cliente(string n, int e) : Persona(n, e) {}

        int funcion() const {
            return 0; // siempre 0 para clientes
        }

        void mostrar() const {
            Persona::mostrar();
            cout << ", Función: " << funcion() << " (Cliente)" << endl;
        }

        
};

// Clase derivada Empleado
class Empleado : public Persona {
    private:
        int tipo; // 1 = Bodeguero, 2 = Cajero, 3 = Supervisor

    public:
        Empleado(string n, int e, int t) : Persona(n, e) {
            tipo = t; // asignación dentro del cuerpo
        }

        int funcion() const {
            return tipo;
        }

        void mostrar() const {
            Persona::mostrar();
            string nombreTipo;
            switch(tipo) {
                case 1: 
                    nombreTipo = "Bodeguero"; 
                    break;
                case 2: 
                    nombreTipo = "Cajero"; 
                    break;
                case 3: 
                    nombreTipo = "Supervisor"; 
                    break;
                default: 
                    nombreTipo = "Desconocido";
            }
            cout << ", Función: " << tipo << " (" << nombreTipo << ")" << endl;
        }
};

// Main
int main() {
    Cliente c1("Ana", 28);
    Empleado e1("Juan", 35, 2); // Cajero

    cout << "Cliente: ";
    c1.mostrar();

    cout << "Empleado: ";
    e1.mostrar();

    return 0;
}
