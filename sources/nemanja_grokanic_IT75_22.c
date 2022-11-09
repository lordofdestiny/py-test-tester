#include <stdio.h>

int main ()
{
    int kat;
    int brend;
    int cene [4][4] = {
        {2000, 2650, 2500, 1800},
        {1900, 2000, 2150, 2050},
        {3000, 3150, 3000, 2500},
        {2700, 3150, 2800, 3300}
    };


    while(1) {
        printf("Unesite kategoriju garderobe: \n");
        printf("1.Majica\n2.Trenerka\n3.Patike\n4.Kosulja\n");
        scanf("%d", &kat);

        printf("Unesite brend garderobe:\n");
        printf("1.Nike\n2.Adidas\n3.Calvin Clein\n4.Gucci\n");
        scanf("%d", &brend);

    int nikePopust   =  cene[0][0]*20/100;
    int adidasPopust =  cene[1][1]/10;
    int ckPopust     =  cene[2][2]*12/100;
    int gucciPopust  =  cene[2][3]*12/100;


    if(kat > 4 || kat < 1 || brend < 1 || brend > 4) {
        printf("\nIzabrane opcije ne postoje, pokusajte ponovo!\n\n");
        continue;
      }

      if(kat == 1 & brend == 1){
        printf("\nRacun je %d , ustedeli ste %d dinara.", cene[0][0] - nikePopust, nikePopust);
        break;
      }

      if(kat == 2 & brend == 2){
        printf("\nRacun je %d , ustedeli ste %d dinara.", cene[1][1] - adidasPopust, adidasPopust);
        break;
      }

      if(kat == 3 & brend == 3){
        printf("\nRacun je %d , ustedeli ste %d dinara.", cene[2][2] - ckPopust, ckPopust);
        break;
      }

      if(kat == 3 & brend == 4){
        printf("\nRacun je %d , ustedeli ste %d dinara.", cene[2][3] - gucciPopust, gucciPopust);
        break;
      }

    printf("\nRacun je %d dinara.",cene[--kat][--brend]);
        break;

    }


    return 0;
}
