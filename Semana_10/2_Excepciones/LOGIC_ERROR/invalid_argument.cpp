#include <iostream>
#include <stdexcept>

void establecerTemperatura(int temp) {
    if (temp < -273) {  // Menor al cero absoluto
        throw std::invalid_argument("Temperatura imposible fisicamente");
    }
    std::cout << "Temperatura establecida: " << temp << "°C" << std::endl;
}

int main() {
    try {
        establecerTemperatura(25);    // OK
        establecerTemperatura(-300);  // ERROR
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*
Salida:
Temperatura establecida: 25°C
Error: Temperatura imposible físicamente
*/