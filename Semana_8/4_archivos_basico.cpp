#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // ========== LEER CSV ==========
    cout << "=== PRODUCTOS EN EL ARCHIVO ===\n";
    
    ifstream archivoLeer("productos.csv");
    string linea;
    
    getline(archivoLeer, linea); // Saltar encabezados
    cout << "Encabezados: " << linea << "\n\n";
    
    while (getline(archivoLeer, linea)) {
        stringstream ss(linea);
        //001,manzana,250
        string codigo, nombre, precio;
        
        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, precio, ',');
        
        cout << codigo << " | " << nombre << " | $" << precio << endl;
    }
    
    archivoLeer.close();
    
    
    // ========== ESCRIBIR EN CSV ==========
    cout << "\n=== AGREGAR NUEVO PRODUCTO ===\n";
    
    string nuevoCodigo, nuevoNombre, nuevoPrecio;
    
    cout << "Codigo: ";
    cin >> nuevoCodigo;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevoNombre);
    cout << "Precio: ";
    cin >> nuevoPrecio;
    
    // Abrir en modo APPEND (agregar al final)
    ofstream archivoEscribir("productos.csv", ios::app);
    
    // IMPORTANTE: Escribir en el formato correcto con comas
    archivoEscribir << nuevoCodigo << "," 
                    << nuevoNombre << "," 
                    << nuevoPrecio << "\n";
    
    archivoEscribir.close();
    
    cout << "\nProducto agregado correctamente!\n";
    
    
    // ========== VERIFICAR QUE SE AGREGÓ BIEN ==========
    cout << "\n=== CONTENIDO ACTUALIZADO ===\n";
    
    ifstream verificar("productos.csv");
    getline(verificar, linea); // Encabezados
    
    while (getline(verificar, linea)) {
        stringstream ss(linea);
        string codigo, nombre, precio;
        
        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, precio, ',');
        
        cout << codigo << " | " << nombre << " | $" << precio << endl;
    }
    
    verificar.close();
    
    return 0;
}