#include "funciones.h"
#include <iostream>
#include <fstream>  // 🆕 Para manejo de archivos
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// ... (todas las otras funciones arriba)

void guardarEnArchivo(const vector<int>& arr, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo); // Abre el archivo para escribir

    if (!archivo) {
        cout << "Error al crear el archivo.\n";
        return;
    }

    for (int i = 0; i < arr.size(); i++)
        archivo << arr[i] << "\n";

    archivo.close();
    cout << "Datos guardados en: " << nombreArchivo << endl;
}
