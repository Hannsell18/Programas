#include <iostream>

class MiLista {
private:
    int* datos;      // Apunta al arreglo dinámico de enteros
    int capacidad;   // Cuántos elementos puede almacenar
    int cantidad;    // Cuántos elementos contiene actualmente

public:
    // Constructor
    MiLista(int cap) {
        capacidad = cap;
        cantidad = 0;
        datos = new int[capacidad];
    }

    // Constructor de copia
    MiLista(const MiLista& otra) {
        capacidad = otra.capacidad;
        cantidad = otra.cantidad;
        datos = new int[capacidad];
        for(int i = 0; i < cantidad; i++) {
            datos[i] = otra.datos[i];
        }
    }

    // Destructor
    ~MiLista() {
        delete[] datos;
    }

    // Sobrecarga del operador = para copiar listas
    MiLista& operator=(const MiLista& otra) {
        if(this != &otra) {  // Evitar autoasignación
            delete[] datos;
            capacidad = otra.capacidad;
            cantidad = otra.cantidad;
            datos = new int[capacidad];
            for(int i = 0; i < cantidad; i++) {
                datos[i] = otra.datos[i];
            }
        }
        return *this;
    }

    // Método para agregar un elemento
    void agregar(int valor) {
        if(cantidad == capacidad) {
            // Redimensionamiento directo
            int* nuevoDatos = new int[capacidad * 2];
            for(int i = 0; i < cantidad; i++) {
                nuevoDatos[i] = datos[i];
            }
            delete[] datos;
            datos = nuevoDatos;
            capacidad *= 2;
        }
        datos[cantidad] = valor;
        cantidad++;
    }

    // CLASE ITERADOR anidada
    class Iterador {
    private:
        int* posicionActual;  // Puntero al elemento actual
    public:
        Iterador(int* pos) : posicionActual(pos) {}

        int operator*() { return *posicionActual; }

        // Pre-incremento
        Iterador& operator++() {
            posicionActual++;
            return *this;
        }

        // Post-incremento
        Iterador operator++(int) {
            Iterador copia = *this;
            posicionActual++;
            return copia;
        }

        // Pre-decremento
        Iterador& operator--() {
            posicionActual--;
            return *this;
        }

        // Post-decremento
        Iterador operator--(int) {
            Iterador copia = *this;
            posicionActual--;
            return copia;
        }

        bool operator!=(const Iterador& otro) {
            return posicionActual != otro.posicionActual;
        }
    };

    Iterador begin() { return Iterador(datos); }
    Iterador end() { return Iterador(datos + cantidad); }

    void mostrarInfo() {
        std::cout << "Cantidad: " << cantidad << ", Capacidad: " << capacidad << std::endl;
    }
};

// --------------------- MAIN ---------------------
int main() {
    MiLista lista(3);

    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);
    lista.mostrarInfo(); // Cantidad: 3, Capacidad: 3

    lista.agregar(40);   // Duplica capacidad automáticamente
    lista.agregar(50);
    lista.mostrarInfo(); // Cantidad: 5, Capacidad: 6

    // Recorrido con pre-incremento
    std::cout << "Recorrido con pre-incremento: ";
    for(MiLista::Iterador it = lista.begin(); it != lista.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Recorrido con post-incremento
    std::cout << "Recorrido con post-incremento: ";
    for(MiLista::Iterador it = lista.begin(); it != lista.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Recorrido con pre-decremento
    std::cout << "Recorrido con pre-decremento: ";
    for(MiLista::Iterador it = lista.end(); it != lista.begin(); ) {
        --it;
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Recorrido con post-decremento
    std::cout << "Recorrido con post-decremento: ";
    for(MiLista::Iterador it = lista.end(); it != lista.begin(); ) {
        MiLista::Iterador copia = it--;
        std::cout << *copia << " ";
    }
    std::cout << std::endl;

    return 0;
}
