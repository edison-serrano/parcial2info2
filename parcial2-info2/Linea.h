#ifndef LINEA_H
#define LINEA_H

#include <string>
#include <vector>
#include "Estacion.h"



using namespace std;
class RedMetro; // Forward declaration

class Linea {
private:
    string nombre;
    RedMetro* redMetro;
    vector<Estacion*> estaciones;

public:
    Linea(const string& nombre, RedMetro* redMetro);
    ~Linea();

    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(Estacion* estacion);
    int getNumeroEstaciones() const;
    string toString() const;
};

#endif // LINEA_H
