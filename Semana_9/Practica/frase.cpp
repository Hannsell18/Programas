#include <iostream>
using namespace std;

class Frase {
private:
    char* texto;

    // Calcula manualmente la longitud de una cadena
    int longitud(const char* cad) const {
        int cont = 0;
        while (cad[cont] != '\0'){
            cont++;
        } 
        return cont;
    }

    // Copia manualmente una cadena origen en destino
    void copiar(char* destino, const char* origen) const {
        int i = 0;
        while (origen[i] != '\0') {
            destino[i] = origen[i];
            i++;
        }
        destino[i] = '\0';
    }

public:
    // Constructor normal
    Frase(const char* cad) {
        cout << "Constructor llamado\n";
        int len = longitud(cad);
        texto = new char[len + 1]; // +1 para el carácter nulo
        copiar(texto, cad);
    }

    // Constructor de copia (Deep Copy)
    Frase(const Frase& original) {
        cout << "Constructor de copia (Deep Copy) llamado\n";
        int len = longitud(original.texto);
        texto = new char[len + 1];
        copiar(texto, original.texto);
    }

    // Método que retorna un puntero a una nueva copia del texto
    char* getTexto() const {
        int len = longitud(texto);
        char* copia = new char[len + 1];
        copiar(copia, texto);
        return copia;
    }

    // Cambia la primera letra (para probar shallow vs deep copy)
    void cambiarPrimeraLetra(char nueva) {
        texto[0] = nueva;
    }

    // Mostrar texto
    void mostrar() const {
        cout << "Frase: " << texto << endl;
    }

    // Destructor
    ~Frase() {
        cout << "Destructor llamado\n";
        delete[] texto;
    }
};


int main() {
    Frase f1("Programar es divertido");

    // Deep copy
    Frase f2 = f1;

    cout << "Antes de modificar \n";
    f1.mostrar();
    f2.mostrar();

    f1.cambiarPrimeraLetra('A');

    cout << "Después de modificar f1 \n";
    f1.mostrar();
    f2.mostrar();

    char* copia = f2.getTexto();
    cout << "Texto retornado desde puntero: " << copia << endl;

    delete[] copia;
    return 0;
}
