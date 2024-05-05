#ifndef LINEA_H
#define LINEA_H

#include <string>
#include "Estacion.h"

// Clase Linea
class Linea {
private:
    std::string nombre;
    Estacion** estaciones;
    int capacidad;
    int tamano;

public:
    Linea(std::string nombre, int capacidad);
    ~Linea();


    Estacion* obtenerEstacion(const std::string& nombreEstacion);
    void agregarEstacion(Estacion* estacion, int posicion);
    void eliminarEstacion(Estacion* estacion);
    int getNumeroEstaciones();
    std::string toString();
};

#endif


