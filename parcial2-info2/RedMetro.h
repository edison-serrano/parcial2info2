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

public:
    RedMetro(const string& nombre);
    ~RedMetro();

    void crearRedMetro(const string& nombreRed);
    void verRedesDisponibles(); // Función para mostrar las redes disponibles
    void eliminarRedMetro(const string& nombreRed);
};

#endif // REDMETRO_H
