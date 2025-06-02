#include <stdio.h>
#include <stdlib.h>
int main() {
    int segundos = 0;

    while (1) {

        int angulo = segundos * 6; // 6

        printf("Manecilla de segundos: %d\n", angulo);

               segundos++;

        if (segundos >= 60) {

        segundos = 0; // Reinicia

    }

    sleep(1); // Espera 1 segundo

}
return 0;

}