/*
  Taller de Aplicación: Recursividad y Gestión de Datos Académicos en C
  Compilación: gcc taller.c -o taller.exe
*/

#include <stdio.h>

typedef struct {
    int codigo;
    float nota;
} Estudiante;

// ---------------------- FUNCIONES RECURSIVAS ----------------------

// 1. Nota máxima
float maxNota(Estudiante est[], int n, int i, float max) {
    if (i == n) return max; // Caso base: se recorrió todo el arreglo
    if (est[i].nota > max) max = est[i].nota;
    return maxNota(est, n, i + 1, max); // Llamado recursivo
}

// 2. Suma de notas para promedio
float sumaNotas(Estudiante est[], int n, int i) {
    if (i == n) return 0; // Caso base: fin del arreglo
    return est[i].nota + sumaNotas(est, n, i + 1); // Recursión
}

float promedioNotas(Estudiante est[], int n) {
    return sumaNotas(est, n, 0) / n;
}

// 3. Selection Sort recursivo por código
void swap(Estudiante *a, Estudiante *b) {
    Estudiante temp = *a;
    *a = *b;
    *b = temp;
}

int minIndex(Estudiante est[], int start, int n, int minPos) {
    if (start == n) return minPos; // Caso base
    if (est[start].codigo < est[minPos].codigo)
        minPos = start;
    return minIndex(est, start + 1, n, minPos); // Recursión
}

void selectionSortRec(Estudiante est[], int start, int n) {
    if (start == n - 1) return; // Caso base: solo queda un elemento
    int minPos = minIndex(est, start, n, start);
    if (minPos != start) swap(&est[start], &est[minPos]);
    selectionSortRec(est, start + 1, n); // Recursión para el resto
}

// ---------------------- FUNCIONES DE UTILIDAD ----------------------

void mostrarEstudiantes(Estudiante est[], int n) {
    for (int i = 0; i < n; i++)
        printf("Codigo: %d  Nota: %.2f\n", est[i].codigo, est[i].nota);
}

// ---------------------- PROGRAMA PRINCIPAL ------------------------

int main() {
    //lista predefinida de estudiantes
    Estudiante estudiantes[] = {
        {2024101, 4.5},
        {2024102, 3.2},
        {2024103, 4.0},
        {2024104, 2.8},
        {2024105, 3.9}
    };
    int n = sizeof(estudiantes)/sizeof(estudiantes[0]);

    int opcion;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Buscar nota maxima (Recursivo)\n");
        printf("2. Calcular promedio del curso (Recursivo)\n");
        printf("3. Ordenar codigos (Selection Sort Recursivo)\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Nota maxima: %.2f\n", maxNota(estudiantes, n, 0, estudiantes[0].nota));
                break;
            case 2:
                printf("Promedio del curso: %.2f\n", promedioNotas(estudiantes, n));
                break;
            case 3:
                selectionSortRec(estudiantes, 0, n);
                printf("Estudiantes ordenados por codigo:\n");
                mostrarEstudiantes(estudiantes, n);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}
