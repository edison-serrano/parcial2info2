#include "Linea.h"
#include <iostream>

using namespace std;


// Constructor predeterminado
Linea::Linea() : nombre("Nombre por defecto"), capacidadMaxima(10), estaciones(nullptr), capacidad(0), tamano(0) {
    // Inicializar el arreglo de estaciones con capacidad inicial
    estaciones = new Estacion*[capacidadMaxima];
}

// Constructor con parámetros
Linea::Linea(const string& nombre, int capacidadMaxima) : nombre(nombre), capacidadMaxima(capacidadMaxima), estaciones(nullptr), capacidad(0), tamano(0) {
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
    if (posicion < 0 || posicion > tamano || tamano == capacidadMaxima) {
        cout << "Error: No se puede agregar la estación en la posición especificada o la línea está llena." << endl;
        return;
    }

    // Hacer espacio para la nueva estación
    for (int i = tamano; i > posicion; --i) {
        estaciones[i] = estaciones[i - 1];
    }
    // Agregar la nueva estación
    estaciones[posicion] = estacion;
    tamano++;
}

// Método para eliminar una estación de la línea
void Linea::eliminarEstacion(Estacion* estacion) {
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
        cout << "Estación eliminada correctamente de la línea." << endl;
    } else {
        cout << "Error: La estación no se encontró en la línea." << endl;
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
    string infoLinea = "Nombre de la línea: " + nombre + "\n";
    infoLinea += "Capacidad máxima: " + to_string(capacidadMaxima) + "\n";
    infoLinea += "Estaciones en la línea:\n";
    for (int i = 0; i < tamano; ++i) {
        infoLinea += " - " + estaciones[i]->getNombre() + "\n";
    }
    return infoLinea;
}

// Método para obtener el nombre de la línea
string Linea::getNombre() const {
    return nombre;
}






