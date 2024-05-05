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
    int opcion;
    while (true) {
        cout << "\n=== Menú Red Metro ===" << endl;
        cout << "1. Ver Red Metro" << endl;
        cout << "2. Crear Red Metro" << endl;
        cout << "3. Eliminar Red Metro" << endl;
        cout << "4. Volver al Menú Principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
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
        case 3: {
            string nombreRed;
            cout << "Ingrese el nombre de la red de metro a eliminar: ";
            cin >> nombreRed;
            redMetro.eliminarRedMetro(nombreRed);
            cout << "Red de metro eliminada exitosamente." << endl;
            break;
        }
        case 4:
            // Volver al menú principal
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }
}

void menuLinea(RedMetro& redMetro) {
    Linea linea("Linea 1", 5);
    Estacion* nuevaEstacion = nullptr; // Declarar la variable fuera del bucle

    int opcion;
    while (true) {
        cout << "\n=== Menú Línea ===" << endl;
        cout << "1. Agregar Estación a Línea" << endl;
        cout << "2. Eliminar Estación de Línea" << endl;
        cout << "3. Ver Número de Estaciones en Línea" << endl;
        cout << "4. Mostrar Línea" << endl;
        cout << "5. Volver al Menú Principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombreEstacion;
            int posicion;
            cout << "Ingrese el nombre de la estación a agregar: ";
            cin >> nombreEstacion;
            cout << "Ingrese la posición donde desea agregar la estación: ";
            cin >> posicion;
            nuevaEstacion = new Estacion(nombreEstacion);
            linea.agregarEstacion(nuevaEstacion, posicion);
            cout << "Estación creada correctamente en la línea." << endl;
            break;
        }
        case 2: {
            if (linea.getNumeroEstaciones() == 0) {
                cout << "No hay estaciones en la línea para eliminar." << endl;
            } else {
                string nombreEstacion;
                cout << "Ingrese el nombre de la estación que desea eliminar: ";
                cin >> nombreEstacion;
                Estacion* estacion = nullptr;
                // Obtener la estación por su nombre
                // Aquí necesitas implementar un método en la clase Linea que busque y devuelva una estación por su nombre
                if ((estacion = linea.obtenerEstacion(nombreEstacion)) != nullptr) {
                    linea.eliminarEstacion(estacion);
                } else {
                    cout << "La estación '" << nombreEstacion << "' no se encontró en la línea." << endl;
                }
            }
            break;
        }
        case 3: {
            cout << "Número de estaciones: " << linea.getNumeroEstaciones() << endl;
            break;
        }
        case 4: {
            cout << linea.toString() << endl;
            break;
        }
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            break;
        }
    }

    // Liberar la memoria asignada dinámicamente al salir del bucle
    if (nuevaEstacion) {
        delete nuevaEstacion;
    }
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
            menuRedMetro(redMetro);
            break;
        case 2:
            menuLinea(redMetro);
            break;
        case 3:
            menuEstacion();
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

