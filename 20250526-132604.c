#include <stdio.h>
#include <stdlib.h>

int main() {

    int x, i;

    int *ptr;

    printf("Ingresa el tamaño del arreglo: ");

    scanf("%d", &x);

    if (x <= 0) {

        printf("El tamaño del arreglo debe ser un entero positivo.\n");

        return 1;
    }

    ptr =(int *)malloc(x * 4);


    if (ptr == NULL) {

        printf("Error: No se pudo asignar memoria.\n");

        return 1;

    }

    for (i = 0; i < x; i++) {

        printf("Ingresa el valor para el elemento %d: ", i + 1);

        scanf("%d", (ptr + i));
    }
    printf("Los valores del arreglo son:\n");

    for (i = 0; i < x; i++) {

        printf("%d ", *(ptr +i));
    }
    printf("\n");

    free(ptr);

    return 0;

}