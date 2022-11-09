#include <stdio.h>
#include <stdlib.h>

int main() {
    int odeca;
    int brend;
    while (1) {
        printf("Unesi odecu, zatim brend: ");
        scanf("%d %d", &odeca, &brend);

        if ((odeca < 1) || (odeca > 4) || (brend < 1) || (brend > 4)) {
            printf("Izabrane opcije ne postoje, pokusajte ponovo!\n");
            continue;
        }

        int popust;
        if (odeca == 1) {
            if (brend == 1) {
                int nikeMajica = 2000;
                popust = nikeMajica * 1 / 5;
                nikeMajica = nikeMajica - popust;
                printf("Racun je %d dinara, ustedeli ste %d dinara.\n", nikeMajica, popust);
            } else if (brend == 2) {
                int adidasMajica = 2650;
                printf("Racun je %d dinara.\n", adidasMajica);
            } else if (brend == 3) {
                int ckMajica = 2500;
                printf("Racun je %d dinara.\n", ckMajica);
            } else {
                int gucciMajica = 1800;
                printf("Racun je %d dinara.\n", gucciMajica);
            }
        }

        else if (odeca == 2) {
            if (brend == 1) {
                int nikeTrenerka = 1900;
                printf("Racun je %d dinara.\n", nikeTrenerka);
            } else if (brend == 2) {
                int adidasTrenerka = 2000;
                popust = adidasTrenerka / 10;
                adidasTrenerka = adidasTrenerka - popust;
                printf("Racun je %d dinara, ustedeli ste %d dinara.\n", adidasTrenerka, popust);
            } else if (brend == 3) {
                int ckTrenerka = 2150;
                printf("Racun je %d dinara.\n", ckTrenerka);
            } else {
                int gucciTrenerka = 2050;
                printf("Racun je %d dinara.\n", gucciTrenerka);
            }
        }

        else if (odeca == 3) {
            if (brend == 1) {
                int nikePatike = 3000;
                printf("Racun je %d dinara.\n", nikePatike);
            } else if (brend == 2) {
                int adidasPatike = 3150;
                printf("Racun je %d dinara.\n", adidasPatike);
            } else if (brend == 3) {
                int ckPatike = 3000;
                popust = ckPatike / 12;
                ckPatike -= popust;
                printf("Racun je %d dinara, ustedeli ste %d dinara.\n", ckPatike, popust);
            } else {
                int gucciPatike = 2500;
                printf("Racun je %d dinara.\n", gucciPatike);
            }
        }

        else {
            if (brend == 1) {
                int nikeKosulja = 2700;
                printf("Racun je %d dinara.\n", nikeKosulja);
            } else if (brend == 2) {
                int adidasKosulja = 3150;
                printf("Racun je %d dinara.\n", adidasKosulja);
            } else if (brend == 3) {
                int ckKosulja = 2800;
                printf("Racun je %d dinara.\n", ckKosulja);
            } else {
                int gucciKosulja = 3300;
                printf("Racun je %d dinara.\n", gucciKosulja);
            }
        }
    }
    return 0;
}
