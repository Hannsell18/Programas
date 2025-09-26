#include <iostream>
#include <string>

// Clase base 1: Mensajero
class Mensajero {
    protected:
        bool estadoDeConexion; 
    public:
        // El constructor usa 'this' para evitar ambigüedad.
        Mensajero(bool conectado = false) {
            this->estadoDeConexion = conectado;
        }

        void enviarMensaje(const std::string& destino, const std::string& mensaje) {
            std::cout << "Mensaje enviado a " << destino << ": " << mensaje << std::endl;
        }

        void conectar() {
            this->estadoDeConexion = true;
            std::cout << "Conectado al servidor de mensajeria." << std::endl;
        }
};

// Clase base 2: Almacenamiento
class Almacenamiento {
    protected:
        int espacioDisponible;
    public:
        // El constructor usa 'this' para evitar ambigüedad.
        Almacenamiento(int espacio = 0) {
            this->espacioDisponible = espacio;
        }

        void guardarArchivo(const std::string& nombreArchivo) {
            if (this->espacioDisponible > 0) {
                std::cout << "Archivo '" << nombreArchivo << "' guardado exitosamente." << std::endl;
                this->espacioDisponible--; // Simulación de uso de espacio
            } else {
                std::cout << "No hay espacio disponible para guardar el archivo." << std::endl;
            }
        }
};

// Clase derivada: ClienteCloud que hereda públicamente de ambas
class ClienteCloud : public Mensajero, public Almacenamiento {
    public:
        // Constructor de ClienteCloud. Llama a los constructores de las clases base
        // para inicializar sus atributos.
        ClienteCloud(bool conexionInicial, int espacioInicial) 
            : Mensajero(conexionInicial), Almacenamiento(espacioInicial) {}
            
        void subirYNotificar(const std::string& nombreArchivo, const std::string& destinatario) {
            // 'this' es opcional aquí pero lo usamos para enfatizar que se accede a
            // un miembro de la instancia actual.
            if (this->estadoDeConexion) {
                std::cout << "Estado de conexion: Conectado." << std::endl;
                
                // Llama al método heredado de Almacenamiento
                this->guardarArchivo(nombreArchivo);
                
                // Llama al método heredado de Mensajero
                std::string mensajeNotificacion = "Archivo '" + nombreArchivo + "' subido a la nube.";
                this->enviarMensaje(destinatario, mensajeNotificacion);
            } else {
                std::cout << "Error: No se puede subir el archivo. No hay conexion." << std::endl;
            }
        }
};

int main() {
    // Crear un objeto ClienteCloud, inicializando sus atributos heredados a través del constructor.
    ClienteCloud miCliente(true, 1000);

    std::cout << "\n--- Iniciando la subida y notificacion ---\n";
    // Llamar al método que usa la funcionalidad de ambas clases padre
    miCliente.subirYNotificar("mi_informe_final.docx", "equipo_trabajo");

    return 0;
}