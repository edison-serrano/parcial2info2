#ifndef LINEA_H
#define LINEA_H

#include <string>
#include "Estacion.h"

using namespace std;

// Clase Linea
class Linea {
private:
    string nombre;
    Estacion** estaciones;
    int capacidad;
    int capacidadMaxima;
    int numeroEstaciones;
    int tamano;

public:
    Linea();
    Linea(const string& nombre, int capacidadMaxima);
    //Linea(std::string nombre, int capacidadMaxima);
    Linea(string nombre);

    ~Linea();


    Estacion* obtenerEstacion(const string& nombreEstacion);
    void agregarEstacion(Estacion* estacion, int posicion);
    void eliminarEstacion(Estacion* estacion);
    int getNumeroEstaciones();
    string toString() const;
    string getNombre() const;
};

#endif


