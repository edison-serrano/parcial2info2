#include "Linea.h"
#include <iostream>

using namespace std;


// Constructor predeterminado
Linea::Linea() : nombre("Nombre por defecto"), capacidadMaxima(10), estaciones(nullptr), capacidad(0), tamano(0) {
    // Inicializar el arreglo de estaciones con capacidad inicial
    estaciones = new Estacion*[capacidadMaxima];
}

// Constructor con parámetros
Linea::Linea(const string& nombre, int capacidadMaxima, const string& nombreRed) : nombre(nombre), capacidadMaxima(capacidadMaxima), nombreRed(nombreRed), estaciones(nullptr), capacidad(0), tamano(0) {
    // Inicializar el arreglo de estaciones con capacidad inicial
    estaciones = new Estacion*[capacidadMaxima];
}

// Destructor
Linea::~Linea() {
    // Liberar la memoria de cada estación
    for (int i = 0; i < tamano; ++i) {
        delete estaciones[i];
    }
    // Liberar la memoria del arreglo de punteros a estaciones
    delete[] estaciones;
}

// Método para agregar una estación a la línea
void Linea::agregarEstacion(Estacion* estacion, int posicion) {
    if (posicion < 0 || posicion >= capacidadMaxima) {
        cout << "Error: La posicion especificada esta fuera de los limites de la linea." << endl;
        return;
    }

    // Asegurarse de que haya suficiente capacidad para agregar la estación
    if (tamano >= capacidadMaxima) {
        cout << "Error: La linea esta llena, no se puede agregar mas estaciones." << endl;
        return;
    }

    // Preguntar al usuario si la estación es de transferencia
    char esTransferenciaInput;
    cout << "¿Es esta una estacion de transferencia? (S/N): ";
    cin >> esTransferenciaInput;
    bool esTransferencia = (esTransferenciaInput == 'S' || esTransferenciaInput == 's');

    // Asignar el valor de transferencia a la estación
    estacion->setTransferencia(esTransferencia);

    // Si la posición es mayor que el tamaño actual, agregar la estación al final
    if (posicion >= tamano) {
        estaciones[tamano++] = estacion;
    } else {
        // Hacer espacio para la nueva estación
        for (int i = tamano; i > posicion; --i) {
            estaciones[i] = estaciones[i - 1];
        }
        // Agregar la nueva estación en la posición especificada
        estaciones[posicion] = estacion;
        tamano++;
    }
}


// Método para eliminar una estación de la línea
void Linea::eliminarEstacion(Estacion* estacion) {
    if (estacion->esDeTransferencia()) {
        cout << "No se puede eliminar una estacion de transferencia." << endl;
        return;
    }
    bool encontrada = false; // Variable para indicar si se encontró la estación
    for (int i = 0; i < tamano; ++i) {
        if (estaciones[i] == estacion) {
            delete estaciones[i]; // Liberar la memoria de la estación
            estaciones[i] = nullptr; // Establecer el puntero a nullptr
            encontrada = true; // Marcar que se encontró la estación
            break; // Salir del bucle una vez que se elimine la estación
        }
    }

    if (encontrada) {
        // Reorganizar el arreglo para eliminar los nullptr
        int j = 0;
        for (int i = 0; i < tamano; ++i) {
            if (estaciones[i] != nullptr) {
                estaciones[j++] = estaciones[i];
            }
        }
        tamano = j; // Actualizar el tamaño del arreglo
        cout << "Estacion eliminada correctamente de la linea." << endl;
    } else {
        cout << "Error: La estacion no se encontro en la linea." << endl;
    }
}


// Método para obtener una estación por su nombre
Estacion* Linea::obtenerEstacion(const string& nombreEstacion) {
    for (int i = 0; i < tamano; ++i) {
        if (estaciones[i] != nullptr && estaciones[i]->getNombre() == nombreEstacion) {
            return estaciones[i];
        }
    }
    return nullptr; // Si no se encontró la estación, devuelve nullptr
}

// Método para obtener el número de estaciones en la línea
int Linea::getNumeroEstaciones() {
    return tamano;
}

// Método para obtener una representación de cadena de la línea
string Linea::toString() const {
    string infoLinea = "Nombre de la linea: " + nombre + "\n";
    infoLinea += "Capacidad maxima: " + to_string(capacidadMaxima) + "\n";
    infoLinea += "Estaciones en la linea:\n";
    for (int i = 0; i < tamano; ++i) {
        infoLinea += " - " + estaciones[i]->getNombre() + "\n";
    }
    return infoLinea;
}

// Método para obtener el nombre de la línea
string Linea::getNombre() const {
    return nombre;
}



void Linea::editarTiempoEstaciones(const string& nombreEstacion, int tiempoEstacionAnterior, int tiempoEstacionSiguiente) {
    Estacion* estacion = obtenerEstacion(nombreEstacion);
    if (estacion) {
        estacion->setTiempoEstacionAnterior(tiempoEstacionAnterior);
        estacion->setTiempoEstacionSiguiente(tiempoEstacionSiguiente);
    } else {
        cout << "La estacion especificada no existe en esta linea." << endl;
    }
}

void Linea::mostrarEstacionesConTiempos() const {
    cout << "Estaciones en la línea '" << nombre << "':" << endl;
    cout << "--------------------------------------" << endl;

    // Iterar sobre todas las estaciones en la línea
    for (int i = 0; i < tamano; ++i) {
        // Mostrar el nombre de la estación
        cout << i + 1 << ". " << estaciones[i]->getNombre() << endl;

        // Mostrar el tiempo con la estación anterior, excepto para la primera estación
        if (i > 0) {
            cout << "   Tiempo con la estación anterior: " << estaciones[i]->getTiempoEstacionAnterior() << " segundos" << endl;
        }

        // Mostrar el tiempo con la estación siguiente, excepto para la última estación
        if (i < tamano - 1) {
            cout << "   Tiempo con la estación siguiente: " << estaciones[i]->getTiempoEstacionSiguiente() << " segundos" << endl;
        }
    }
}
