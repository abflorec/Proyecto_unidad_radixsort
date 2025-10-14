#include <iostream>
#include <vector>
#include "funciones.h"
using namespace std;

int main() {
    vector<int> datos;
    int opcion, cantidad;

    do {
        cout << "\n========= MENU DE ORDENAMIENTO =========\n";
        cout << "1. Generar 100 datos\n";
        cout << "2. Generar 1000 datos\n";
        cout << "3. Generar 10000 datos\n";
        cout << "4. Ejecutar Intercambio Directo\n";
        cout << "5. Ejecutar RadixSort\n";
        cout << "6. Guardar datos en archivo\n";  // 🆕 nueva opción
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cantidad = 100;
                generarDatos(datos, cantidad);
                cout << "Se generaron " << cantidad << " datos.\n";
                mostrarArreglo(datos);
                break;
            case 2:
                cantidad = 1000;
                generarDatos(datos, cantidad);
                cout << "Se generaron " << cantidad << " datos.\n";
                mostrarArreglo(datos);
                break;
            case 3:
                cantidad = 10000;
                generarDatos(datos, cantidad);
                cout << "Se generaron " << cantidad << " datos.\n";
                mostrarArreglo(datos);
                break;
            case 4:
                if (datos.empty()) cout << "Primero genere los datos.\n";
                else medirTiempo(intercambioDirecto, datos, "Intercambio Directo");
                break;
            case 5:
                if (datos.empty()) cout << "Primero genere los datos.\n";
                else medirTiempo(radixSort, datos, "Radix Sort");
                break;
            case 6:
                if (datos.empty()) cout << "No hay datos para guardar.\n";
                else guardarEnArchivo(datos, "datos_generados.txt");
                break;
            case 7:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 7);

    return 0;
}
