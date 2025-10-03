#include <iostream>
#include <fstream>   // Librería necesaria para trabajar con archivos
#include <string>
using namespace std;

/*
 * ═══════════════════════════════════════════════════════════════════════════
 *                   GUÍA COMPLETA DE MANEJO DE ARCHIVOS EN C++
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * ¿QUÉ SON LOS ARCHIVOS EN PROGRAMACIÓN?
 * Son formas de almacenar datos de manera PERSISTENTE (sobreviven al cierre
 * del programa), a diferencia de las variables que se borran al terminar.
 *
 * CLASES PRINCIPALES PARA MANEJO DE ARCHIVOS:
 * ┌────────────┬──────────────────────────┬─────────────────────────────────┐
 * │  Clase     │  Propósito               │  Ejemplo de uso                 │
 * ├────────────┼──────────────────────────┼─────────────────────────────────┤
 * │ ofstream   │ ESCRIBIR en archivos     │ Guardar datos, crear reportes   │
 * │            │ (output file stream)     │                                 │
 * ├────────────┼──────────────────────────┼─────────────────────────────────┤
 * │ ifstream   │ LEER archivos            │ Cargar configuración, importar  │
 * │            │ (input file stream)      │ datos                           │
 * ├────────────┼──────────────────────────┼─────────────────────────────────┤
 * │ fstream    │ LEER Y ESCRIBIR          │ Actualizar archivos existentes  │
 * │            │ (file stream)            │                                 │
 * └────────────┴──────────────────────────┴─────────────────────────────────┘
 *
 * ANALOGÍA: Piensa en los archivos como cuadernos:
 * - ofstream es como escribir en un cuaderno nuevo
 * - ifstream es como leer un cuaderno existente
 * - fstream es como tener un cuaderno donde puedes leer Y escribir
 */

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 1: ESCRIBIR EN ARCHIVO - Conceptos básicos
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Mostrar cómo crear y escribir datos en un archivo de texto
 *
 * PROCESO BÁSICO PARA ESCRIBIR EN ARCHIVOS:
 * 1. Declarar objeto ofstream
 * 2. Abrir el archivo con .open() o en el constructor
 * 3. Verificar que se abrió correctamente con .is_open()
 * 4. Escribir datos usando el operador << (igual que con cout)
 * 5. Cerrar el archivo con .close()
 */
void escribirArchivo() {
    cout << "\n=== ESCRITURA DE ARCHIVOS ===\n";

    // PASO 1: Crear objeto ofstream (output file stream)
    ofstream archivo;

    // PASO 2: Abrir el archivo (se crea si no existe, se sobrescribe si existe)
    archivo.open("datos.txt");

    // PASO 3: SIEMPRE verificar si el archivo se abrió correctamente
    // Puede fallar por: permisos, disco lleno, ruta inválida, etc.
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    // PASO 4: Escribir datos en el archivo
    // Funciona exactamente igual que cout, pero guarda en el archivo
    archivo << "Hola, este es un archivo de texto\n";
    archivo << "Número: " << 42 << "\n";
    archivo << "Pi aproximado: " << 3.14159 << "\n";

    // PASO 5: IMPORTANTE: Siempre cerrar el archivo
    // Esto asegura que los datos se guarden correctamente
    archivo.close();
    cout << "Archivo 'datos.txt' creado exitosamente\n";

    // NOTA: El archivo se crea en el mismo directorio donde se ejecuta el programa
}

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 2: MODOS DE APERTURA - Control avanzado de archivos
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Aprender a controlar CÓMO se abre un archivo
 *
 * TABLA DE MODOS DE APERTURA:
 * ┌──────────────┬──────────────────────────────┬───────────────────────────┐
 * │    Modo      │  Descripción                 │  Efecto                   │
 * ├──────────────┼──────────────────────────────┼───────────────────────────┤
 * │ ios::in      │ Abrir para LECTURA           │ El archivo debe existir   │
 * │ ios::out     │ Abrir para ESCRITURA         │ BORRA contenido previo    │
 * │ ios::app     │ APPEND (agregar)             │ Mantiene contenido, añade │
 * │              │                              │ al final                  │
 * │ ios::ate     │ At The End (al final)        │ Inicia al final pero se   │
 * │              │                              │ puede mover               │
 * │ ios::trunc   │ TRUNCATE (truncar)           │ Borra todo el contenido   │
 * │ ios::binary  │ Modo BINARIO                 │ Para archivos no texto    │
 * └──────────────┴──────────────────────────────┴───────────────────────────┘
 *
 * TIP: Los modos se pueden COMBINAR usando el operador | (OR binario)
 * Ejemplo: ios::in | ios::out | ios::app
 */
void modosDeApertura() {
    cout << "\n=== MODOS DE APERTURA ===\n";

    // EJEMPLO 1: ios::app (APPEND) - Agregar sin borrar
    // Útil para archivos de log que necesitan preservar historial
    ofstream archivo1("log.txt", ios::app);
    archivo1 << "Nueva línea agregada al final\n";
    archivo1.close();
    cout << "Línea agregada a log.txt (sin borrar contenido previo)\n";

    // EJEMPLO 2: Combinar modos - Lectura, escritura y append
    // Permite leer Y escribir en el mismo archivo
    fstream archivo2("datos_mixtos.txt", ios::in | ios::out | ios::app);
    if (archivo2.is_open()) {
        archivo2 << "Línea adicional al final\n";
        archivo2.close();
        cout << "Archivo mixto actualizado\n";
    }

    // COMPARACIÓN:
    // ofstream archivo("test.txt");              → BORRA contenido existente
    // ofstream archivo("test.txt", ios::app);    → MANTIENE contenido, añade al final
}

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 3: LEER ARCHIVO LÍNEA POR LÍNEA - Método más común
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Leer un archivo línea por línea (el método MÁS USADO)
 *
 * ¿CUÁNDO USAR getline()?
 * - Cuando necesitas leer cada línea completa
 * - Para procesar archivos de texto línea por línea
 * - Cuando las líneas tienen espacios (>> no sirve en este caso)
 *
 * SINTAXIS: getline(archivo, variable_string)
 * - Lee desde el archivo hasta encontrar '\n' (salto de línea)
 * - Guarda la línea en la variable string
 * - NO incluye el '\n' en el string resultante
 */
void leerArchivoLineas() {
    cout << "\n=== LECTURA LÍNEA POR LÍNEA ===\n";

    // Abrir archivo para LECTURA usando ifstream
    ifstream archivo("datos.txt");

    // Verificar que se abrió correctamente
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para lectura\n";
        return;
    }

    string linea;
    int numeroLinea = 1;

    // getline() devuelve true mientras haya líneas que leer
    // Cuando llega al final del archivo, devuelve false y el ciclo termina
    while (getline(archivo, linea)) {
        cout << "Línea " << numeroLinea << ": " << linea << "\n";
        numeroLinea++;
    }

    archivo.close();

    // EJEMPLO DE USO REAL:
    // Leer un archivo de configuración, un CSV, un archivo de log, etc.
}

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 4: LEER ARCHIVO PALABRA POR PALABRA - Operador >>
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Leer un archivo palabra por palabra (tokens)
 *
 * DIFERENCIA entre >> y getline():
 * ┌─────────────┬──────────────────────────┬─────────────────────────────┐
 * │  Método     │  Lee hasta...            │  Uso típico                 │
 * ├─────────────┼──────────────────────────┼─────────────────────────────┤
 * │ getline()   │ Salto de línea (\n)      │ Leer líneas completas       │
 * │ >>          │ Espacio, tab o \n        │ Leer palabras individuales  │
 * └─────────────┴──────────────────────────┴─────────────────────────────┘
 *
 * EJEMPLO DE LA DIFERENCIA:
 * Archivo: "Hola mundo\nAdiós"
 * Con getline(): obtiene "Hola mundo" (primera iteración)
 * Con >>: obtiene "Hola" (primera), "mundo" (segunda), "Adiós" (tercera)
 */
void leerArchivoPalabras() {
    cout << "\n=== LECTURA PALABRA POR PALABRA ===\n";

    ifstream archivo("datos.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo\n";
        return;
    }

    string palabra;

    // El operador >> lee palabra por palabra (separadas por espacios/tabs/saltos)
    // IGNORA automáticamente espacios en blanco al inicio
    while (archivo >> palabra) {
        cout << palabra << " | ";
    }
    cout << "\n";

    archivo.close();

    // USO REAL: Contar palabras, buscar palabras específicas, analizar texto
}

// ==================== FUNCIÓN 5: LEER ARCHIVO COMPLETO ====================
void leerArchivoCompleto() {
    cout << "\n=== LECTURA DE ARCHIVO COMPLETO ===\n";
    
    ifstream archivo("datos.txt");
    
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo\n";
        return;
    }
    
    string contenido;
    string linea;
    
    // Concatenar todas las líneas
    while (getline(archivo, linea)) {
        contenido += linea + "\n";
    }
    
    cout << "Contenido completo:\n" << contenido;
    
    archivo.close();
}

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 6: VERIFICACIONES DE ESTADO - Control de errores
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Detectar problemas durante operaciones con archivos
 *
 * MÉTODOS DE VERIFICACIÓN:
 * ┌─────────────┬──────────────────────────────────────────────────────────┐
 * │  Método     │  ¿Qué verifica?                                          │
 * ├─────────────┼──────────────────────────────────────────────────────────┤
 * │ is_open()   │ Si el archivo se abrió exitosamente                      │
 * │ eof()       │ Si llegamos al END OF FILE (final del archivo)           │
 * │ fail()      │ Si hubo un error en la última operación                  │
 * │ bad()       │ Si hubo un error GRAVE (corrupto, hardware)              │
 * │ good()      │ Si todo está bien (sin errores ni eof)                   │
 * └─────────────┴──────────────────────────────────────────────────────────┘
 *
 * TIP: Usa is_open() SIEMPRE después de abrir, y good() para verificar estado
 */
void verificacionesArchivo() {
    cout << "\n=== VERIFICACIONES DE ESTADO ===\n";

    ifstream archivo("datos.txt");

    // VERIFICACIÓN 1: ¿Se abrió correctamente?
    if (!archivo.is_open()) {
        cout << "Archivo no existe o no se puede abrir\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        // VERIFICACIÓN 2: ¿Llegamos al final?
        if (archivo.eof()) {
            cout << "Llegamos al final del archivo\n";
        }
    }

    // VERIFICACIÓN 3: ¿Hubo errores en operaciones?
    if (archivo.fail()) {
        cout << "Hubo un error en la lectura\n";
    }

    // VERIFICACIÓN 4: ¿Todo está bien?
    if (archivo.good()) {
        cout << "El archivo está en buen estado (no hay errores)\n";
    }

    archivo.close();

    // PRÁCTICA RECOMENDADA:
    // Siempre verifica is_open() después de abrir un archivo
}

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 7: POSICIONAMIENTO EN ARCHIVO - Navegación avanzada
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Mover el "cursor" de lectura/escritura dentro del archivo
 *
 * ANALOGÍA: Imagina un archivo como un libro con un marcador
 * - tellg()/tellp() → ¿En qué página estoy?
 * - seekg()/seekp() → Mover el marcador a otra página
 *
 * FUNCIONES DE POSICIONAMIENTO:
 * ┌─────────────┬────────────────────────────────────────────────────────┐
 * │  Función    │  Descripción                                           │
 * ├─────────────┼────────────────────────────────────────────────────────┤
 * │ tellg()     │ Tell Get - obtener posición actual de LECTURA (bytes) │
 * │ tellp()     │ Tell Put - obtener posición actual de ESCRITURA       │
 * │ seekg(n,d)  │ Seek Get - mover puntero de LECTURA                    │
 * │ seekp(n,d)  │ Seek Put - mover puntero de ESCRITURA                  │
 * └─────────────┴────────────────────────────────────────────────────────┘
 *
 * DIRECCIONES para seekg/seekp:
 * - ios::beg → Desde el inicio (beginning)
 * - ios::cur → Desde la posición actual (current)
 * - ios::end → Desde el final (end)
 */
void posicionamientoArchivo() {
    cout << "\n=== POSICIONAMIENTO EN ARCHIVO ===\n";

    fstream archivo("datos.txt", ios::in);

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo\n";
        return;
    }

    // tellg() - ¿En qué posición (byte) estoy?
    cout << "Posición inicial: " << archivo.tellg() << " bytes\n";

    // seekg() - Mover al FINAL del archivo
    archivo.seekg(0, ios::end);  // 0 bytes desde el final = al final
    cout << "Tamaño del archivo: " << archivo.tellg() << " bytes\n";

    // seekg() - Volver al INICIO del archivo
    archivo.seekg(0, ios::beg);  // 0 bytes desde el inicio = al inicio

    // Leer desde la posición actual (inicio)
    string primera_linea;
    getline(archivo, primera_linea);
    cout << "Primera línea: " << primera_linea << "\n";

    // EJEMPLO PRÁCTICO: Para leer desde el byte 10:
    // archivo.seekg(10, ios::beg);

    archivo.close();
}

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 8: ESCRIBIR DATOS ESTRUCTURADOS - Formato CSV
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Guardar datos organizados en formato CSV (Comma Separated Values)
 *
 * ¿QUÉ ES CSV?
 * Es un formato simple para guardar datos en forma de tabla:
 * - Cada línea = una fila
 * - Cada campo = separado por coma (,)
 * - Primera línea = encabezados (nombres de columnas)
 *
 * VENTAJAS DE CSV:
 * ✓ Fácil de leer y escribir
 * ✓ Compatible con Excel, Google Sheets
 * ✓ Formato universal para intercambio de datos
 * ✓ Archivo de texto plano (se puede abrir con cualquier editor)
 *
 * ESTRUCTURA:
 * Nombre,Edad,Promedio    ← Encabezado
 * Juan,20,8.5             ← Datos fila 1
 * María,22,9.2            ← Datos fila 2
 */
void escribirDatosEstructurados() {
    cout << "\n=== ESCRITURA DE DATOS ESTRUCTURADOS ===\n";

    ofstream archivo("estudiantes.txt");

    if (!archivo.is_open()) {
        cout << "Error al crear archivo\n";
        return;
    }

    // Escribir ENCABEZADO (nombres de columnas)
    archivo << "Nombre,Edad,Promedio\n";

    // Escribir DATOS (formato CSV: valores separados por comas)
    archivo << "Juan,20,8.5\n";
    archivo << "María,22,9.2\n";
    archivo << "Pedro,21,7.8\n";

    archivo.close();
    cout << "Archivo 'estudiantes.txt' creado (formato CSV)\n";

    // USO REAL: Exportar datos de programas, guardar tablas, intercambiar info
}

// ==================== FUNCIÓN 9: LEER DATOS ESTRUCTURADOS ====================
void leerDatosEstructurados() {
    cout << "\n=== LECTURA DE DATOS ESTRUCTURADOS ===\n";

    ifstream archivo("estudiantes.txt");
    
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo\n";
        return;
    }
    
    string linea;
    getline(archivo, linea); // Saltar encabezado
    
    cout << "Datos de estudiantes:\n";
    
    while (getline(archivo, linea)) {
        // Parsear línea manualmente (ejemplo simple)
        cout << "  " << linea << "\n";
    }
    
    archivo.close();
}

// ════════════════════════════════════════════════════════════════════════════
// FUNCIÓN 10: ARCHIVOS BINARIOS - Datos en formato crudo
// ════════════════════════════════════════════════════════════════════════════
/*
 * PROPÓSITO: Trabajar con archivos binarios (datos no legibles por humanos)
 *
 * DIFERENCIA: Archivos de TEXTO vs BINARIOS
 * ┌───────────────┬─────────────────────────┬────────────────────────────┐
 * │  Característica│  Archivo de TEXTO       │  Archivo BINARIO           │
 * ├───────────────┼─────────────────────────┼────────────────────────────┤
 * │ Legibilidad   │ Sí (Notepad, editor)    │ NO (bytes crudos)          │
 * │ Tamaño        │ Más grande              │ Más compacto               │
 * │ Velocidad     │ Más lento               │ Más rápido                 │
 * │ Portabilidad  │ Alta (multiplataforma)  │ Baja (depende de sistema)  │
 * │ Uso típico    │ Configs, logs, CSV      │ Imágenes, ejecutables, DB  │
 * └───────────────┴─────────────────────────┴────────────────────────────┘
 *
 * MÉTODOS ESPECIALES:
 * - write(puntero, tamaño) → Escribir bytes crudos
 * - read(puntero, tamaño)  → Leer bytes crudos
 * - reinterpret_cast<char*> → Convertir cualquier tipo a bytes
 *
 * ¿CUÁNDO USAR BINARIOS?
 * ✓ Guardar estructuras de datos completas
 * ✓ Mayor velocidad de lectura/escritura
 * ✓ Menor tamaño de archivo
 * ✗ NO para archivos que necesiten ser editados manualmente
 */
void archivosBinarios() {
    cout << "\n=== ARCHIVOS BINARIOS ===\n";

    // ========== ESCRIBIR en BINARIO ==========
    ofstream salida("numeros.bin", ios::binary);  // Modo BINARY activado

    if (salida.is_open()) {
        int numeros[] = {10, 20, 30, 40, 50};

        // write() escribe BYTES CRUDOS (no conversión a texto)
        // Parámetros: (puntero_como_char*, cantidad_de_bytes)
        salida.write(reinterpret_cast<char*>(numeros), sizeof(numeros));
        salida.close();
        cout << "Archivo binario 'numeros.bin' creado\n";
    }

    // ========== LEER en BINARIO ==========
    ifstream entrada("numeros.bin", ios::binary);  // Modo BINARY para lectura

    if (entrada.is_open()) {
        int numeros_leidos[5];

        // read() lee BYTES CRUDOS directamente a memoria
        entrada.read(reinterpret_cast<char*>(numeros_leidos), sizeof(numeros_leidos));

        cout << "Números leídos del archivo binario: ";
        for (int i = 0; i < 5; i++) {
            cout << numeros_leidos[i] << " ";
        }
        cout << "\n";

        entrada.close();
    }

    // NOTA: Los archivos .bin NO se pueden abrir con Notepad (verás símbolos raros)
}

// ==================== FUNCIÓN PRINCIPAL ====================
int main() {
    cout << "==============================================\n";
    cout << "  GUÍA COMPLETA DE ARCHIVOS EN C++\n";
    cout << "==============================================\n";
    
    // Ejecutar todas las demostraciones
    escribirArchivo();
    modosDeApertura();
    leerArchivoLineas();
    leerArchivoPalabras();
    leerArchivoCompleto();
    verificacionesArchivo();
    posicionamientoArchivo();
    escribirDatosEstructurados();
    leerDatosEstructurados();
    archivosBinarios();
    
    cout << "\n==============================================\n";
    cout << "  PROGRAMA FINALIZADO\n";
    cout << "==============================================\n";
    
    return 0;
}

/*
 * ═══════════════════════════════════════════════════════════════════════════
 *                        RESUMEN DE CONCEPTOS CLAVE
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * REGLAS DE ORO (memoriza esto):
 * ✓ 1. SIEMPRE verificar si el archivo se abrió con is_open()
 * ✓ 2. SIEMPRE cerrar archivos con close()
 * ✓ 3. ofstream para ESCRIBIR, ifstream para LEER, fstream para AMBOS
 * ✓ 4. Usar ios::app para AGREGAR sin borrar contenido
 * ✓ 5. getline() para LÍNEAS completas, >> para PALABRAS
 * ✓ 6. Archivos binarios usan ios::binary, write() y read()
 * ✓ 7. tellg()/tellp() para ver posición, seekg()/seekp() para mover
 *
 * FLUJO BÁSICO DE TRABAJO CON ARCHIVOS:
 * 1. Declarar objeto (ofstream/ifstream/fstream)
 * 2. Abrir archivo (.open() o en constructor)
 * 3. Verificar apertura (if !is_open())
 * 4. Leer/Escribir datos (<< o >> o getline())
 * 5. Cerrar archivo (.close())
 *
 * ERRORES COMUNES A EVITAR:
 * ✗ Olvidar cerrar el archivo → puede perder datos
 * ✗ No verificar is_open() → el programa puede crashear
 * ✗ Usar >> cuando hay espacios → solo lee hasta el primer espacio
 * ✗ Olvidar ios::app → borra todo el contenido existente
 *
 * CASOS DE USO FRECUENTES:
 * • Guardar configuraciones → ofstream + ios::trunc (o solo ofstream)
 * • Logs/Historial → ofstream + ios::app
 * • Leer configuración → ifstream + getline()
 * • Procesar CSV → ifstream + getline() + parsing
 * • Guardar/Cargar datos → Archivos binarios (write/read)
 */