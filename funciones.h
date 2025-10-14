#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>
#include <chrono>
using namespace std;

void generarDatos(vector<int>& arr, int cantidad);
void mostrarArreglo(const vector<int>& arr);
void intercambioDirecto(vector<int>& arr);
void radixSort(vector<int>& arr);
void medirTiempo(void (*funcion)(vector<int>&), vector<int> arr, const string& nombre);
void guardarEnArchivo(const vector<int>& arr, const string& nombreArchivo); // 🆕 NUEVA FUNCIÓN

#endif
