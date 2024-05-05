#include "Linea.h"
#include <iostream>

using namespace std;


// Implementación del constructor
Linea::Linea(std::string nombre, int capacidad) : nombre(nombre), capacidad(capacidad), tamano(0) {
    estaciones = new Estacion*[capacidad];
}

// Implementación del destructor
Linea::~Linea() {
    delete[] estaciones;
}

// Implementación del método agregarEstacion
void Linea::agregarEstacion(Estacion* estacion, int posicion) {
    if (posicion < 0 || posicion > tamano || tamano == capacidad) {
        std::cout << "Error: No se puede agregar la estación en la posición especificada." << std::endl;
        return;
    }

    for (int i = tamano; i > posicion; --i) {
        estaciones[i] = estaciones[i - 1];
    }
    estaciones[posicion] = estacion;
    tamano++;
}

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
            } else {
                delete estaciones[i]; // Liberar la memoria de la estación nullptr
            }
        }
        tamano = j; // Actualizar el tamaño del arreglo
        cout << "Estación eliminada correctamente de la línea." << endl;
    } else {
        cout << "Error: La estación no se encontró en la línea." << endl;
    }
}


Estacion* Linea::obtenerEstacion(const string& nombreEstacion) {
    for (int i = 0; i < tamano; ++i) {
        if (estaciones[i] != nullptr && estaciones[i]->nombre == nombreEstacion) {
            return estaciones[i];
        }
    }
    return nullptr; // Si no se encontró la estación, devuelve nullptr
}







// Implementación del método getNumeroEstaciones
int Linea::getNumeroEstaciones() {
    return tamano;
}

// Implementación del método toString
std::string Linea::toString() {
    std::string result = "Linea: " + nombre + "\n";
    result += "Estaciones:\n";
    for (int i = 0; i < tamano; ++i) {
        result += estaciones[i]->nombre + "\n";
    }
    return result;
}
