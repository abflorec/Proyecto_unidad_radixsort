#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;
using namespace std::chrono;
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
        n--; 
    } while (cambio);
}
char generarLetra() { return 'a' + rand() % 26; }
string generarPalabra(int longitud = 5) {
    string s = "";
    for (int i = 0; i < longitud; i++)
        s += generarLetra();
    return s;
}
template<typename T>
void guardarEnArchivo(const vector<T>& arr, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    for (auto &elem : arr)
        archivo << elem << "\n";
    archivo.close();
}
int main() {
    DWORD_PTR mask = 1;
    SetProcessAffinityMask(GetCurrentProcess(), mask);
    srand(2025);

    int n, tipo;
    cout << "Cantidad de elementos: ";
    cin >> n;
    cout << "Tipo de datos (1=Num, 2=Letras, 3=Palabras): ";
    cin >> tipo;

    if (tipo == 1) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = rand() % 100000 + 1;

        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto stop = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(stop - start);

        cout << "Tiempo Bubble Sort: " << dur.count() / 1000.0 << " ms\n";
        guardarEnArchivo(arr, "bubble_numeros.txt");
    }
    else if (tipo == 2) {
        vector<char> arr(n);
        for (int i = 0; i < n; i++) arr[i] = generarLetra();

        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto stop = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(stop - start);

        cout << "Tiempo Bubble Sort: " << dur.count() / 1000.0 << " ms\n";
        guardarEnArchivo(arr, "bubble_letras.txt");
    }
    else if (tipo == 3) {
        vector<string> arr(n);
        for (int i = 0; i < n; i++) arr[i] = generarPalabra();

        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto stop = high_resolution_clock::now();
        auto dur = duration_cast<microseconds>(stop - start);

        cout << "Tiempo Bubble Sort: " << dur.count() / 1000.0 << " ms\n";
        guardarEnArchivo(arr, "bubble_palabras.txt");
    }
    else {
        cout << "Tipo de dato no valido.\n";
    }

    return 0;
}
