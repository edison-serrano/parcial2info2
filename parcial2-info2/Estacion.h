#ifndef ESTACION_H
#define ESTACION_H

#include <string>

using namespace std;

class Estacion {
private:
    string nombre;
    bool esTransferencia;

public:
    Estacion(string nombre, bool transferencia = false);
    string getNombre() const;
    bool esDeTransferencia() const;
    void setTransferencia(bool transferencia); // Nuevo método para establecer si la estación es de transferencia
};

#endif
