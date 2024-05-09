#include "RedMetro.h"
#include "Linea.h"
#include <iostream>



using namespace std;



RedMetro::RedMetro(const string& nombre) : redes(nullptr), numRedes(0), capacidadRedes(0), lineas(nullptr), numLineas(0), capacidadLineas(0) {
    // Inicializar el arreglo de líneas con la capacidad adecuada
    lineas = new Linea[capacidadLineas];
    // Llenar el arreglo de líneas con objetos Linea inicializados
    for (int i = 0; i < capacidadLineas; ++i) {
        // Inicializar cada objeto Linea con el constructor proporcionado
        lineas[i] = Linea("Nombre de la línea", 10, nombre); // Reemplaza "Nombre de la línea" con el nombre deseado y 10 con la capacidad máxima deseada
    }
}


RedMetro::~RedMetro() {
    delete[] redes;
}




void RedMetro::crearRedMetro(const string& nombreRed) {
    if (numRedes == capacidadRedes) {
        // Si el arreglo está lleno, ampliamos su capacidad
        capacidadRedes = (capacidadRedes == 0) ? 1 : capacidadRedes * 2;
        RedInfo* nuevoArreglo = new RedInfo[capacidadRedes];
        // Copiamos los datos del arreglo anterior al nuevo
        for (int i = 0; i < numRedes; ++i) {
            nuevoArreglo[i] = redes[i];
        }
        delete[] redes;
        redes = nuevoArreglo;
    }
    // Creamos la nueva red
    redes[numRedes].nombre = nombreRed;
    numRedes++;
    cout << "Se ha creado la red de metro '" << nombreRed << "'." << endl;
}

void RedMetro::verRedesDisponibles() {
    if (numRedes == 0) {
        cout << "No hay redes de metro disponibles." << endl;
    } else {
        cout << "Redes de metro disponibles:" << endl;
        for (int i = 0; i < numRedes; ++i) {
            cout << "- " << redes[i].nombre << endl;
        }
    }
}


void RedMetro::eliminarRedMetro(const string& nombreRed) {
    // Buscar la red con el nombre dado
    int indice = -1;
    for (int i = 0; i < numRedes; ++i) {
        if (redes[i].nombre == nombreRed) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        // Solicitar confirmación al usuario
        char confirmacion;
        cout << "¿Esta seguro de que desea eliminar la red de metro '" << nombreRed << "'? (S/N): ";
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            // Eliminar la red encontrada
            for (int i = indice; i < numRedes - 1; ++i) {
                redes[i] = redes[i + 1];
            }
            numRedes--;
            cout << "Red de metro '" << nombreRed << "' eliminada exitosamente." << endl;
        } else {
            cout << "Operacion cancelada. La red de metro '" << nombreRed << "' no ha sido eliminada." << endl;
        }
    } else {
        // La red no existe
        cout << "La red de metro '" << nombreRed << "' no existe." << endl;
    }
}

// Implementación del método crearLinea
void RedMetro::crearLinea(const string& nombreLinea, const string& nombreRed) {
    if (numLineas == capacidadLineas) {
        // Si el arreglo está lleno, ampliamos su capacidad
        capacidadLineas = (capacidadLineas == 0) ? 1 : capacidadLineas * 2;
        Linea* nuevoArreglo = new Linea[capacidadLineas];
        // Copiamos los datos del arreglo anterior al nuevo
        for (int i = 0; i < numLineas; ++i) {
            nuevoArreglo[i] = lineas[i];
        }
        delete[] lineas;
        lineas = nuevoArreglo;
    }
    // Creamos la nueva línea
    lineas[numLineas] = Linea(nombreLinea, 10, nombreRed); // Reemplaza 10 con la capacidad máxima deseada
    numLineas++;
    cout << "Se ha creado la linea '" << nombreLinea << "' en la red '" << nombreRed << "'." << endl;
}



// Obtener una línea por su nombre
Linea* RedMetro::obtenerLineaPorNombre(const string& nombre) const {
    for (int i = 0; i < numLineas; ++i) {
        if (lineas[i].getNombre() == nombre) {
            return &lineas[i];
        }
    }
    return nullptr; // Si no se encuentra la línea
}

void RedMetro::agregarEstacionALinea(const string& nombreLinea, Estacion* estacion, int posicion) {
    Linea* linea = obtenerLineaPorNombre(nombreLinea);
    if (linea) {
        linea->agregarEstacion(estacion, posicion);
    } else {
        cout << "La linea especificada no existe." << endl;
    }
}


Estacion* RedMetro::obtenerEstacionPorNombre(const string& nombreEstacion) const {
    // Iterar sobre todas las líneas y buscar la estación en cada una
    for (int i = 0; i < numLineas; ++i) {
        // Obtener la línea actual
        Linea lineaActual = lineas[i];
        // Obtener la estación actual de esta línea
        Estacion* estacion = lineaActual.obtenerEstacion(nombreEstacion);
        // Si se encuentra la estación, devolverla
        if (estacion != nullptr) {
            return estacion;
        }
    }
    // Si no se encuentra la estación en ninguna línea, devolver nullptr
    return nullptr;
}


void RedMetro::eliminarEstacionDeLinea(const std::string& nombreLinea, const string& nombreEstacion) {
    Linea* linea = obtenerLineaPorNombre(nombreLinea); // Obtener la línea por su nombre
    if (linea) {
        Estacion* estacion = linea->obtenerEstacion(nombreEstacion); // Obtener la estación por su nombre
        if (estacion) {
            if (estacion->esDeTransferencia()) {
                cout << "No se puede eliminar una estacion de transferencia." << endl;
            } else {
                linea->eliminarEstacion(estacion); // Eliminar la estación de la línea
                cout << "Estacion '" << nombreEstacion << "' eliminada de la linea '" << nombreLinea << "'." << endl;
            }
        } else {
            cout << "La estacion '" << nombreEstacion << "' no se encontro en la linea '" << nombreLinea << "'." << endl;
        }
    } else {
        cout << "La linea '" << nombreLinea << "' no existe." << endl;
    }
}


void RedMetro::verNumeroEstacionesEnLinea(const string& nombreLinea) const {
    Linea* linea = obtenerLineaPorNombre(nombreLinea);
    if (linea) {
        cout << "Numero de estaciones en la linea '" << nombreLinea << "': " << linea->getNumeroEstaciones() << endl;
    } else {
        cout << "La linea '" << nombreLinea << "' no existe." << endl;
    }
}


void RedMetro::mostrarLinea(const std::string& nombreLinea) const {
    // Buscar la línea por su nombre
    Linea* linea = obtenerLineaPorNombre(nombreLinea);

    // Verificar si la línea existe
    if (linea) {
        // Mostrar las estaciones de la línea con los tiempos
        cout << "Estaciones en la línea '" << nombreLinea << "':" << endl;
        linea->mostrarEstacionesConTiempos();
    } else {
        cout << "La línea '" << nombreLinea << "' no existe." << endl;
    }
}


void RedMetro::editarTiempoEstaciones(const string& nombreLinea, const string& nombreEstacion, int tiempoEstacionAnterior, int tiempoEstacionSiguiente) {
    Linea* linea = obtenerLineaPorNombre(nombreLinea);
    if (linea) {
        linea->editarTiempoEstaciones(nombreEstacion, tiempoEstacionAnterior, tiempoEstacionSiguiente);
    } else {
        cout << "La linea especificada no existe." << endl;
    }
}
