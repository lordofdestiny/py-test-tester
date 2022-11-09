#include <stdio.h>
int main ()
{
    int proizvod, brend, cena_proizvoda;

    while (1){
    printf("Unesite proizvod i brend: ");
    scanf("%d %d",&proizvod, &brend);
    if ((proizvod >= 1 && proizvod <=4)&& (brend >= 1 && brend <= 4)){
        break;
    }
        else if((proizvod < 1 || proizvod >4)||(brend < 1 || brend > 4 )){
        printf("Izabrane opcije ne postoje, pokusajte ponovo!\n\n");
    }
     else{
        return 1;
     }
    }


/**          1.    2.       3.       4.
            Nike Adidas Calvin Klein Gucci
1. Majica   2000  2650      2500     1800
2. Trenerka 1900  2000      2150     2050
3. Patike   3000  3150      3000     2500
4. Košulja  2700  3150      2800     3300
*/

    if(brend == 1){
        if(proizvod == 1){
            cena_proizvoda = 2000;
            int popust = cena_proizvoda * 0.2;
            int racun = cena_proizvoda  - popust;
            printf("Racun je %d dinara, ustedeli ste %d dinara.", racun, popust);
        }
        else if(proizvod == 2){
            cena_proizvoda = 1900;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else if(proizvod == 3){
            cena_proizvoda = 3000;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else {
            cena_proizvoda =  2700;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
    }
    else if (brend == 2){
        if(proizvod == 1){
            cena_proizvoda = 2650;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else if(proizvod == 2){
            cena_proizvoda = 2000;
            int popust = cena_proizvoda * 0.1;
            int racun = cena_proizvoda - popust;
            printf("Racun je %d dinara, ustedelli ste %d dinara.", racun, popust);
        }
        else if(proizvod == 3){
            cena_proizvoda = 3150;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else {
            cena_proizvoda  = 3150;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
    }
    else if(brend == 3){
        if(proizvod == 1){
            cena_proizvoda  = 2500;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else if(proizvod == 2){
            cena_proizvoda = 2150;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else if(proizvod == 3){
            cena_proizvoda = 3000;
            int popust = cena_proizvoda * 0.12;
            int racun = cena_proizvoda - popust;
            printf("Racun je %d dinara, ustedelli ste %d dinara.", racun, popust);
        }
        else {
            cena_proizvoda = 2800;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
    }
    else if(brend == 4){
        if(proizvod == 1){
            cena_proizvoda = 1800;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else if(proizvod == 2){
            cena_proizvoda = 2050;
            printf("Racun je %d dinara.",cena_proizvoda);
        }
        else if(proizvod == 3){
            cena_proizvoda = 2500;
            int popust = cena_proizvoda * 0.12;
            int racun = cena_proizvoda - popust;
            printf("Racun je %d dinara, ustedelli ste %d dinara.", racun, popust);
        }
        else {
            cena_proizvoda = 3300;
            printf("Racun je %d dinara.",cena_proizvoda);

        }
    }
    return 0;
}
