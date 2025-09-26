#include <iostream>

double convertirAFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

int main() {
    double tempCelsius;
    
    std::cout << "Ingrese la temperatura en Celsius: ";
    std::cin >> tempCelsius;
    
    double tempFahrenheit = convertirAFahrenheit(tempCelsius);
    
    std::cout << "La temperatura en Fahrenheit es: " << tempFahrenheit << std::endl;
    
    return 0;
}