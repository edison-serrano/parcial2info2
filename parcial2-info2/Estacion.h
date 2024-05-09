#ifndef ESTACION_H
#define ESTACION_H

#include <string>

using namespace std;

class Estacion {
private:
    string nombre;
    bool esTransferencia;
    int tiempoEstacionAnterior;
    int tiempoEstacionSiguiente;

public:
    Estacion(string nombre, bool transferencia = false);
    string getNombre() const;
    bool esDeTransferencia() const;
    void setTransferencia(bool transferencia);
    int getTiempoEstacionAnterior() const;
    void setTiempoEstacionAnterior(int tiempo);
    int getTiempoEstacionSiguiente() const;
    void setTiempoEstacionSiguiente(int tiempo);
};

#endif
