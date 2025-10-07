#include <iostream>
#include <string>
using namespace std;

class Carro {
    string marca;
    int anno;
    public:
        Carro(string marca, int anno) {
            this->marca = marca;
            this->anno = anno;
        }

        friend ostream& operator<<(ostream& os, const Carro& c) {
            return os << c.marca << " (" << c.anno << ")";
        }
};

class Nodo {
    public:
        Carro dato;
        Nodo* siguiente;

        Nodo(const Carro& c) : dato(c), siguiente(nullptr) {}
};

class Lista {
    Nodo* cabeza;
    public:
        Lista() : cabeza(nullptr) {}

        void insertarInicio(const Carro& c) {
            Nodo* nuevo = new Nodo(c);
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
        }

    // ------------------ ITERADOR ------------------
    class Iterador {
        Nodo* nodoActual;
        public:
            Iterador(Nodo* nodo) : nodoActual(nodo) {}

            // Desreferenciación: devuelve el Carro
            Carro& operator*() {
                return nodoActual->dato;
            }

            // Pre-incremento: ++it
            Iterador& operator++() {
                nodoActual = nodoActual->siguiente;
                return *this;
            }

            // Comparación: !=
            bool operator!=(const Iterador& otro) {
                return nodoActual != otro.nodoActual;
            }
    };

    Iterador begin() { 
        return Iterador(cabeza); 
    }
    Iterador end() { 
        return Iterador(nullptr); 
    }

    friend ostream& operator<<(ostream& os, const Lista& l) {
        Nodo* actual = l.cabeza;
        while (actual) {
            os << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        return os << "NULL";
    }

    ~Lista() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

int main() {
    Lista listaCarros;
    listaCarros.insertarInicio(Carro("Toyota", 2020));
    listaCarros.insertarInicio(Carro("Honda", 2018));
    listaCarros.insertarInicio(Carro("Ford", 2022));

    cout << "Lista completa: " << listaCarros << endl;

    cout << "Recorrido con iterador: ";
    for(Lista::Iterador it = listaCarros.begin(); it != listaCarros.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
