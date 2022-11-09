/*
                    BREND

              1.         2.       3.         4.
  ARTIKAL    Nike     Adidas  Calvin Klein   Gucci
1. Majica   2000(20%) 2650      2500         1800
2. Trenerka 1900      2000(10%) 2150         2050
3. Patike   3000      3150      3000(12%)    2500(12%)
4. Košulja  2700      3150      2800         3300
*/

#include <stdio.h>

int main()
{
    int artikal, brend, cena;

    while (1){
        printf("Unesite artikal: ");
        scanf("%d", &artikal);

        printf("Unesite brend: ");
        scanf("%d", &brend);

        if ((artikal >= 1 && artikal <= 4)&&(brend >= 1 && brend <= 4)){
            break;
        }

            else if ((artikal < 1 || artikal > 4)||(brend <1 || brend > 4)){
                printf ("Uneli ste pogresan kriterijum.\n");
            }
                else {
                    return 1;
                }
    }

    if (brend == 1){
        if (artikal == 1){
            cena = 2000;
            int popust = cena * 0.2; ///20% popusta
            int racun = cena - popust;
            printf ("Racun je %d dinara, ustedeli ste %d dinara.", racun, popust);
        }
        else if (artikal == 2){
            cena = 1900;
            printf ("Racun je %d dinara.", cena);
        }
        else if (artikal == 3){
            cena = 3000;
            printf ("Racun je %d dinara.", cena);
        }
        else {
        cena = 2700;
        printf ("Racun je %d dinara.", cena);
        }
    }
    else if (brend == 2){
        if (artikal == 1){
            cena = 2650;
            printf ("Racun je %d dinara.", cena);
        }
        else if(artikal == 2){
            cena = 2000;
            int popust = cena * 0.1;  ///10% popusta
            int racun = cena - popust;
            printf ("Racun je %d dinara, ustedeli ste %d dinara.", racun, popust);
        }
        else if (artikal == 3){
            cena = 3150;
            printf ("Racun je %d dinara.", cena);
        }
        else {
            cena = 3150;
            printf ("Racun je %d dinara.", cena);
        }
    }

    else if (brend == 3){
        if (artikal == 1){
            cena = 2500;
            printf ("Racun je %d dinara.", cena);
        }
       else if (artikal == 2){
            cena = 2150;
            printf ("Racun je %d dinara.", cena);
        }
       else if (artikal == 3){
            cena = 3000;
            int popust = cena * 0.12;  ///12% popusta
            int racun = cena - popust;
            printf ("Racun je %d dinara, ustedeli ste %d dinara.", racun, popust);
        }
        else {
            cena = 2800;
            printf ("Racun je %d dinara.", cena);
        }
    }

    else {
        if (artikal == 1){
            cena = 1800;
            printf ("Racun je %d dinara.", cena);
        }
       else if (artikal == 2){
            cena = 2050;
            printf ("Racun je %d dinara.", cena);
        }
       else if (artikal == 3){
            cena = 2500;
            int popust = cena * 0.12;  ///12% popusta
            int racun = cena - popust;
            printf ("Racun je %d dinara, ustedeli ste %d dinara.", racun, popust);
        }
        else {
            cena = 3300;
            printf ("Racun je %d dinara.", cena);
        }
    }


    return 0;
}
