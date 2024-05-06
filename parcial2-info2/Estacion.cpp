#include "Estacion.h"

using namespace std;

// Implementación de constructor
Estacion::Estacion(string nombre) : nombre(nombre) {
    // Código del constructor si es necesario
}

string Estacion::getNombre() const {
    return nombre;
}
