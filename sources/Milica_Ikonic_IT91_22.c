#include <stdio.h>

    int main () {


        int kategorija_odece, brend_proizvoda;
        int cena, popust;

        while (1) {
            printf("Unesite kategoriju odece:");
            scanf("%d", &kategorija_odece);
            if (kategorija_odece >= 1 && kategorija_odece <= 4) {

                break;
            }
            printf("\nUneta vrednost ne postoji, pokusajte ponovo!\n");
        }

        while (1) {
            printf("Unesite brend proizvoda:");
            scanf("%d", &brend_proizvoda);
            if (brend_proizvoda >= 1 && brend_proizvoda <= 4) {

                break;
            }
            printf("\nUneta vrednost ne postoji, pokusajte ponovo!\n");

        }


///////// majica

        if (kategorija_odece == 1) {
            if (brend_proizvoda == 1){
                cena = 2000 * 0.8;
                popust = 2000 * 0.2;
                printf("Racun je %d dinara, ustedeli ste %d dinara.", cena,popust);
            }
            else if (brend_proizvoda == 2){
                cena = 2650;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 3){
                cena = 2500;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 4){
                cena = 1800;
                printf("Racun je %d dinara.", cena);
            }
        }


///////// trenerka

        if (kategorija_odece == 2) {
            if (brend_proizvoda == 1){
                cena = 1900;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 2){
                cena = 2000 * 0.9;
                popust = 2000 * 0.1;
                printf("Racun je %d dinara, ustedeli ste %d dinara.", cena, popust);
            }
            else if (brend_proizvoda == 3){
                cena = 2150;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 4){
                cena = 2050;
                printf("Racun je %d dinara.", cena);
            }
        }


///////// patike

         if (kategorija_odece == 3) {
            if (brend_proizvoda == 1){
                cena = 3000;
                printf("Racun je %d dinara.", cena);
            }
             else if (brend_proizvoda == 2){
                cena = 3150;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 3){
                cena = 3000 * 0.88;
                popust = 3000 * 0.12;
                printf("Racun je %d dinara, ustedeli ste %d dinara.", cena, popust);
            }
            else if (brend_proizvoda == 4){
                cena = 2500 * 0.88;
                popust = 2500 * 0.12;
                printf("Racun je %d dinara, ustedeli ste %d dinara.", cena, popust);
            }
         }


///////// kosulja

        if (kategorija_odece == 4) {
            if (brend_proizvoda == 1){
                cena = 2700;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 2){
                cena = 3150;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 3){
                cena = 2800;
                printf("Racun je %d dinara.", cena);
            }
            else if (brend_proizvoda == 4){
                cena = 3300;
                printf("Racun je %d dinara.", cena);
            }
        }


    return 0;
    }
