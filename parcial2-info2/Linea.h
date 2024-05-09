#ifndef LINEA_H
#define LINEA_H

#include <string>
#include "Estacion.h"

using namespace std;

class Linea {
private:
    string nombre;
    Estacion** estaciones;
    int capacidad;
    int capacidadMaxima;
    int tamano;

public:
    Linea();
    Linea(const string& nombre, int capacidadMaxima);
    ~Linea();

    Estacion* obtenerEstacion(const string& nombreEstacion);
    void agregarEstacion(Estacion* estacion, int posicion);
    void eliminarEstacion(Estacion* estacion);
    int getNumeroEstaciones();
    string toString() const;
    string getNombre() const;
    void editarTiempoEstaciones(const string& nombreEstacion, int tiempoEstacionAnterior, int tiempoEstacionSiguiente);
    void mostrarEstacionesConTiempos() const;
};

#endif
