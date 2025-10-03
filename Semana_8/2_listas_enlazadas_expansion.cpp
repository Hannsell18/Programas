#include <iostream>
#include <string>
using namespace std;

//
// Clase Carro: Representa el dato que guardaremos en cada nodo de la lista.
//
class Carro {
    string marca;
    int anno;
    public:
        // Constructor que inicializa un carro con marca y año usando this
        Carro(string marca, int anno) {
            this->marca = marca;
            this->anno = anno;
        }

        // Sobrecarga del operador << para imprimir objetos Carro
        friend ostream& operator<<(ostream& os, const Carro& c) {
            return os << c.marca << " (" << c.anno << ")";
        }
};

//
// Clase Nodo: Cada nodo de la lista guarda un Carro y un puntero al siguiente nodo.
//
class Nodo {
    public:
        Carro dato;       // Dato que guarda el nodo (en este caso un Carro)
        Nodo* siguiente;  // Puntero al siguiente nodo de la lista

        // Constructor: inicializa el nodo con un Carro y sin siguiente (nullptr)
        // Llame al constructor de Carro y construye dato usando c
        Nodo(const Carro& c) : dato(c) {
            this->siguiente = nullptr;
        }
};

//
// Clase Lista: Administra los nodos de la lista enlazada.
//
class Lista {
    Nodo* cabeza;  // Puntero al primer nodo (la "cabeza" de la lista)
    public:
        // Constructor: inicializa la lista vacía
        Lista() {
            this->cabeza = nullptr;
        }

        // Inserta un carro al inicio de la lista
        void insertarInicio(const Carro& c) {
            Nodo* nuevo = new Nodo(c);    // 1. Se crea un nodo dinámicamente con new
            nuevo->siguiente = this->cabeza; // 2. El nuevo nodo apunta al anterior primero
            this->cabeza = nuevo;         // 3. La cabeza ahora es el nuevo nodo
        }

        // Inserta un carro al final de la lista
        void insertarFinal(const Carro& c) {
            Nodo* nuevo = new Nodo(c);    // 1. Se crea un nodo dinámicamente con new
            
            // Si la lista está vacía, el nuevo nodo será la cabeza
            if (this->cabeza == nullptr) {
                this->cabeza = nuevo;
                return;
            }
            
            // Si la lista no está vacía, recorremos hasta el último nodo
            Nodo* actual = this->cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;  // Avanzamos al siguiente nodo
            }
            
            // El último nodo ahora apunta al nuevo nodo
            actual->siguiente = nuevo;
        }

        // Sobrecarga del operador << para imprimir toda la lista
        friend ostream& operator<<(ostream& os, const Lista& l) {
            Nodo* actual = l.cabeza;
            while (actual) {              // Mientras no lleguemos al final
                os << actual->dato << " -> ";
                actual = actual->siguiente;  // Avanzamos al siguiente nodo
            }
            return os << "NULL";          // Fin de la lista
        }

        // Destructor: libera la memoria de todos los nodos
        ~Lista() {
            Nodo* actual = this->cabeza;
            while (actual) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;              // Liberamos la memoria del nodo
            }
        }
};

//
// Función principal: Demostración de la lista enlazada con carros.
//
int main() {
    Lista listaCarros;   // Creamos una lista vacía

    // Insertamos carros al inicio (el último insertado queda de primero)
    listaCarros.insertarInicio(Carro("Toyota", 2020));
    listaCarros.insertarInicio(Carro("Honda", 2018));
    listaCarros.insertarInicio(Carro("Ford", 2022));

    // Imprimimos la lista completa
    cout << "Lista con insertar al inicio:" << endl;
    cout << listaCarros << endl;
    // Salida esperada:
    // Ford (2022) -> Honda (2018) -> Toyota (2020) -> NULL

    // Ahora probamos insertarFinal
    listaCarros.insertarFinal(Carro("Mazda", 2023));
    listaCarros.insertarFinal(Carro("Nissan", 2021));

    cout << "\nLista después de insertar al final:" << endl;
    cout << listaCarros << endl;
    // Salida esperada:
    // Ford (2022) -> Honda (2018) -> Toyota (2020) -> Mazda (2023) -> Nissan (2021) -> NULL

    return 0;
}