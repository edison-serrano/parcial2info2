#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include <vector>
#include "linea.h"


using namespace std;
class RedMetro {
private:
    string nombre;
    vector<Linea*> lineas;

public:
    RedMetro(const string& nombre);
    ~RedMetro();

    void agregarLinea(Linea* linea);
    void eliminarLinea(Linea* linea);
    int getNumeroLineas() const;
    int getNumeroEstaciones() const;
    bool isEstacionEnLinea(Estacion* estacion, Linea* linea) const;
    string toString() const;
};

#endif // REDMETRO_H
