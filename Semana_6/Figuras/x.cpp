// La clase base común
class Pokemon {
public:
    int nivel;
};

// Herencia virtual: las clases intermedias usan 'virtual'
class TipoAgua : virtual public Pokemon {};
class TipoTierra :virtual public Pokemon {};

// La clase más derivada hereda de ambas y las une
class Swampert : public TipoAgua, public TipoTierra {};

int main() {
    Swampert swampert;
    swampert.nivel = 50; // Ahora no hay ambigüedad.
    // ...
}
