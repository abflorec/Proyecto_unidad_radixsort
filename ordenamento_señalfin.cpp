#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
using namespace std::chrono;

// --- Bubble Sort genérico ---
template<typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    bool cambio;
    do {
        cambio = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                cambio = true;
            }
        }
    } while (cambio);
}

// --- Generación de datos ---
char generarLetra() { return 'a' + rand() % 26; }
string generarPalabra(int longitud = 5) {
    string s = "";
    for (int i = 0; i < longitud; i++) s += generarLetra();
    return s;
}

// --- Programa Principal Burbuja ---
int main() {
    DWORD_PTR mask = 1;
    SetProcessAffinityMask(GetCurrentProcess(), mask);
    srand(2025);

    int n, tipo;
    cout << "Cantidad de elementos a generar: ";
    cin >> n;
    cout << "Tipo de datos (1=Números, 2=Letras, 3=Palabras): ";
    cin >> tipo;

    if (tipo == 1) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = rand() % 100000 + 1;
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto stop = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(stop - start);
        cout << "\nCantidad de datos: " << n << endl;
        cout << "Tiempo Burbuja: " << dur.count() / 1000.0 << " ms\n";
    }
    else if (tipo == 2) {
        vector<char> arr(n);
        for (int i = 0; i < n; i++) arr[i] = generarLetra();
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto stop = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(stop - start);
        cout << "\nCantidad de datos: " << n << endl;
        cout << "Tiempo Burbuja: " << dur.count() / 1000.0 << " ms\n";
    }
    else if (tipo == 3) {
        vector<string> arr(n);
        for (int i = 0; i < n; i++) arr[i] = generarPalabra();
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto stop = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(stop - start);
        cout << "\nCantidad de datos: " << n << endl;
        cout << "Tiempo Burbuja: " << dur.count() / 1000.0 << " ms\n";
    }
    else {
        cout << "Tipo de dato no válido.\n";
    }

    return 0;
}
