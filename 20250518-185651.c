#include <stdio.h>
#include <stdlib.h>

#define MAX_FILAS 20
#define MAX_COLUMNAS 21 // Una columna adicional para la matriz aumentada

// Función para imprimir una matriz
void imprimirMatriz(double matriz[][MAX_COLUMNAS], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j <= filas; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para realizar eliminación gaussiana
void gaussEliminacion(double matriz[][MAX_COLUMNAS], int filas) {
    for (int i = 0; i < filas - 1; i++) {
        // Pivoteo parcial
        int maxIndice = i;
        for (int k = i + 1; k < filas; k++) {
            if (fabs(matriz[k][i]) > fabs(matriz[maxIndice][i])) {
                maxIndice = k;
            }
        }
        if (maxIndice != i) {
            for (int j = 0; j <= filas; j++) {
                double temp = matriz[i][j];
                matriz[i][j] = matriz[maxIndice][j];
                matriz[maxIndice][j] = temp;
            }
        }

        // Eliminación
        for (int j = i + 1; j < filas; j++) {
            double factor = matriz[j][i] / matriz[i][i];
            for (int k = i; k <= filas; k++) {
                matriz[j][k] -= factor * matriz[i][k];
            }
        }
    }
}

// Función para resolver el sistema de ecuaciones mediante sustitución hacia atrás
void gaussSustitucion(double matriz[][MAX_COLUMNAS], int filas, double *solucion) {
    for (int i = filas - 1; i >= 0; i--) {
        solucion[i] = matriz[i][filas];
        for (int j = i + 1; j < filas; j++) {
            solucion[i] -= matriz[i][j] * solucion[j];
        }
        solucion[i] /= matriz[i][i];
    }
}

int main() {
    int filas;
    printf("Ingrese el número de filas (hasta %d): ", MAX_FILAS);
    scanf("%d", &filas);

    if (filas > MAX_FILAS) {
        printf("El número de filas es demasiado grande.\n");
        return 1;
    }

    double matriz[MAX_FILAS][MAX_COLUMNAS];
    printf("Ingrese los coeficientes de la matriz aumentada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j <= filas; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("\nMatriz aumentada:\n");
    imprimirMatriz(matriz, filas);

    gaussEliminacion(matriz, filas);
    printf("\nMatriz después de la eliminación gaussiana:\n");
    imprimirMatriz(matriz, filas);

    double solucion[MAX_FILAS];
    gaussSustitucion(matriz, filas, solucion);
    printf("\nSolución del sistema:\n");
    for (int i = 0; i < filas; i++) {
        printf("x%d = %.2lf\n", i + 1, solucion[i]);
    }

    return 0;
}