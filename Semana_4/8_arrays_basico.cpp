#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int* p = arr; // arr equivale a &arr[0]

    cout << "Primer elemento: " << *p << endl;     // 10
    cout << "Segundo elemento: " << *(p+1) << endl; // 20
    cout << "Tercer elemento: " << *(p+2) << endl; // 30

    return 0;
}

// arr es la dirección del primer elemento (&arr[0]).
// *(p+1) significa "el valor en la posición siguiente".
