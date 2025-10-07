#include <iostream>

/*
Aqui primero definimos la estructura básica de una lista, la cual indica que 
tendrá un puntero de tipo int a datos, su capacidad y cantidad.

No es una lista enlazada (como con Nodo* siguiente), sino una lista
con un arreglo dinámico interno (como una versión casera de std::vector).
*/
class MiLista {
    private:
        int* datos;      // Apunta al bloque de memoria donde guardas los datos (un arreglo dinámico)
        int capacidad;   // Cuántos elementos puede guardar en total
        int cantidad;    // Cuántos elementos lleva guardados actualmente
    public:
        // Constructor
        MiLista(int cap) {
            capacidad = cap;
            cantidad = 0;
            datos = new int[capacidad];
        }
        /*
        Lo que hace:
        Guarda cuánta capacidad tendrá (capacidad = cap).
        Pone la cantidad inicial en cero (cantidad = 0).
        Reserva memoria para un arreglo de enteros (new int[capacidad]).
        */
        // Destructor
        ~MiLista() {
            delete[] datos;
        }
        // Agregar elemento
        void agregar(int valor) {
            if(cantidad < capacidad) {
                datos[cantidad] = valor;
                cantidad++;
            }
        }


    // CLASE ITERADOR (anidada dentro de MiLista)
    class Iterador {
    private:
        int* posicionActual;  // Puntero al elemento actual
        
    public:
        // Constructor del iterador
        Iterador(int* pos) {
            posicionActual = pos;
        }
        
        // Operador de desreferenciación
        int operator*() {
            return *posicionActual;
        }
        
        // Operador de pre-incremento
        Iterador& operator++() {
            posicionActual++;  // Mueve el puntero al siguiente
            return *this;      // Retorna el iterador mismo
        }
        
        Iterador operator++(int) {  // Post-incremento (el int es solo sintaxis)
            Iterador copia = *this;  // Guarda copia del estado actual
            posicionActual++;         // Incrementa
            return copia;             // Retorna el estado ANTES de incrementar
        }

        // Operador de comparación
        bool operator!=(const Iterador& otro) {
            return posicionActual != otro.posicionActual;
        }
    };
    
    // Métodos para obtener iteradores
    Iterador begin() {
        return Iterador(datos);  // Apunta al primer elemento
    }
    
    Iterador end() {
        return Iterador(datos + cantidad);  // Apunta después del último
    }



};

int main() {
    MiLista lista(5);
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);

    for (MiLista::Iterador it = lista.begin(); it != lista.end(); ++it) {
        std::cout << *it << " ";
    }
}