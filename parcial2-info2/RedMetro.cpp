#include "RedMetro.h"
#include <iostream>



using namespace std;
RedMetro::RedMetro(const string& nombre) : redes(nullptr), numRedes(0), capacidadRedes(0) {}

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
        cout << "¿Está seguro de que desea eliminar la red de metro '" << nombreRed << "'? (S/N): ";
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            // Eliminar la red encontrada
            for (int i = indice; i < numRedes - 1; ++i) {
                redes[i] = redes[i + 1];
            }
            numRedes--;
            cout << "Red de metro '" << nombreRed << "' eliminada exitosamente." << endl;
        } else {
            cout << "Operación cancelada. La red de metro '" << nombreRed << "' no ha sido eliminada." << endl;
        }
    } else {
        // La red no existe
        cout << "La red de metro '" << nombreRed << "' no existe." << endl;
    }
}

