#include <stdio.h>
int main ()
{
    int odeca, brend;
    printf("Unesite zeljenu odecu: ");
    scanf("%d", &odeca);
    if (odeca>=1 && odeca<=4){
        }
    printf("Unesite zeljeni brend: ");
    scanf("%d", &brend);
    if (brend>=1 && brend<=4){
        }
    else  {
        printf("Izabrane opcije ne postoje pokusajte ponovo!", brend,odeca);
        }
    int  cena;
    float popust;

    if (odeca ==1){
        if(brend==1){
        popust=2000*20/100;
        cena=2000-popust;
        printf("Racun je %d dinara, ustedeli ste %.0f dinara.", cena, popust);
        }
        else if (brend==2){
        cena=2650;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend==3){
        cena=2500;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend=4){
        cena=1800;
        printf("Racun je %d dinara.",cena);
        }
    }
    else if (odeca ==2){
        if (brend==1){
        cena =1900;
        printf("Racun je %d dinara.",cena);
    }
        else if (brend==2){
        popust=2000*10/100;
        cena=2000-popust;
        printf("Racun je %d dinara, ustedeli ste %f dinara.",cena,popust);
        }
        else if (brend==3){
        cena = 2150;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend ==4){
        cena=2050;
        printf("Racun je %d dinara.",cena);
        }
    }
    else if (odeca ==3){
        if (brend==1){
        cena=3000;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend==2){
        cena = 3150;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend==3){
        popust=3000*12/100;
        cena =3000-popust;
        printf("Racun je %d dinara, ustedeli ste %.0f dinara.",cena,popust);
        }
        else if (brend==4){
        popust=2500*12/100;
        cena = 2500-popust;
        printf("Racun je %d dinara, ustedeli ste %.0f dinara.", cena, popust);
        }
    }
    else if (odeca ==4){
        if (brend==1){
        cena =2700;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend==2){
        cena =3150;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend==3){
        cena =2800;
        printf("Racun je %d dinara.",cena);
        }
        else if (brend==4){
        cena=3300;
        printf("Racun je %d dinara.",cena);
        }
    }
        return 0;

    }
