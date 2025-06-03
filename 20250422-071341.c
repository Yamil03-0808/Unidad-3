#include <stdlib.h>

int main() {
    char pl[100];
    char p2[100];
    char r[10000];

    printf("Pl: ");
    scanf("%s", pl);

    printf("P2: ");
    scanf("%s", p2);

    int len = strlen(pl);
    strcat(r, pl);
    for(int i = 0; i < len; i++) {
        strcat(r, p2);
    }
    printf("Pl: %s\n", r);

    system("pause");
    return 0;
}