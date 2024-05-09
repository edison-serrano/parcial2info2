#include <iostream>
#include "RedMetro.h"
#include "Linea.h"
#include "Estacion.h"

using namespace std;

void menuPrincipal() {
    cout << "\n=== Menu Principal ===" << endl;
    cout << "1. Red Metro" << endl;
    cout << "2. Linea" << endl;
    cout << "3. Estacion" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void menuRedMetro(RedMetro& redMetro) {
    int opcion;
    while (true) {
        cout << "\n=== Menu Red Metro ===" << endl;
        cout << "1. Ver Red Metro" << endl;
        cout << "2. Crear Red Metro" << endl;
        cout << "3. Eliminar Red Metro" << endl;
        cout << "4. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
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
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

void menuLinea(RedMetro& redMetro) {
    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "\n=== Menu Linea ===" << endl;
        cout << "1. Crear Linea" << endl;
        cout << "2. Agregar Estacion a Linea" << endl;
        cout << "3. Eliminar Estacion de Linea" << endl;
        cout << "4. Ver Numero de Estaciones en Linea" << endl;
        cout << "5. Mostrar Linea" << endl;
        cout << "6. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombreLinea, nombreRed;
            cout << "Ingrese el nombre de la nueva linea: ";
            cin >> nombreLinea;
            cout << "Ingrese el nombre de la red de metro a la que pertenece la linea: ";
            cin >> nombreRed;
            redMetro.crearLinea(nombreLinea, nombreRed);
            cout << "Linea creada exitosamente." << endl;
            break;
        }

        case 2: {
            string nombreLinea, nombreEstacion;
            int posicion;
            cout << "Ingrese el nombre de la linea a la que desea agregar la estacion: ";
            cin >> nombreLinea;
            cout << "Ingrese el nombre de la estacion a agregar: ";
            cin >> nombreEstacion;
            cout << "Ingrese la posicion donde desea agregar la estacion: ";
            cin >> posicion;

            // Crear una nueva instancia de Estacion
            Estacion* nuevaEstacion = new Estacion(nombreEstacion);

            // Verificar si la estación se creo correctamente
            if (nuevaEstacion != nullptr) {
                // Llamar a la función para agregar la estación a la línea
                redMetro.agregarEstacionALinea(nombreLinea, nuevaEstacion, posicion);
            } else {
                cout << "Error al crear la estacion." << endl;
                // Si hubo un error al crear la estación, asegúrate de liberar la memoria
                delete nuevaEstacion;
            }
            break;
        }

        case 3: {
            string nombreLinea, nombreEstacion;
            cout << "Ingrese el nombre de la linea de la que desea eliminar la estacion: ";
            cin >> nombreLinea;
            cout << "Ingrese el nombre de la estacion a eliminar: ";
            cin >> nombreEstacion;
            redMetro.eliminarEstacionDeLinea(nombreLinea, nombreEstacion);
            break;
        }
        case 4: {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            redMetro.verNumeroEstacionesEnLinea(nombreLinea);
            break;
        }
        case 5: {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea que desea ver: ";
            cin >> nombreLinea;
            redMetro.mostrarLinea(nombreLinea);
            break;
        }
        case 6:
            cout << "Saliendo del Menu Linea." << endl;
            salir = true;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    }
}




void menuEstacion(RedMetro& redMetro) {
    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "\n=== Menu Estacion ===" << endl;
        cout << "1. Ver Estaciones Disponibles" << endl;
        cout << "2. Tiempos de Estacion" << endl;
        cout << "3. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea que desea ver: ";
            cin >> nombreLinea;
            redMetro.mostrarLinea(nombreLinea);
            break;
        }
            break;

        case 2:{
            std::string nombreLinea, nombreEstacion;
            int tiempoEstacionAnterior, tiempoEstacionSiguiente;
            cout << "Ingrese el nombre de la línea: ";
            cin >> nombreLinea;
            cout << "Ingrese el nombre de la estación: ";
            cin >> nombreEstacion;
            cout << "Ingrese el tiempo en segundos de la estación anterior: ";
            cin >> tiempoEstacionAnterior;
            cout << "Ingrese el tiempo en segundos de la estación siguiente: ";
            cin >> tiempoEstacionSiguiente;

            redMetro.editarTiempoEstaciones(nombreLinea, nombreEstacion, tiempoEstacionAnterior, tiempoEstacionSiguiente);
            break;
        }
        case 3:
            // Salir del menú estación
            salir = true;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
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
            menuEstacion(redMetro);
            break;
        case 4:
            salir = true;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }



    cout << "¡Hasta luego!" << endl;

    return 0;
}
