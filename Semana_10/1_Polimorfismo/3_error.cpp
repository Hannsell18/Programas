int main() {
    // Guardar estudiantes Y profesores juntos
    Persona* personas[3];
    
    personas[0] = new Estudiante("Ana", 20, 9.5);
    personas[1] = new Profesor("Dr. López", 45, "Programación");
    personas[2] = new Estudiante("Carlos", 22, 8.0);
    
    // Mostrar todos
    for(int i = 0; i < 3; i++) {
        personas[i]->Mostrar();
    }
    
    // Liberar memoria
    for(int i = 0; i < 3; i++) {
        delete personas[i];
    }
    
    return 0;
}