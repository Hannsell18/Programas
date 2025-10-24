#include <iostream>
#include <string>
using namespace std;

class Persona {
    protected:  
        string nombre;
        int edad;
    
    public:
        // Constructor de Persona
        Persona(string n, int e) {
            nombre = n;
            edad = e;
        }
        
        // Método para mostrar datos básicos
        virtual void Mostrar() {
            cout << "Nombre: " << nombre << ", Edad: " << edad;
        }
};


class Estudiante : public Persona {
    private:
        float nota;
        
    public:
        // Constructor que llama al constructor de Persona
        Estudiante(string n, int e, float nt) : Persona(n, e) {
            nota = nt;
        }
        
        void Mostrar() {
            Persona::Mostrar();  // Llamamos al Mostrar de Persona
            cout << ", Nota: " << nota << endl;
        }
};

class Profesor : public Persona {
    private:
        string materia;
        
    public:
        Profesor(string n, int e, string m) : Persona(n, e) {
            materia = m;
        }
        
        void Mostrar() {
            Persona::Mostrar();
            cout << ", Materia: " << materia << endl;
        }
};

int main() {
    Persona* personas[3];
    
    personas[0] = new Estudiante("Ana", 20, 9.5);
    personas[1] = new Profesor("Dr. Lopez", 45, "Programacion");
    personas[2] = new Estudiante("Carlos", 22, 8.0);
    
    for(int i = 0; i < 3; i++) {
        personas[i]->Mostrar();  // ← Mismo código
    }
    
    for(int i = 0; i < 3; i++) {
        delete personas[i];
    }
    
    return 0;
}