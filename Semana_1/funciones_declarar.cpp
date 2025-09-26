#include <iostream>
#include <string>

// --- DECLARACIÓN DE FUNCIONES ---
// (No es estrictamente necesario si se definen antes de main,
// pero es una buena práctica para proyectos grandes)
void saludar();
int sumar(int a, int b);
std::string crearMensaje(std::string nombre);


// --- FUNCION PRINCIPAL (main) ---
int main() {
    // 1. Invocación de una función sin retorno y sin parámetros
    saludar();

    // 2. Invocación de una función con retorno y con parámetros
    int resultadoSuma = sumar(10, 5); // Los valores 10 y 5 son los argumentos
    std::cout << "El resultado de la suma es: " << resultadoSuma << std::endl;

    // 3. Invocación de una función que retorna un string
    std::string mensajeCompleto = crearMensaje("Carlos");
    std::cout << mensajeCompleto << std::endl;

    return 0;
}


// --- DEFINICIONES DE LAS FUNCIONES ---

// Funcion que no retorna nada (void)
void saludar() {
    std::cout << "¡Hola desde la funcion saludar!" << std::endl;
}

// Funcion que retorna un entero (int) y recibe dos parametros
int sumar(int a, int b) {
    return a + b; // La palabra clave 'return' devuelve el resultado
}

// Funcion que retorna un string y recibe un parametro
std::string crearMensaje(std::string nombre) {
    std::string mensaje = "Bienvenido, " + nombre + ".";
    return mensaje;
}