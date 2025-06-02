#include <stdio.h>
#include <stdlib.h>


// Función para imprimir una matriz
void imprimirMatriz(double matriz[][10], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para realizar eliminación gaussiana
void gaussEliminacion(double matriz[][10], int filas, int columnas) {
    int i, j, k;
    double factor;

    // Eliminación hacia adelante
    for (i = 0; i < filas - 1; i++) {
        for (j = i + 1; j < filas; j++) {
            factor = matriz[j][i] / matriz[i][i];
            for (k = i; k < columnas; k++) {
                matriz[j][k] -= factor * matriz[i][k];
            }
        }
    }
}

// Función para resolver el sistema de ecuaciones mediante sustitución hacia atrás
double * gaussSustitucion(double matriz[][10], int filas, int columnas) {
    int i, j;
    double *solucion = (double *)malloc((filas) * sizeof(double));

    // Sustitución hacia atrás
    for (i = filas - 1; i >= 0; i--) {
        solucion[i] = matriz[i][columnas - 1];
        for (j = i + 1; j < filas; j++) {
            solucion[i] -= matriz[i][j] * solucion[j];
        }
        solucion[i] /= matriz[i][i];
    }

    return solucion;
}

int main() {
    int filas, columnas, i, j;
    double matriz[10][10];

    // Obtener el número de filas y columnas
    printf("Ingrese el número de filas (debe ser igual al número de columnas): ");
    scanf("%d", &filas);
    columnas = filas + 1;  // La matriz aumentada tiene una columna más

    // Ingresar los coeficientes de la matriz y la columna de términos independientes
    printf("Ingrese los coeficientes de la matriz aumentada:\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    // Imprimir la matriz original
    printf("\nMatriz aumentada:\n");
    imprimirMatriz(matriz, filas, columnas);

    // Realizar la eliminación gaussiana
    gaussEliminacion(matriz, filas, columnas);

    // Imprimir la matriz después de la eliminación
    printf("\nMatriz después de la eliminación gaussiana:\n");
    imprimirMatriz(matriz, filas, columnas);

    // Resolver el sistema mediante sustitución hacia atrás
    double *solucion = gaussSustitucion(matriz, filas, columnas);

    // Imprimir la solución
    printf("\nSolución del sistema:\n");
    for (i = 0; i < filas; i++) {
        printf("x%d = %.2lf\n", i + 1, solucion[i]);
    }

    // Liberar la memoria
    free(solucion);

    
return 0;

}