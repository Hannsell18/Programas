void cambiarReferencia(int &numero) {
    numero = 100; // Cambia la variable ORIGINAL
}

int main() {
    int miNumero = 5;
    cambiarReferencia(miNumero);
    // miNumero ahora es 100
    return 0;
}