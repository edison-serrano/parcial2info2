#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include "Linea.h"

using namespace std;

class RedMetro {
private:
    struct RedInfo {
        string nombre;
        // Aquí podrías agregar más información sobre la red si es necesario
    };

    RedInfo* redes;         // Arreglo para almacenar múltiples redes
    int numRedes;           // Número de redes actualmente almacenadas
    int capacidadRedes;     // Capacidad máxima del arreglo
    Linea* lineas;         // Arreglo para almacenar múltiples líneas
    int numLineas;         // Número de líneas actualmente almacenadas
    int capacidadLineas;   // Capacidad máxima del arreglo
    Linea* obtenerLinea(const string& nombreLinea);
    int capacidadMaxima;     // Capacidad máxima de una línea



public:
    Linea* obtenerLineaPorNombre(const string& nombre) const;
    RedMetro(const string& nombre);
    ~RedMetro();

    void crearRedMetro(const string& nombreRed);
    void verRedesDisponibles(); // Función para mostrar las redes disponibles
    void eliminarRedMetro(const string& nombreRed);
    void crearLinea(const string& nombreLinea);
    //void crearLinea(const string& nombreLinea); // Método para crear una nueva línea
    void verLineasDisponibles();
    void agregarEstacionALinea(const string& nombreLinea, Estacion* estacion, int posicion);
    Estacion* obtenerEstacionPorNombre(const string& nombreEstacion) const;
    void eliminarEstacionDeLinea(const string& nombreLinea, const string& nombreEstacion);
    void verNumeroEstacionesEnLinea(const string& nombreLinea) const;
    void mostrarLinea(const string& nombreLinea) const;

};

#endif // REDMETRO_H
