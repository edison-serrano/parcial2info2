#ifndef ESTACION_H
#define ESTACION_H

#include <string>

using namespace std;

// Clase Estacion
class Estacion {
public:
    string nombre;
    // Otros atributos de la estación, como coordenadas, por ejemplo

    Estacion(string nombre);
    // Otros métodos de la estación

    string getNombre() const;
};

#endif
