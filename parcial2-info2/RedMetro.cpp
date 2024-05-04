#include "RedMetro.h"
#include <iostream>

RedMetro::RedMetro(const string& nombre) : redes(nullptr), numRedes(0), capacidadRedes(0) {}

RedMetro::~RedMetro() {
    delete[] redes;
}

void RedMetro::crearRedMetro(const std::string& nombreRed) {
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
    std::cout << "Se ha creado la red de metro '" << nombreRed << "'." << std::endl;
}

void RedMetro::verRedesDisponibles() {
    if (numRedes == 0) {
        std::cout << "No hay redes de metro disponibles." << std::endl;
    } else {
        std::cout << "Redes de metro disponibles:" << std::endl;
        for (int i = 0; i < numRedes; ++i) {
            std::cout << "- " << redes[i].nombre << std::endl;
        }
    }
}
