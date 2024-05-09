#include "Estacion.h"

Estacion::Estacion(string nombre, bool transferencia) : nombre(nombre), esTransferencia(transferencia) {}

string Estacion::getNombre() const {
    return nombre;
}

bool Estacion::esDeTransferencia() const {
    return esTransferencia;
}

void Estacion::setTransferencia(bool transferencia) {
    esTransferencia = transferencia;
}

int Estacion::getTiempoEstacionAnterior() const {
    return tiempoEstacionAnterior;
}

void Estacion::setTiempoEstacionAnterior(int tiempo) {
    tiempoEstacionAnterior = tiempo;
}

int Estacion::getTiempoEstacionSiguiente() const {
    return tiempoEstacionSiguiente;
}

void Estacion::setTiempoEstacionSiguiente(int tiempo) {
    tiempoEstacionSiguiente = tiempo;
}
