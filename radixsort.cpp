#include <iostream>
#include <vector>
using namespace std;

// Función para obtener el dígito máximo
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal)
            maxVal = num;
    }
    return maxVal;
}

// Conteo de sort por dígito
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Contar ocurrencias de cada dígito
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Acumulado
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construir arreglo ordenado
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copiar de vuelta al arreglo original
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nLista original: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "\nLista ordenada (Radix Sort): ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
