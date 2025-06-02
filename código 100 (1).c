#include <stdio.h>
#include <stdlib.h>
int main() {
  
    int horas = 0, minutos = 0, segundos = 0;

    while (1) {



        printf("%02d:%02d:%02d\n", horas, minutos, segundos);

        segundos++;

        if (segundos >= 60) {

            segundos = 0;

            minutos++;

        }

        if (minutos >= 60) {

            minutos = 0;


            horas++;

        }

        if (horas >= 24) {

            horas = 0;

        }



        sleep(1);

    }

    return 0;

}