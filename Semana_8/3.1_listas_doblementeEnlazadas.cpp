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
// Clase Nodo: Cada nodo tiene punteros al siguiente Y al anterior
//
class Nodo {
    public:
        Carro dato;        // Dato que guarda el nodo (en este caso un Carro)
        Nodo* siguiente;   // Puntero al siguiente nodo de la lista
        Nodo* anterior;    // Puntero al nodo anterior de la lista

        // Constructor: inicializa el nodo con un Carro y sin enlaces
        Nodo(const Carro& c) : dato(c) {
            this->siguiente = nullptr;
            this->anterior = nullptr;
        }
};

//
// Clase ListaDoble: Administra los nodos de la lista doblemente enlazada.
//
class ListaDoble {
    Nodo* cabeza;  // Puntero al primer nodo (la "cabeza" de la lista)
    Nodo* cola;    // Puntero al último nodo (la "cola" de la lista)
    
    public:
        // Constructor: inicializa la lista vacía
        ListaDoble() {
            this->cabeza = nullptr;
            this->cola = nullptr;
        }

        // Inserta un carro al inicio de la lista
        void insertarInicio(const Carro& c) {
            Nodo* nuevo = new Nodo(c);    // 1. Se crea un nodo dinámicamente con new
            
            // Si la lista está vacía
            if (this->cabeza == nullptr) {
                this->cabeza = nuevo;
                this->cola = nuevo;
            } else {
                // 2. El nuevo nodo apunta hacia adelante a la antigua cabeza
                nuevo->siguiente = this->cabeza;
                // 3. La antigua cabeza apunta hacia atrás al nuevo nodo
                this->cabeza->anterior = nuevo;
                // 4. La cabeza ahora es el nuevo nodo
                this->cabeza = nuevo;
            }
        }

        // Inserta un carro al final de la lista
        void insertarFinal(const Carro& c) {
            Nodo* nuevo = new Nodo(c);    // 1. Se crea un nodo dinámicamente con new
            
            // Si la lista está vacía
            if (this->cola == nullptr) {
                this->cabeza = nuevo;
                this->cola = nuevo;
            } else {
                // 2. El nuevo nodo apunta hacia atrás a la antigua cola
                nuevo->anterior = this->cola;
                // 3. La antigua cola apunta hacia adelante al nuevo nodo
                this->cola->siguiente = nuevo;
                // 4. La cola ahora es el nuevo nodo
                this->cola = nuevo;
            }
        }

        // Imprime la lista de inicio a fin
        void imprimirAdelante() const {
            cout << "De inicio a fin: ";
            Nodo* actual = this->cabeza;
            while (actual) {
                cout << actual->dato << " <-> ";
                actual = actual->siguiente;
            }
            cout << "NULL" << endl;
        }

        // Imprime la lista de fin a inicio (recorrido inverso)
        void imprimirAtras() const {
            cout << "De fin a inicio: ";
            Nodo* actual = this->cola;
            while (actual) {
                cout << actual->dato << " <-> ";
                actual = actual->anterior;
            }
            cout << "NULL" << endl;
        }

        // Sobrecarga del operador << para imprimir toda la lista (adelante)
        friend ostream& operator<<(ostream& os, const ListaDoble& l) {
            Nodo* actual = l.cabeza;
            while (actual) {
                os << actual->dato << " <-> ";
                actual = actual->siguiente;
            }
            return os << "NULL";
        }

        // Destructor: libera la memoria de todos los nodos
        ~ListaDoble() {
            Nodo* actual = this->cabeza;
            while (actual) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;              // Liberamos la memoria del nodo
            }
        }
};

//
// Función principal: Demostración de la lista doblemente enlazada con carros.
//
int main() {
    cout << "========================================" << endl;
    cout << "  LISTA DOBLEMENTE ENLAZADA DE CARROS  " << endl;
    cout << "========================================" << endl << endl;

    ListaDoble listaCarros;   // Creamos una lista vacía

    // Insertamos carros al inicio
    cout << ">> Insertando al INICIO:" << endl;
    listaCarros.insertarInicio(Carro("Toyota", 2020));
    listaCarros.insertarInicio(Carro("Honda", 2018));
    listaCarros.insertarInicio(Carro("Ford", 2022));

    cout << "\n" << listaCarros << endl << endl;

    // Insertamos carros al final
    cout << ">> Insertando al FINAL:" << endl;
    listaCarros.insertarFinal(Carro("Mazda", 2023));
    listaCarros.insertarFinal(Carro("Nissan", 2021));

    cout << "\n" << listaCarros << endl << endl;

    // Demostramos el recorrido bidireccional
    cout << "========================================" << endl;
    cout << "  RECORRIDO BIDIRECCIONAL (ventaja)    " << endl;
    cout << "========================================" << endl;
    listaCarros.imprimirAdelante();
    listaCarros.imprimirAtras();

    return 0;
}