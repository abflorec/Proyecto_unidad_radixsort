import os
import pandas as pd
import matplotlib.pyplot as plt
from collections import Counter
carpeta_output = "C:/Users/mipc/Desktop/PROYECTO UNIDAD 1/output"
carpeta_resultados = "C:/Users/mipc/Desktop/PROYECTO UNIDAD 1/results"

os.makedirs(carpeta_resultados, exist_ok=True)
archivos = {
    "Radix Números": "radix_numeros.txt",
    "Radix Letras": "radix_letras.txt",
    "Radix Palabras": "radix_palabras.txt",
    "Bubble Números": "bubble_numeros.txt",
    "Bubble Letras": "bubble_letras.txt"
}
for tipo, nombre in archivos.items():
    ruta = os.path.join(carpeta_output, nombre)
    
    if not os.path.isfile(ruta):
        print(f"[!] Archivo no encontrado: {ruta}")
        continue
    
    print(f"[+] Procesando {tipo} desde {nombre}...")

    if "Números" in tipo:
        datos = pd.read_csv(ruta, header=None, names=["Valor"])
        valores = datos["Valor"].tolist()
        
        csv_path = os.path.join(carpeta_resultados, f"{tipo.replace(' ','_')}.csv")
        datos.to_csv(csv_path, index=False)
        
        plt.figure(figsize=(12,6))
        plt.plot(valores, marker='o', linestyle='-', markersize=4)
        plt.title(f"Visualización de datos ordenados: {tipo}")
        plt.xlabel("Índice")
        plt.ylabel("Valor")
        plt.grid(True)
        plt.savefig(os.path.join(carpeta_resultados, f"{tipo.replace(' ','_')}.png"))
        plt.close()
    
    elif "Letras" in tipo:
        with open(ruta) as f:
            datos = f.read().splitlines()
        conteo = Counter(datos)
        
        df = pd.DataFrame(conteo.items(), columns=["Letra", "Frecuencia"])
        csv_path = os.path.join(carpeta_resultados, f"{tipo.replace(' ','_')}.csv")
        df.to_csv(csv_path, index=False)
        
        plt.figure(figsize=(10,5))
        plt.bar(conteo.keys(), conteo.values(), color='skyblue' if "Radix" in tipo else 'orange')
        plt.title(f"Frecuencia de letras: {tipo}")
        plt.xlabel("Letra")
        plt.ylabel("Frecuencia")
        plt.savefig(os.path.join(carpeta_resultados, f"{tipo.replace(' ','_')}.png"))
        plt.close()
    elif "Palabras" in tipo:
        with open(ruta) as f:
            datos = f.read().splitlines()
        conteo = Counter(datos)
        palabras, freqs = zip(*conteo.most_common(10))
        
        df = pd.DataFrame({"Palabra": palabras, "Frecuencia": freqs})
        csv_path = os.path.join(carpeta_resultados, f"{tipo.replace(' ','_')}_Top10.csv")
        df.to_csv(csv_path, index=False)
        
        plt.figure(figsize=(12,6))
        plt.bar(palabras, freqs, color='lightgreen')
        plt.title(f"Frecuencia de palabras (Top 10): {tipo}")
        plt.xlabel("Palabra")
        plt.ylabel("Frecuencia")
        plt.xticks(rotation=45)
        plt.grid(axis='y')
        plt.savefig(os.path.join(carpeta_resultados, f"{tipo.replace(' ','_')}_Top10.png"))
        plt.close()

print("\n[ok] Todos los resultados se han guardado en la carpeta 'results/'.")
