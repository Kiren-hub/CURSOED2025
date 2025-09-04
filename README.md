# Primer Taller

## Descripción breve
Este programa permite registrar 10 enteros positivos, mostrar el arreglo original, ordenarlo de forma ascendente con Selection Sort y descendente con Insertion Sort, mostrando el proceso paso a paso y el resultado final.

## Ejemplo de salida
```
===== MENU =====
1. Registrar enteros (llenar array)
2. Mostrar array original
3. Ordenar con Selection Sort (ascendente)
4. Ordenar con Insertion Sort (descendente)
5. Salir
Seleccione una opcion: 1
Ingrese el tiempo 1 (entero positivo): 5
... (más entradas)

===== MENU =====
2. Mostrar array original
[5, 8, 3, 7, 2, 9, 1, 4, 6, 10]

===== MENU =====
3. Ordenar con Selection Sort (ascendente)
Paso 1: [1, 8, 3, 7, 2, 9, 5, 4, 6, 10]
... (más pasos)
Resultado final (asc): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

===== MENU =====
4. Ordenar con Insertion Sort (descendente)
Paso 1: [8, 5, 3, 7, 2, 9, 1, 4, 6, 10]
... (más pasos)
Resultado final (desc): [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
```

## Cómo compilar y ejecutar

Abre una terminal en la carpeta `actividades` y ejecuta:

```
gcc primertaller.c -o primertaller.exe
primertaller.exe
```
