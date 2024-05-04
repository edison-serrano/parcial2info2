#include "linea.h"

using namespace std;

Linea::Linea(const string& nombre, RedMetro* redMetro) : nombre(nombre), redMetro(redMetro) {}

Linea::~Linea() {
    for (Estacion* estacion : estaciones) {
        delete estacion;
    }
}

void Linea::agregarEstacion(Estacion* estacion) {
    estaciones.push_back(estacion);
}

void Linea::eliminarEstacion(Estacion* estacion) {
    // Implementar eliminación de la estación si es necesario
}

int Linea::getNumeroEstaciones() const {
    return estaciones.size();
}

string Linea::toString() const {
    // Implementar la representación en cadena de la línea
    return "";
}
