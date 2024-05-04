#include <iostream>
#include "RedMetro.h"
#include "Linea.h"
#include "Estacion.h"

using namespace std;

void menuPrincipal() {
    cout << "\n=== Menú Principal ===" << endl;
    cout << "1. Red Metro" << endl;
    cout << "2. Linea" << endl;
    cout << "3. Estacion" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void menuRedMetro(RedMetro& redMetro) {
    cout << "\n=== Menú Red Metro ===" << endl;
    cout << "1. Ver Red Metro" << endl;
    cout << "2. Crear Red Metro" << endl;
    cout << "3. Eliminar Red Metro" << endl;
    cout << "4. Volver al Menú Principal" << endl;
    cout << "Seleccione una opción: ";
}

void menuLinea() {
    cout << "\n=== Menú Linea ===" << endl;
    cout << "1. Ver Lineas Disponibles" << endl;
    cout << "2. Crear Linea" << endl;
    cout << "3. Editar Linea" << endl;
    cout << "4. Eliminar Linea" << endl;
    cout << "5. Volver al Menú Principal" << endl;
    cout << "Seleccione una opción: ";
}

void menuEstacion() {
    cout << "\n=== Menú Estacion ===" << endl;
    cout << "1. Ver Estaciones Disponibles" << endl;
    cout << "2. Crear Estacion" << endl;
    cout << "3. Editar Estacion" << endl;
    cout << "4. Eliminar Estacion" << endl;
    cout << "5. Volver al Menú Principal" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    bool salir = false;
    RedMetro redMetro("Nombre Predeterminado");

    while (!salir) {
        menuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            while (true) {
                menuRedMetro(redMetro);
                cin >> opcion;

                switch (opcion) {
                case 1:
                    // Implementar ver red metro
                    redMetro.verRedesDisponibles();
                    break;
                case 2: {
                    string nombreRed;
                    cout << "Ingrese el nombre de la nueva red de metro: ";
                    cin >> nombreRed;
                    redMetro.crearRedMetro(nombreRed);
                    cout << "Red de metro creada exitosamente." << endl;
                    break;
                }
                case 3:
                    // Implementar eliminar red metro
                    break;
                case 4:
                    // Volver al menú principal
                    break;
                default:
                    cout << "Opción inválida. Intente de nuevo." << endl;
                }

                if (opcion == 4) {
                    break;
                }
            }
            break;
        case 2:
            // Implementar menú de línea
            break;
        case 3:
            // Implementar menú de estación
            break;
        case 4:
            salir = true;
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }

    cout << "¡Hasta luego!" << endl;

    return 0;
}
