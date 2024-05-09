#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include "Linea.h"

using namespace std;

class RedMetro {
private:
    // Estructura interna para almacenar información de la red
    struct RedInfo {
        string nombre;
        // Aquí podrías agregar más información sobre la red si es necesario
    };

    RedInfo* redes;         // Arreglo para almacenar múltiples redes
    int numRedes;           // Número de redes actualmente almacenadas
    int capacidadRedes;     // Capacidad máxima del arreglo
    Linea* lineas;          // Arreglo para almacenar múltiples líneas
    int numLineas;          // Número de líneas actualmente almacenadas
    int capacidadLineas;    // Capacidad máxima del arreglo

    Linea* obtenerLineaPorNombre(const string& nombre) const;

public:
    RedMetro(const string& nombre);
    ~RedMetro();

    void crearRedMetro(const string& nombreRed);
    void verRedesDisponibles();
    void eliminarRedMetro(const string& nombreRed);
    void crearLinea(const string& nombreLinea, const string& nombreRed);
    void agregarEstacionALinea(const string& nombreLinea, Estacion* estacion, int posicion);
    void eliminarEstacionDeLinea(const string& nombreLinea, const string& nombreEstacion);
    void verNumeroEstacionesEnLinea(const string& nombreLinea) const;
    void mostrarLinea(const string& nombreLinea) const;
    void editarTiempoEstaciones(const string& nombreLinea, const string& nombreEstacion, int tiempoEstacionAnterior, int tiempoEstacionSiguiente);

    Estacion* obtenerEstacionPorNombre(const string& nombreEstacion) const;

};

#endif
