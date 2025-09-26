#include <iostream>
#include <string>
/*

// EJEMPLO CON CIN
// Se usa para leer palabras o valores individuales.
// Se detiene cuando encuentra un espacio, tabulación o salto de línea.


int main() {
    std::string nombre;
    int edad;

    std::cout << "Ingrese su nombre y edad: ";
    std::cin >> nombre >> edad; // Problema si el nombre es "Juan Pérez"
    
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
    // Si el usuario ingresa "Juan Pérez 25", la salida será:
    // Nombre: Juan, Edad: 0. El "Pérez" y 25 se queda en el búfer.
    return 0;
}

*/

/*
int main() {
    std::string nombre_completo;

    std::cout << "Ingrese su nombre completo: ";
    std::getline(std::cin, nombre_completo); // Lee la línea completa
    
    std::cout << "Hola, " << nombre_completo << "." << std::endl;
    // Si el usuario ingresa "Juan Pérez", la salida será:
    // Hola, Juan Pérez.
    return 0;
}

*/
int main(){
    int edad;
    std::string nombre;

    // Cuando se usa cin antes de getline, queda un enter (\n) pendiente en el buffer,
    //y getline lo lee como si fuera una línea vacía.
    std::cout << "Ingresa tu edad: ";
    std::cin >> edad;

    // std::cin.ignore();

    std::cout << "Ingresa tu nombre completo: ";
    std::getline(std::cin, nombre); // Aquí leerá una línea vacía
    std::cout << "Hola, " << nombre << " tienes "<< edad << " anios." << std::endl;
}


/*
En resumen:
 - Usa cin para números o palabras sueltas.
 - Usa getline para frases completas o entradas con espacios.
*/
