#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal)
            maxVal = num;
    }
    return maxVal;
}

void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

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
    cout << "Ingrese la cantidad de elementos a generar: ";
    cin >> n;

    vector<int> arr(n);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000 + 1; // genera números entre 1 y 99999
    }

    cout << "\nLista generada (" << n << " elementos):\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 20 == 0) cout << endl;
    }

    cout << "\n\nIniciando ordenamiento...\n";

    auto start = high_resolution_clock::now();
    radixSort(arr);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nLista ordenada:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 20 == 0) cout << endl;
    }

    cout << "\n\nTiempo de ejecucion con " << n << " datos: "
         << duration.count() << " microsegundos ("
         << duration.count() / 1000.0 << " milisegundos)\n";

    return 0;
}
