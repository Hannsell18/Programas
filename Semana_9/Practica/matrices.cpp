#include <iostream>
#include <iomanip>
using namespace std;

class RedDeCiudades {
private:
    float** matriz;  // Puntero doble: apunta a un arreglo de punteros
    int n;           // Cantidad de ciudades (tamaño de la matriz n×n)

public:
    // CONSTRUCTOR: Se ejecuta al crear el objeto
    RedDeCiudades(int ciudades) {
        n = ciudades;  // Guardamos cuántas ciudades tenemos
        
        // PASO 1: Crear el arreglo de FILAS (arreglo de punteros)
        // Es como decir: "Dame espacio para n punteros"
        // Cada puntero apuntará a una fila completa
        matriz = new float*[n];
        
        // PASO 2: Para cada FILA, crear el arreglo de COLUMNAS
        // Es como decir: "Para cada puntero, dame espacio para n números"
        for (int i = 0; i < n; i++) {
            matriz[i] = new float[n];  // Crea n columnas para la fila i
            
            // PASO 3: Inicializar TODA la fila en 0
            for(int j = 0; j < n; j++) {
                matriz[i][j] = 0;  // Cada celda comienza en 0
            }
        }
        
        // Al terminar tenemos una matriz n×n llena de ceros
    }
    
    // DESTRUCTOR: Se ejecuta al destruir el objeto
    ~RedDeCiudades() {
        // MUY IMPORTANTE: Liberar memoria en ORDEN INVERSO
        
        // PASO 1: Liberar cada FILA (cada arreglo de columnas)
        for(int i = 0; i < n; i++) {
            delete[] matriz[i];  // Libera el arreglo de columnas i
        }
        
        // PASO 2: Liberar el arreglo de PUNTEROS (las filas)
        delete[] matriz;
        
        // Memoria completamente liberada, sin fugas de memoria
    }
    
    // AGREGAR CONEXIÓN: Añade rutas entre ciudades
    void agregarConexion(int origen, int destino, float cantidad) {
        // Validar que las ciudades existan (índices válidos)
        if(origen >= 0 && origen < n && destino >= 0 && destino < n) {
            
            // SUMAR (+=) la cantidad, NO reemplazar (=)
            // Esto permite acumular rutas si se llama varias veces
            matriz[origen][destino] += cantidad;
            
            // Interpretación:
            // matriz[origen][destino] = rutas que van DE origen HACIA destino
        }
    }
    
    // MOSTRAR: Imprime la matriz en formato tabla
    void mostrar() {
        // Imprimir encabezado (números de columnas)
        cout << "    ";  // Espacios para alinear
        for(int j = 0; j < n; j++) {
            cout << setw(5) << j;  // setw(5) = ancho de 5 caracteres
        }
        cout << endl;
        
        // Imprimir cada fila con su número
        for(int i = 0; i < n; i++) {
            cout << i << " |";  // Número de fila
            
            // Imprimir cada columna de la fila
            for(int j = 0; j < n; j++) {
                cout << setw(5) << matriz[i][j];
            }
            cout << endl;
        }
        
        // Resultado: tabla bonita y organizada
    }
    
    // TOTAL SALIDAS: Rutas que SALEN de una ciudad
    float totalSalidas(int ciudad) {
        // Validar que la ciudad exista
        if(ciudad < 0 || ciudad >= n) return 0;
        
        float total = 0;
        
        // Sumar TODA LA FILA (fila fija, columna variable)
        // La fila representa el ORIGEN
        for(int j = 0; j < n; j++) {
            total += matriz[ciudad][j];  // ciudad = fila, j = columna
        }
        
        // total = todas las rutas que salen de 'ciudad'
        return total;
    }
    
    // TOTAL ENTRADAS: Rutas que LLEGAN a una ciudad
    float totalEntradas(int ciudad) {
        // Validar que la ciudad exista
        if(ciudad < 0 || ciudad >= n) return 0;
        
        float total = 0;
        
        // Sumar TODA LA COLUMNA (fila variable, columna fija)
        // La columna representa el DESTINO
        for(int i = 0; i < n; i++) {
            total += matriz[i][ciudad];  // i = fila, ciudad = columna
        }
        
        // total = todas las rutas que llegan a 'ciudad'
        return total;
    }
};

// MAIN: Programa principal
int main() {
    int n;
    
    // Pedir al usuario cuántas ciudades
    cout << "Ingrese cantidad de ciudades: ";
    cin >> n;
    
    // Crear objeto RedDeCiudades
    // Aquí se ejecuta el CONSTRUCTOR y se crea la matriz n×n
    RedDeCiudades red(n);
    
    // Agregar conexiones entre ciudades
    red.agregarConexion(0, 1, 2);  // De ciudad 0 → ciudad 1: 2 rutas
    red.agregarConexion(1, 2, 3);  // De ciudad 1 → ciudad 2: 3 rutas
    red.agregarConexion(0, 2, 1);  // De ciudad 0 → ciudad 2: 1 ruta
    red.agregarConexion(2, 0, 4);  // De ciudad 2 → ciudad 0: 4 rutas
    
    // Mostrar la matriz completa
    cout << "\nMatriz de conexiones:\n";
    red.mostrar();
    
    // Consultar salidas y entradas de la ciudad 0
    cout << "\nTotal de rutas que salen de ciudad 0: " << red.totalSalidas(0) << endl;
    cout << "Total de rutas que llegan a ciudad 0: " << red.totalEntradas(0) << endl;
    
    // Al terminar el main, el objeto 'red' se destruye
    // Automáticamente se ejecuta el DESTRUCTOR y se libera la memoria
    
    return 0;
}

// ============================================
// RESUMEN DE CONCEPTOS CLAVE
// ============================================
//
// 1️⃣ PUNTERO DOBLE (float**):
//    - Es un puntero que apunta a otros punteros
//    - Permite crear matrices de tamaño VARIABLE (dinámico)
//
// 2️⃣ CREAR MATRIZ DINÁMICA:
//    matriz = new float*[n];        // Crear filas
//    matriz[i] = new float[n];      // Crear columnas para cada fila
//
// 3️⃣ LIBERAR MEMORIA:
//    delete[] matriz[i];            // Primero: liberar cada fila
//    delete[] matriz;               // Después: liberar el conjunto
//
// 4️⃣ ACCEDER A LA MATRIZ:
//    matriz[fila][columna] = valor;
//
// 5️⃣ SALIDAS vs ENTRADAS:
//    - Salidas: Sumar la FILA → matriz[ciudad][j]
//    - Entradas: Sumar la COLUMNA → matriz[i][ciudad]
//
// ============================================