#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char cadena[10];
    printf("un int ocupa%d\n bytes",sizeof(int));
    printf("un char ocupa%d\n bytes", sizeof(char));
    printf("un float ocupa%d\n bytes",sizeof(float));
    printf("un double ocupa%d\n bytes", sizeof(double));
    printf("ordena ocupa%d\n bytes", sizeof(cadena));
    return 0;
}