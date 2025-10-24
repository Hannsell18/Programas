#include <iostream>
#include <string>
using namespace std;

// Ejemplo SIN polimorfismo

class Estudiante {
    private:
        string nombre;
        int edad;
        float nota;
    public:
        Estudiante(string n, int e, float nt) {
            nombre = n;
            edad = e;
            nota = nt;
        }
        
        void MostrarEstudiante() {
            cout << "Estudiante: " << nombre 
                << ", Edad: " << edad 
                << ", Nota: " << nota << endl;
        }
};

class Profesor {
    private:
        string nombre;
        int edad;
        string materia;
    public:
        Profesor(string n, int e, string m) {
            nombre = n;
            edad = e;
            materia = m;
        }
        
        void MostrarProfesor() {
            cout << "Profesor: " << nombre 
                << ", Edad: " << edad 
                << ", Materia: " << materia << endl;
        }
};

int main() {
    Estudiante est("Ana", 20, 9.5);
    Profesor prof("Dr. López", 45, "Programación");
    
    est.MostrarEstudiante();
    prof.MostrarProfesor();
    
    return 0;
}