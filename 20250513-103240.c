#include <stdio.h>
#include <stdlib.h>
int main() {

    int tabla = 5;

    int limite = 10;

    int resultados (limite); 
    
    tabla_multiplicar (tabla,

                       resultados, limite);

void tabla_multiplicar(int tabla, int

                       *resultado, int limite) {

    for (int i = 1; i <= limite; i++) {

        *resultado tabla i;

        printf("%d x %d = %d\n", tabla,

               i, *resultado);

        resultado++;

    }

}



    return 0;

}