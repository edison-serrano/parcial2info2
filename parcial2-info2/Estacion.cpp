#include "Estacion.h"

using namespace std;

// Implementación del constructor
Estacion::Estacion(string nombre, bool transferencia) : nombre(nombre), esTransferencia(transferencia) {}

// Implementación del método getter para obtener el nombre de la estación
string Estacion::getNombre() const {
    return nombre;
}

// Implementación del método getter para verificar si la estación es de transferencia
bool Estacion::esDeTransferencia() const {
    return esTransferencia;
}

// Implementación del método setter para establecer si la estación es de transferencia o no
void Estacion::setTransferencia(bool transferencia) {
    esTransferencia = transferencia;
}
