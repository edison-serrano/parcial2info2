#ifndef ESTACION_H
#define ESTACION_H

#include <string>

using namespace std;
class Linea; // Forward declaration

class Estacion {
private:
    string nombre;
    Linea* linea;
    int tiempoAnterior;
    int tiempoSiguiente;
    bool esTransferencia;

public:
    Estacion(const string& nombre, Linea* linea, int tiempoAnterior, int tiempoSiguiente, bool esTransferencia);
    int getTiempoLlegada(Estacion* destino) const;
    string toString() const;
};

#endif // ESTACION_H
