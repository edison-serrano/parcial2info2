#include "estacion.h"



using namespace std;

Estacion::Estacion(const string& nombre, Linea* linea, int tiempoAnterior, int tiempoSiguiente, bool esTransferencia)
    : nombre(nombre), linea(linea), tiempoAnterior(tiempoAnterior), tiempoSiguiente(tiempoSiguiente), esTransferencia(esTransferencia) {}

int Estacion::getTiempoLlegada(Estacion* destino) const {
    // Implementar la lógica para calcular el tiempo de llegada a una estación destino
    return 0;
}

string Estacion::toString() const {
    // Implementar la representación en cadena de la estación
    return "";
}
