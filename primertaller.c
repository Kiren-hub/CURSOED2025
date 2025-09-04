#include <stdio.h>
#define TAM 10

void llenarArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int num;
        int valid;
        do {
            printf("Ingrese el numero %d (entero positivo): ", i+1);
            valid = scanf("%d", &num); // Guardamos el retorno de scanf
            
            if (valid != 1) {
                printf("Error: debe ingresar un numero entero.\n");
                while (getchar() != '\n'); // limpiar buffer
            } else if (num <= 0) {
                printf("Error: el numero debe ser entero positivo.\n");
            }
        } while (valid != 1 || num <= 0);
        a[i] = num;
    }
}

void mostrarArray(int a[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n-1) printf(", ");
    }
    printf("]\n");
}

void ordenarSelectionAscendente(int a[], int n) {
    int arr[TAM];
    for (int i = 0; i < n; i++) arr[i] = a[i];
    printf("\n-- Selection Sort Ascendente --\n");
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        printf("Paso %d: ", i+1);
        mostrarArray(arr, n);
    }
    printf("Resultado final (asc): ");
    mostrarArray(arr, n);
}

void ordenarInsertionDescendente(int a[], int n) {
    int arr[TAM];
    for (int i = 0; i < n; i++) arr[i] = a[i];
    printf("\n-- Insertion Sort Descendente --\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Paso %d: ", i);
        mostrarArray(arr, n);
    }
    printf("Resultado final (desc): ");
    mostrarArray(arr, n);
}

int main() {
    int a[TAM];
    int opcion;
    int valid;
    int arrayLlenado = 0;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Registrar enteros (llenar array)\n");
        printf("2. Mostrar array original\n");
        printf("3. Ordenar con Selection Sort (ascendente)\n");
        printf("4. Ordenar con Insertion Sort (descendente)\n");
        printf("5. Salir\n");

        // Validar entrada del menú
        do {
            printf("Seleccione una opcion: ");
            valid = scanf("%d", &opcion);
            if (valid != 1) {
                printf("Error: debe ingresar un numero entero.\n");
                while (getchar() != '\n'); // limpiar buffer
            }
        } while (valid != 1);
        
        switch(opcion) {
            case 1:
                llenarArray(a, TAM);
                arrayLlenado = 1;
                break;
            case 2:
                if (arrayLlenado)
                    mostrarArray(a, TAM);
                else
                    printf("Primero debe registrar el array.\n");
                break;
            case 3:
                if (arrayLlenado)
                    ordenarSelectionAscendente(a, TAM);
                else
                    printf("Primero debe registrar el array.\n");
                break;
            case 4:
                if (arrayLlenado)
                    ordenarInsertionDescendente(a, TAM);
                else
                    printf("Primero debe registrar el array.\n");
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 5);
    return 0;
}
