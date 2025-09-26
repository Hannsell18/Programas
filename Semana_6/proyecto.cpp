/*
  transporte_estudiantil.cpp
  Proyecto: Sistema de Transporte Estudiantil (POO, C++)
  - Listas fijas y punteros a objetos
  - Herencia, polimorfismo, encapsulamiento
  - Menús, validaciones y reportes
  ------------------------------------
  Compilar (ejemplo):
  g++ -std=c++17 transporte_estudiantil.cpp -o transporte
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

/* ========== CONSTANTES (tamaños de listas fijas) ========== */
const int MAX_CHOFERES = 50;
const int MAX_ESTUDIANTES = 300;
const int MAX_BUSES = 80;
const int MAX_RUTAS = 60;
const int MAX_RESERVACIONES = 1000;

/* ========== CLASES BASE Y DERIVADAS ========== */

class Persona {
protected:
    string nombre;
    string cedula;
public:
    Persona(const string& n, const string& c) : nombre(n), cedula(c) {}
    virtual ~Persona() = default;
    string getCedula() const { return cedula; }
    string getNombre() const { return nombre; }
    virtual void mostrar() const = 0;
};

class Chofer : public Persona {
    string licencia;
    string telefono;
public:
    Chofer(const string& n, const string& c, const string& lic, const string& tel)
        : Persona(n,c), licencia(lic), telefono(tel) {}
    void mostrar() const override {
        cout << "Chofer: " << nombre << " | Cédula: " << cedula
             << " | Lic: " << licencia << " | Tel: " << telefono << '\n';
    }
    string getLicencia() const { return licencia; }
};

class Estudiante : public Persona {
    string carrera;
    string correo;
public:
    Estudiante(const string& n, const string& c, const string& carrera_, const string& correo_)
        : Persona(n,c), carrera(carrera_), correo(correo_) {}
    void mostrar() const override {
        cout << "Estudiante: " << nombre << " | Cédula: " << cedula
             << " | Carrera: " << carrera << " | Correo: " << correo << '\n';
    }
    string getCorreo() const { return correo; }
};

/* ========== VEHÍCULO Y BUS ========== */

class Vehiculo {
protected:
    string placa;
    string modelo;
public:
    Vehiculo(const string& p, const string& m) : placa(p), modelo(m) {}
    virtual ~Vehiculo() = default;
    string getPlaca() const { return placa; }
    virtual void mostrar() const = 0;
};

class Bus : public Vehiculo {
    int capacidad;
    Chofer* choferAsignado; // puntero a chofer (puede ser nullptr)
public:
    Bus(const string& p, const string& m, int cap)
        : Vehiculo(p,m), capacidad(cap), choferAsignado(nullptr) {}
    void asignarChofer(Chofer* c) { choferAsignado = c; }
    Chofer* getChofer() const { return choferAsignado; }
    int getCapacidad() const { return capacidad; }
    void mostrar() const override {
        cout << "Bus: placa=" << placa << " | modelo=" << modelo
             << " | capacidad=" << capacidad;
        if (choferAsignado) cout << " | Chofer: " << choferAsignado->getNombre()
                                  << " (" << choferAsignado->getCedula() << ")";
        else cout << " | Chofer: [No asignado]";
        cout << '\n';
    }
};

/* ========== RUTA Y RESERVACIÓN ========== */

class Ruta {
    string codigo;
    string origen;
    string destino;
    double costoMensual;
    Bus* busAsignado; // puntero a Bus (puede ser nullptr)
public:
    Ruta(const string& cod, const string& ori, const string& dest, double costo)
        : codigo(cod), origen(ori), destino(dest), costoMensual(costo), busAsignado(nullptr) {}
    void asignarBus(Bus* b) { busAsignado = b; }
    Bus* getBus() const { return busAsignado; }
    string getCodigo() const { return codigo; }
    double getCosto() const { return costoMensual; }
    void mostrar() const {
        cout << "Ruta: " << codigo << " | " << origen << " -> " << destino
             << " | Costo: " << costoMensual;
        if (busAsignado) cout << " | Bus: " << busAsignado->getPlaca();
        else cout << " | Bus: [No asignado]";
        cout << '\n';
    }
};

/* Estado de pago: PENDIENTE o PAGADO */
enum EstadoPago { PENDIENTE = 0, PAGADO = 1 };

class Reservacion {
    string id;
    Estudiante* estudiante;
    Ruta* ruta;
    EstadoPago estado;
public:
    Reservacion(const string& id_, Estudiante* e, Ruta* r)
        : id(id_), estudiante(e), ruta(r), estado(PENDIENTE) {}
    string getId() const { return id; }
    Estudiante* getEstudiante() const { return estudiante; }
    Ruta* getRuta() const { return ruta; }
    EstadoPago getEstado() const { return estado; }
    void pagar() { estado = PAGADO; }
    void mostrar() const {
        cout << "ResID: " << id << " | Est: " << estudiante->getNombre()
             << " (" << estudiante->getCedula() << ")"
             << " | Ruta: " << ruta->getCodigo()
             << " | Estado: " << (estado==PAGADO ? "PAGADO" : "PENDIENTE") << '\n';
    }
};

/* ========== SISTEMA (control central) ========== */

class Sistema {
    // arreglos fijos de punteros
    Chofer* choferes[MAX_CHOFERES];
    int nChoferes;

    Estudiante* estudiantes[MAX_ESTUDIANTES];
    int nEstudiantes;

    Bus* buses[MAX_BUSES];
    int nBuses;

    Ruta* rutas[MAX_RUTAS];
    int nRutas;

    Reservacion* reservaciones[MAX_RESERVACIONES];
    int nReservaciones;

public:
    Sistema() : nChoferes(0), nEstudiantes(0), nBuses(0), nRutas(0), nReservaciones(0) {
        srand((unsigned)time(nullptr));
    }

    ~Sistema() {
        // liberar memoria
        for (int i=0;i<nChoferes;i++) delete choferes[i];
        for (int i=0;i<nEstudiantes;i++) delete estudiantes[i];
        for (int i=0;i<nBuses;i++) delete buses[i];
        for (int i=0;i<nRutas;i++) delete rutas[i];
        for (int i=0;i<nReservaciones;i++) delete reservaciones[i];
    }

    /* ---------- UTILIDADES ---------- */
    void pausa() {
        cout << "\nPresione ENTER para continuar...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    string generarIdReservacion() {
        // simple: RES + timestamp + contador
        int r = rand() % 900 + 100;
        time_t t = time(nullptr);
        string s = "RES" + to_string((int)t) + to_string(r);
        return s;
    }

    /* ---------- VALIDADORES / BUSQUEDAS ---------- */

    Chofer* buscarChoferPorCedula(const string& ced) {
        for (int i=0;i<nChoferes;i++) if (choferes[i]->getCedula() == ced) return choferes[i];
        return nullptr;
    }

    Estudiante* buscarEstudiantePorCedula(const string& ced) {
        for (int i=0;i<nEstudiantes;i++) if (estudiantes[i]->getCedula() == ced) return estudiantes[i];
        return nullptr;
    }

    Bus* buscarBusPorPlaca(const string& placa) {
        for (int i=0;i<nBuses;i++) if (buses[i]->getPlaca() == placa) return buses[i];
        return nullptr;
    }

    Ruta* buscarRutaPorCodigo(const string& cod) const {
        for (int i=0;i<nRutas;i++) if (rutas[i]->getCodigo() == cod) return rutas[i];
        return nullptr;
    }

    int contarReservacionesActivasEnRuta(Ruta* r) {
        int c = 0;
        for (int i=0;i<nReservaciones;i++) {
            if (reservaciones[i]->getRuta() == r) c++;
        }
        return c;
    }

    /* ---------- MÓDULOS: Creación / Listado / Búsqueda ---------- */

    void registrarChofer() {
        if (nChoferes >= MAX_CHOFERES) {
            cout << "Error: límite de choferes alcanzado (" << MAX_CHOFERES << ").\n";
            return;
        }
        string nombre, cedula, licencia, telefono;
        cout << "Registrar Chofer\nNombre: "; getline(cin, nombre);
        cout << "Cédula: "; getline(cin, cedula);
        if (buscarChoferPorCedula(cedula)) {
            cout << "Ya existe un chofer con esa cédula.\n"; return;
        }
        cout << "Licencia: "; getline(cin, licencia);
        cout << "Teléfono: "; getline(cin, telefono);
        Chofer* c = new Chofer(nombre, cedula, licencia, telefono);
        choferes[nChoferes++] = c;
        cout << "Chofer registrado correctamente.\n";
    }

    void listarChoferes() const {
        cout << "\n--- Lista de Choferes (" << nChoferes << ") ---\n";
        for (int i=0;i<nChoferes;i++) choferes[i]->mostrar();
    }

    void registrarEstudiante() {
        if (nEstudiantes >= MAX_ESTUDIANTES) {
            cout << "Error: límite de estudiantes alcanzado (" << MAX_ESTUDIANTES << ").\n";
            return;
        }
        string nombre, cedula, carrera, correo;
        cout << "Registrar Estudiante\nNombre: "; getline(cin, nombre);
        cout << "Cédula: "; getline(cin, cedula);
        if (buscarEstudiantePorCedula(cedula)) {
            cout << "Ya existe un estudiante con esa cédula.\n"; return;
        }
        cout << "Carrera: "; getline(cin, carrera);
        cout << "Correo: "; getline(cin, correo);
        Estudiante* e = new Estudiante(nombre, cedula, carrera, correo);
        estudiantes[nEstudiantes++] = e;
        cout << "Estudiante registrado correctamente.\n";
    }

    void listarEstudiantes() const {
        cout << "\n--- Lista de Estudiantes (" << nEstudiantes << ") ---\n";
        for (int i=0;i<nEstudiantes;i++) estudiantes[i]->mostrar();
    }

    void registrarBus() {
        if (nBuses >= MAX_BUSES) {
            cout << "Error: límite de buses alcanzado (" << MAX_BUSES << ").\n";
            return;
        }
        string placa, modelo;
        int cap;
        cout << "Registrar Bus\nPlaca: "; getline(cin, placa);
        if (buscarBusPorPlaca(placa)) { cout << "Ya existe un bus con esa placa.\n"; return; }
        cout << "Modelo: "; getline(cin, modelo);
        cout << "Capacidad (número entero): "; cin >> cap; cin.ignore();
        if (cap <= 0) { cout << "Capacidad inválida.\n"; return; }
        Bus* b = new Bus(placa, modelo, cap);
        buses[nBuses++] = b;
        cout << "Bus registrado correctamente.\n";
    }

    void listarBuses() const {
        cout << "\n--- Lista de Buses (" << nBuses << ") ---\n";
        for (int i=0;i<nBuses;i++) buses[i]->mostrar();
    }

    void registrarRuta() {
        if (nRutas >= MAX_RUTAS) {
            cout << "Error: límite de rutas alcanzado (" << MAX_RUTAS << ").\n"; return;
        }
        string codigo, origen, destino;
        double costo;
        cout << "Registrar Ruta\nCódigo único: "; getline(cin, codigo);
        if (buscarRutaPorCodigo(codigo)) { cout << "Ya existe una ruta con ese código.\n"; return; }
        cout << "Origen: "; getline(cin, origen);
        cout << "Destino: "; getline(cin, destino);
        cout << "Costo mensual (ej: 25000.50): "; cin >> costo; cin.ignore();
        if (costo < 0) { cout << "Costo inválido.\n"; return; }
        Ruta* r = new Ruta(codigo, origen, destino, costo);
        rutas[nRutas++] = r;
        cout << "Ruta registrada correctamente.\n";
    }

    void listarRutas() const {
        cout << "\n--- Lista de Rutas (" << nRutas << ") ---\n";
        for (int i=0;i<nRutas;i++) rutas[i]->mostrar();
    }

    /* ---------- Asignaciones (relaciones) ---------- */

    void asignarChoferABus() {
        cout << "Asignar Chofer a Bus\nPlaca bus: "; string placa; getline(cin, placa);
        Bus* b = buscarBusPorPlaca(placa);
        if (!b) { cout << "Bus no encontrado.\n"; return; }
        cout << "Cédula del chofer a asignar: "; string ced; getline(cin, ced);
        Chofer* c = buscarChoferPorCedula(ced);
        if (!c) { cout << "Chofer no encontrado.\n"; return; }
        b->asignarChofer(c);
        cout << "Chofer asignado al bus.\n";
    }

    void asignarBusARuta() {
        cout << "Asignar Bus a Ruta\nCódigo de ruta: "; string cod; getline(cin, cod);
        Ruta* r = buscarRutaPorCodigo(cod);
        if (!r) { cout << "Ruta no encontrada.\n"; return; }
        cout << "Placa del bus a asignar: "; string placa; getline(cin, placa);
        Bus* b = buscarBusPorPlaca(placa);
        if (!b) { cout << "Bus no encontrado.\n"; return; }
        // comprobar que bus no esté ya asignado a otra ruta (simple check)
        for (int i=0;i<nRutas;i++) {
            if (rutas[i]->getBus() == b) {
                cout << "Este bus ya está asignado a la ruta " << rutas[i]->getCodigo() << '\n';
                return;
            }
        }
        r->asignarBus(b);
        cout << "Bus asignado a la ruta correctamente.\n";
    }

    /* ---------- Reservaciones y pagos ---------- */

    void crearReservacion() {
        if (nReservaciones >= MAX_RESERVACIONES) {
            cout << "Error: límite de reservaciones alcanzado.\n"; return;
        }
        cout << "Crear Reservación\nCédula del estudiante: "; string ced; getline(cin, ced);
        Estudiante* e = buscarEstudiantePorCedula(ced);
        if (!e) { cout << "Estudiante no encontrado.\n"; return; }
        cout << "Código de ruta: "; string cod; getline(cin, cod);
        Ruta* r = buscarRutaPorCodigo(cod);
        if (!r) { cout << "Ruta no encontrada.\n"; return; }
        Bus* b = r->getBus();
        if (!b) { cout << "Esta ruta no tiene un bus asignado aún.\n"; return; }
        int ocupados = contarReservacionesActivasEnRuta(r);
        if (ocupados >= b->getCapacidad()) { cout << "Capacidad del bus alcanzada. No se puede reservar.\n"; return; }
        // evitar reservación duplicada del mismo estudiante en la misma ruta
        for (int i=0;i<nReservaciones;i++) {
            if (reservaciones[i]->getEstudiante() == e && reservaciones[i]->getRuta() == r) {
                cout << "El estudiante ya tiene reservación en esa ruta.\n"; return;
            }
        }
        string id = generarIdReservacion();
        Reservacion* res = new Reservacion(id, e, r);
        reservaciones[nReservaciones++] = res;
        cout << "Reservación creada con ID: " << id << ". Estado: PENDIENTE.\n";
    }

    void listarReservaciones() const {
        cout << "\n--- Reservaciones (" << nReservaciones << ") ---\n";
        for (int i=0;i<nReservaciones;i++) reservaciones[i]->mostrar();
    }

    void pagarReservacion() {
        cout << "Pagar Reservación\nID de reservación: "; string id; getline(cin, id);
        for (int i=0;i<nReservaciones;i++) {
            if (reservaciones[i]->getId() == id) {
                if (reservaciones[i]->getEstado() == PAGADO) { cout << "Reservación ya pagada.\n"; return; }
                reservaciones[i]->pagar();
                cout << "Pago registrado. Reservación marcada como PAGADO.\n";
                return;
            }
        }
        cout << "Reservación no encontrada.\n";
    }

    /* ---------- REPORTES ---------- */

    void reporteEstudiantesPorRuta() const {
        cout << "Reporte: Estudiantes por Ruta\nCódigo de ruta: "; string cod; getline(cin, cod);
        Ruta* r = buscarRutaPorCodigo(cod);
        if (!r) { cout << "Ruta no encontrada.\n"; return; }
        cout << "Ruta " << cod << " - Inscritos:\n";
        int found = 0;
        for (int i=0;i<nReservaciones;i++) {
            if (reservaciones[i]->getRuta() == r) {
                Estudiante* e = reservaciones[i]->getEstudiante();
                cout << " - " << e->getNombre() << " (" << e->getCedula() << ") | Estado: "
                     << (reservaciones[i]->getEstado()==PAGADO ? "PAGADO" : "PENDIENTE") << '\n';
                found++;
            }
        }
        if (!found) cout << "No hay estudiantes inscritos en esta ruta.\n";
    }

    void reporteIngresosPorRuta() const {
        cout << "Reporte: Ingresos por Ruta\n";
        for (int i=0;i<nRutas;i++) {
            Ruta* r = rutas[i];
            double ingresos = 0.0;
            for (int j=0;j<nReservaciones;j++) {
                if (reservaciones[j]->getRuta() == r && reservaciones[j]->getEstado()==PAGADO) {
                    ingresos += r->getCosto();
                }
            }
            cout << "Ruta " << r->getCodigo() << " | Ingresos: " << fixed << setprecision(2) << ingresos << '\n';
        }
    }

    void reporteBusesYChoferes() const {
        cout << "\nReporte: Buses y Choferes asignados\n";
        for (int i=0;i<nRutas;i++) {
            Ruta* r = rutas[i];
            cout << "Ruta " << r->getCodigo() << ": ";
            Bus* b = r->getBus();
            if (!b) cout << "[Sin bus asignado]\n";
            else {
                cout << "Bus " << b->getPlaca() << " - Chofer: ";
                Chofer* c = b->getChofer();
                if (!c) cout << "[Sin chofer asignado]\n";
                else cout << c->getNombre() << " (" << c->getCedula() << ")\n";
            }
        }
    }

    void reporteMorosos() const {
        cout << "\nReporte: Estudiantes morosos (reservación PENDIENTE)\n";
        bool any = false;
        for (int i=0;i<nReservaciones;i++) {
            if (reservaciones[i]->getEstado() == PENDIENTE) {
                reservaciones[i]->mostrar();
                any = true;
            }
        }
        if (!any) cout << "No se encontraron morosos.\n";
    }

    /* ---------- MENÚS ---------- */

    void menuChoferes() {
        while (true) {
            cout << "\n--- Módulo Choferes ---\n";
            cout << "1) Registrar chofer\n2) Listar choferes\n3) Buscar chofer por cédula\n0) Volver\nElija opción: ";
            int op; if (!(cin>>op)) { cin.clear(); cin.ignore(); op=-1; }
            cin.ignore();
            if (op == 1) registrarChofer();
            else if (op == 2) listarChoferes();
            else if (op == 3) {
                cout << "Cédula: "; string ced; getline(cin, ced);
                Chofer* c = buscarChoferPorCedula(ced);
                if (c) c->mostrar(); else cout << "Chofer no encontrado.\n";
            }
            else if (op == 0) break;
            else cout << "Opción inválida.\n";
        }
    }

    void menuBuses() {
        while (true) {
            cout << "\n--- Módulo Buses ---\n";
            cout << "1) Registrar bus\n2) Listar buses\n3) Asignar chofer a bus\n0) Volver\nElija opción: ";
            int op; if (!(cin>>op)) { cin.clear(); cin.ignore(); op=-1; }
            cin.ignore();
            if (op == 1) registrarBus();
            else if (op == 2) listarBuses();
            else if (op == 3) asignarChoferABus();
            else if (op == 0) break;
            else cout << "Opción inválida.\n";
        }
    }

    void menuEstudiantes() {
        while (true) {
            cout << "\n--- Módulo Estudiantes ---\n";
            cout << "1) Registrar estudiante\n2) Listar estudiantes\n3) Buscar estudiante por cédula\n0) Volver\nElija opción: ";
            int op; if (!(cin>>op)) { cin.clear(); cin.ignore(); op=-1; }
            cin.ignore();
            if (op == 1) registrarEstudiante();
            else if (op == 2) listarEstudiantes();
            else if (op == 3) {
                cout << "Cédula: "; string ced; getline(cin, ced);
                Estudiante* e = buscarEstudiantePorCedula(ced);
                if (e) e->mostrar(); else cout << "Estudiante no encontrado.\n";
            }
            else if (op == 0) break;
            else cout << "Opción inválida.\n";
        }
    }

    void menuRutas() {
        while (true) {
            cout << "\n--- Módulo Rutas ---\n";
            cout << "1) Registrar ruta\n2) Listar rutas\n3) Asignar bus a ruta\n0) Volver\nElija opción: ";
            int op; if (!(cin>>op)) { cin.clear(); cin.ignore(); op=-1; }
            cin.ignore();
            if (op == 1) registrarRuta();
            else if (op == 2) listarRutas();
            else if (op == 3) asignarBusARuta();
            else if (op == 0) break;
            else cout << "Opción inválida.\n";
        }
    }

    void menuReservaciones() {
        while (true) {
            cout << "\n--- Módulo Reservaciones y Pagos ---\n";
            cout << "1) Crear reservación\n2) Listar reservaciones\n3) Pagar reservación\n0) Volver\nElija opción: ";
            int op; if (!(cin>>op)) { cin.clear(); cin.ignore(); op=-1; }
            cin.ignore();
            if (op == 1) crearReservacion();
            else if (op == 2) listarReservaciones();
            else if (op == 3) pagarReservacion();
            else if (op == 0) break;
            else cout << "Opción inválida.\n";
        }
    }

    void menuReportes() {
        while (true) {
            cout << "\n--- Módulo Reportes ---\n";
            cout << "1) Estudiantes por ruta\n2) Ingresos por ruta\n3) Buses y choferes asignados\n4) Morosos\n0) Volver\nElija opción: ";
            int op; if (!(cin>>op)) { cin.clear(); cin.ignore(); op=-1; }
            cin.ignore();
            if (op == 1) reporteEstudiantesPorRuta();
            else if (op == 2) reporteIngresosPorRuta();
            else if (op == 3) reporteBusesYChoferes();
            else if (op == 4) reporteMorosos();
            else if (op == 0) break;
            else cout << "Opción inválida.\n";
        }
    }

    void menuPrincipal() {
        while (true) {
            cout << "\n=== SISTEMA TRANSPORTE ESTUDIANTIL ===\n";
            cout << "1) Choferes\n2) Buses\n3) Estudiantes\n4) Rutas\n5) Reservaciones y pagos\n6) Reportes\n0) Salir\nElija opción: ";
            int op; if (!(cin>>op)) { cin.clear(); cin.ignore(); op=-1; }
            cin.ignore();
            if (op == 1) menuChoferes();
            else if (op == 2) menuBuses();
            else if (op == 3) menuEstudiantes();
            else if (op == 4) menuRutas();
            else if (op == 5) menuReservaciones();
            else if (op == 6) menuReportes();
            else if (op == 0) {
                cout << "Saliendo... liberando memoria.\n"; break;
            }
            else cout << "Opción inválida.\n";
        }
    }

    /* ---------- Métodos para facilitar pruebas / demo ---------- */
    void poblarDatosDemo() {
        // agregar algunos choferes
        if (nChoferes < MAX_CHOFERES) choferes[nChoferes++] = new Chofer("José Castro","101010101","B1","88881234");
        if (nChoferes < MAX_CHOFERES) choferes[nChoferes++] = new Chofer("María López","202020202","A2","88882345");
        // estudiantes
        if (nEstudiantes < MAX_ESTUDIANTES) estudiantes[nEstudiantes++] = new Estudiante("Ana Vega","300300300","Ing. Sistemas","ana@mail.cr");
        if (nEstudiantes < MAX_ESTUDIANTES) estudiantes[nEstudiantes++] = new Estudiante("Carlos Mora","400400400","Ing. Computación","carlos@mail.cr");
        // buses
        if (nBuses < MAX_BUSES) buses[nBuses++] = new Bus("P-ABC-001","Mercedes 2015",40);
        if (nBuses < MAX_BUSES) buses[nBuses++] = new Bus("P-XYZ-002","Volvo 2018",30);
        // asignar choferes a buses
        buses[0]->asignarChofer(choferes[0]);
        buses[1]->asignarChofer(choferes[1]);
        // rutas
        if (nRutas < MAX_RUTAS) rutas[nRutas++] = new Ruta("R001","Campo A","Sede Central",15000.00);
        if (nRutas < MAX_RUTAS) rutas[nRutas++] = new Ruta("R002","Barrio B","Sede Central",12000.00);
        // asignar buses a rutas
        rutas[0]->asignarBus(buses[0]);
        rutas[1]->asignarBus(buses[1]);
        // reservaciones
        if (nReservaciones < MAX_RESERVACIONES)
            reservaciones[nReservaciones++] = new Reservacion(generarIdReservacion(), estudiantes[0], rutas[0]);
        if (nReservaciones < MAX_RESERVACIONES)
            reservaciones[nReservaciones++] = new Reservacion(generarIdReservacion(), estudiantes[1], rutas[1]);
        // marcar una como pagada
        if (nReservaciones > 0) reservaciones[0]->pagar();
    }
};

/* ========== MAIN ========== */

int main() {
    Sistema sys;
    cout << "Sistema Transporte Estudiantil - Demo\n";
    cout << "Poblando datos de ejemplo...\n";
    sys.poblarDatosDemo();
    sys.menuPrincipal();
    cout << "Programa finalizado.\n";
    return 0;
}
