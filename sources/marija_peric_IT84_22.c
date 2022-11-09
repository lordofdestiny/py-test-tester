#include <stdio.h>
int main () {

    int vrsta_artikla, marka_artikla;

    while (1) {
        printf("Unesite vrstu artikla: \n");
        scanf("%d", &vrsta_artikla);
        printf("Unesite marku artikla: \n");
        scanf("%d", &marka_artikla);
        if (vrsta_artikla >= 1 && vrsta_artikla <= 4 && marka_artikla >= 1 && marka_artikla <= 4){
            break;
        }
        else {
            printf("Izabrane opcije ne postoje pokusajte ponovo! \n");
        }
    }

    int cena_artikla, usteda_racuna = 0;

    if (vrsta_artikla == 1) {
        if (marka_artikla == 1) {
                    cena_artikla = 2000 * 0.8;
                    usteda_racuna = 2000 * 0.2;
        }
        else if (marka_artikla == 2) {
                    cena_artikla = 2650;
        }
        else if (marka_artikla == 3) {
                    cena_artikla = 2500;
        }
        else   {
                    cena_artikla = 1800;
        }
    }

    else if (vrsta_artikla == 2) {
        if (marka_artikla == 1) {
                    cena_artikla = 1900;
        }
        else if (marka_artikla == 2) {
                    cena_artikla = 2000 * 0.9;
                    usteda_racuna = 2000 * 0.1;
        }
        else if (marka_artikla == 3) {
                    cena_artikla = 2150;
        }
        else   {
                    cena_artikla = 2050;
        }
    }

    else if (vrsta_artikla == 3) {
        if (marka_artikla == 1) {
                    cena_artikla = 3000;
        }
        else if (marka_artikla == 2) {
                    cena_artikla = 3150;
        }
        else if (marka_artikla == 3) {
                    cena_artikla = 3000 * 0.88;
                    usteda_racuna = 3000 * 0.12;
        }
        else   {
                    cena_artikla = 2500 * 0.88;
                    usteda_racuna = 2500 * 0.12;
        }
    }

    else   {
        if (marka_artikla == 1) {
                    cena_artikla = 2700;
        }
        else if (marka_artikla == 2) {
                    cena_artikla = 3150;
        }
        else if (marka_artikla == 3) {
                    cena_artikla = 2800 ;
        }
        else   {
                    cena_artikla = 3300;
        }
    }

    if (usteda_racuna > 0) {
        printf("Racun je %d dinara, ustedeli ste %d dinara.", cena_artikla, usteda_racuna );
        }
    else {
        printf("Racun je %d dinara.", cena_artikla);
    }

  return 0;
}
