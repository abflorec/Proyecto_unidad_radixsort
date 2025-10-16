Proyecto Radix Sort – Benchmark y Visualización
Objetivos:
Implementar el algoritmo Radix Sort para números, letras y palabras.
Medir el tiempo de ejecución del algoritmo para distintos tamaños de entrada.
Guardar los resultados en archivos .txt para su visualización con Python.
Generar gráficas de los datos ordenados y la frecuencia de elementos.
Cómo compilar:
Usar este comando en el g++ o MingGW
g++ -std=c++17 -O2 -o radix_sort main.cpp 
Cómo ejecutar el benchmark
Ejecuta el programa compilado:
radix_sort.exe 
Ingresa la cantidad de elementos y el tipo de datos:
1 → Números
2 → Letras
3 → Palabras
El programa generará los archivos:
radix_numeros.txt
radix_letras.txt
radix_palabras.txt
El tiempo de ejecución se mostrará en milisegundos.
Cómo regenerar tablas y figuras:
Python (recomendado con pip install pandas matplotlib):
python graficar_todo_radixsort.py

Versiones de compilador y SO
Compilador C++: g++ 12.2
Sistema Operativo: Windows 10 x64
Python: 3.14
Librerías: pandas, matplotlib
Semillas y reproducibilidad
Semilla utilizada en C++: 2025
Esto asegura que los números, letras y palabras generadas sean reproducibles.
Commit hash de la versión final
Último commit: 
