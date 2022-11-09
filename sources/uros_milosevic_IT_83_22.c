#include<stdio.h>

int main()
{
    int kategorijaOdece, brend, cena, popust;
    kategorijaOdece=0;
    brend=0;

    printf("Unesite kategoriju odece\n");
    printf("1.Majica\n2.Trenerka\n3.Patike\n4.Kosulja\n");
    printf("Uneti redni broj kojim se oznacava zeljeni artikal: ");
    scanf("%d",&kategorijaOdece);
    printf("Odaberite brend:\n");
    printf("1.Nike\n2.Adidas\n3.Calvin Klein\n4.Gucci\n");
    printf("Uneti redni broj kojim se oznacava zeljeni brend: ");
    scanf("%d",&brend);


    if (kategorijaOdece==1 && brend==1){
            cena=2000*80/100;
            popust=2000*20/100;
            printf("Racun je %d dinara, ustedeli ste %d dinara.",cena,popust);
    }

    else if (kategorijaOdece==1 && brend==2){
        cena=2650;
        printf("Racun je %d dinara",cena);
    }

    else if (kategorijaOdece==1 && brend==3){
        cena=2500;
        printf("Racun je %d dinara",cena);
    }
    else if (kategorijaOdece==1 && brend==4){
        cena=1800;
        printf("Racun je %d dinara",cena);
    }
    else if (kategorijaOdece==2 && brend==1){
                 cena=1900;
                 printf("Racun je %d dinara",cena);

    }
    else if (kategorijaOdece==2 && brend==2){
        cena=2000*90/100;
        popust=2000*10/100;
        printf("Racun je %d dinara, ustedeli ste %d dinara.",cena,popust);
    }
    else if (kategorijaOdece==2 && brend==3){
                 cena=2150;
                 printf("Racun je %d dinara",cena);

    }
    else if (kategorijaOdece==2 && brend==4){
                 cena=2050;
                 printf("Racun je %d dinara",cena);

    }
    else if (kategorijaOdece==3 && brend==1){
                 cena=3000;
                 printf("Racun je %d dinara",cena);

    }
    else if (kategorijaOdece==3 && brend==2){
                 cena=3150;
                 printf("Racun je %d dinara",cena);

    }

    else if (kategorijaOdece==3 && brend==3){
            cena=3000*88/100;
            popust=2000*12/100;
            printf("Racun je %d dinara, ustedeli ste %d dinara.",cena,popust);
    }
    else if (kategorijaOdece==3 && brend==4){
            cena=2500*88/100;
            popust=2500*12/100;
            printf("Racun je %d dinara, ustedeli ste %d dinara.",cena,popust);
    }
    else if (kategorijaOdece==4 && brend==1){
                 cena=2700;
                 printf("Racun je %d dinara",cena);

    }
    else if (kategorijaOdece==4 && brend==2){
                 cena=3150;
                 printf("Racun je %d dinara",cena);

    }
    else if (kategorijaOdece==4 && brend==3){
                 cena=2800;
                 printf("Racun je %d dinara",cena);

    }
    else if (kategorijaOdece==4 && brend==4){
                 cena=3300;
                 printf("Racun je %d dinara",cena);

    }
    else
        printf("\nIzabrane opcije ne postoje, pokusajte ponovo!");

    return 0;
}
