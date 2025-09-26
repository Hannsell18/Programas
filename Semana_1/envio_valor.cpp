void cambiarValor(int numero) {
    numero = 100; // Solo cambia la COPIA de la variable
}

int main() {
    int miNumero = 5;
    cambiarValor(miNumero);
    // miNumero sigue siendo 5
    return 0;
}

