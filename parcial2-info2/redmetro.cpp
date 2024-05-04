#include "redmetro.h"


using namespace std;

RedMetro::RedMetro(const string& nombre) : nombre(nombre) {}

RedMetro::~RedMetro() {
    for (Linea* linea : lineas) {
        delete linea;
    }
}

void RedMetro::agregarLinea(Linea* linea) {
    lineas.push_back(linea);
}

void RedMetro::eliminarLinea(Linea* linea) {
    // Implementar eliminación de la línea si es necesario
}

int RedMetro::getNumeroLineas() const {
    return lineas.size();
}

int RedMetro::getNumeroEstaciones() const {
    int totalEstaciones = 0;
    for (Linea* linea : lineas) {
        totalEstaciones += linea->getNumeroEstaciones();
    }
    return totalEstaciones;
}

bool RedMetro::isEstacionEnLinea(Estacion* estacion, Linea* linea) const {
    // Implementar lógica para verificar si una estación pertenece a una línea
    return false;
}

string RedMetro::toString() const {
    // Implementar la representación en cadena de la red de metro
    return "";
}
