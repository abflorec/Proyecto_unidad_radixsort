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
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) if (num > maxVal) maxVal = num;
    return maxVal;
}

void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        int index = (arr[i]/exp)%10;
        output[count[index]-1] = arr[i];
        count[index]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp=1; maxVal/exp>0; exp*=10)
        countSort(arr, exp);
}

void radixSort(vector<char>& arr) {
    vector<char> output(arr.size());
    int count[256] = {0};
    for (char c : arr) count[(unsigned char)c]++;
    for (int i = 1; i < 256; i++) count[i]+=count[i-1];
    for (int i = arr.size()-1; i>=0; i--){
        output[count[(unsigned char)arr[i]]-1] = arr[i];
        count[(unsigned char)arr[i]]--;
    }
    arr = output;
}

void radixSort(vector<string>& arr){
    int maxLen = 0;
    for (auto &s: arr) if ((int)s.size()>maxLen) maxLen = s.size();
    for (auto &s: arr) while ((int)s.size()<maxLen) s+=' ';

    for (int pos = maxLen-1; pos>=0; pos--){
        vector<string> output(arr.size());
        int count[256]={0};
        for (auto &s: arr) count[(unsigned char)s[pos]]++;
        for (int i=1;i<256;i++) count[i]+=count[i-1];
        for (int i=arr.size()-1;i>=0;i--){
            char c=arr[i][pos];
            output[count[(unsigned char)c]-1]=arr[i];
            count[(unsigned char)c]--;
        }
        arr=output;
    }

    for (auto &s: arr) while (!s.empty() && s.back()==' ') s.pop_back();
}

char generarLetra() { return 'a' + rand()%26; }
string generarPalabra(int longitud=5){
    string s="";
    for (int i=0;i<longitud;i++) s+=generarLetra();
    return s;
}
template<typename T>
void guardarEnArchivo(const vector<T>& arr, const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    for (auto &elem: arr) archivo << elem << "\n";
    archivo.close();
}
int main(){
    DWORD_PTR mask = 1;
    SetProcessAffinityMask(GetCurrentProcess(), mask);
    srand(2025);

    int n, tipo;
    cout << "Cantidad de elementos: ";
    cin >> n;
    cout << "Tipo de datos (1=Num,2=Letras,3=Palabras): ";
    cin >> tipo;

    if(tipo==1){
        vector<int> arr(n);
        for(int i=0;i<n;i++) arr[i]=rand()%100000+1;
        auto start=high_resolution_clock::now();
        radixSort(arr);
        auto stop=high_resolution_clock::now();
        auto dur=duration_cast<microseconds>(stop-start);
        cout<<"Tiempo Radix Sort: "<<dur.count()/1000.0<<" ms\n";
        guardarEnArchivo(arr,"radix_numeros.txt");
    } else if(tipo==2){
        vector<char> arr(n);
        for(int i=0;i<n;i++) arr[i]=generarLetra();
        auto start=high_resolution_clock::now();
        radixSort(arr);
        auto stop=high_resolution_clock::now();
        auto dur=duration_cast<microseconds>(stop-start);
        cout<<"Tiempo Radix Sort: "<<dur.count()/1000.0<<" ms\n";
        guardarEnArchivo(arr,"radix_letras.txt");
    } else if(tipo==3){
        vector<string> arr(n);
        for(int i=0;i<n;i++) arr[i]=generarPalabra();
        auto start=high_resolution_clock::now();
        radixSort(arr);
        auto stop=high_resolution_clock::now();
        auto dur=duration_cast<microseconds>(stop-start);
        cout<<"Tiempo Radix Sort: "<<dur.count()/1000.0<<" ms\n";
        guardarEnArchivo(arr,"radix_palabras.txt");
    }
    return 0;
}
