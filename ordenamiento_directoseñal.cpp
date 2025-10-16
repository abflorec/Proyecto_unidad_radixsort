#include <iostream>
using namespace std;

void intercambioPorSenal(int arr[], int n) {
    int limite = n - 1;
    while (limite > 0) {
        int ultimaIntercambio = 0;
        for (int i = 0; i < limite; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                ultimaIntercambio = i;
            }
        }
        limite = ultimaIntercambio;
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    // Crear arreglo dinámico
    int* arr = new int[n];

    cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nLista original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    intercambioPorSenal(arr, n);

    cout << "\nLista ordenada: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Liberar memoria dinámica
    delete[] arr;

    return 0;
}
