#include <stdio.h>


        int main()
{
            int kategorija_odece;
            	printf("Unesite kategoriju odece: ");
            	scanf("%d", &kategorija_odece);
            while (kategorija_odece >4 || kategorija_odece <1) {
                printf("Unos je nepravilan probajte jos jednom!");
                scanf("%d", &kategorija_odece);
            }
            int brend_izabranog_proizvoda;
            	printf("Unesite brend izabranog proizvoda: ");
            	scanf("%d", &brend_izabranog_proizvoda);
            while(brend_izabranog_proizvoda >4 || brend_izabranog_proizvoda <1) {
                printf("Unos je nepravilan probajte jos jednom!");
                scanf("%d", &brend_izabranog_proizvoda);
            }
            int popust;
            int cena;
            if (kategorija_odece == 1 && brend_izabranog_proizvoda == 1){
                cena=2000;
                popust=cena*0.2;
                cena=cena-popust;
                printf("Racun je %d dinara, ustedeli ste %d dinara.", cena,popust);
            }
            else if (kategorija_odece == 2 && brend_izabranog_proizvoda == 1){
                cena=1900;
                printf("Racun je %d dinara.", cena);
            }
            else if (kategorija_odece == 3 && brend_izabranog_proizvoda ==1){
                cena=3000;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece ==4 && brend_izabranog_proizvoda==1){
                cena=2700;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece == 1 && brend_izabranog_proizvoda==2){
                cena=2650;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece == 2 && brend_izabranog_proizvoda==2){
                cena=2000;
                popust=cena*0.1;
                cena=cena-popust;
                printf("Racun je %d dinara, ustedeli ste %d dinara.", cena,popust);
            }
            else if(kategorija_odece == 3 && brend_izabranog_proizvoda==2) {
                cena=3150;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece == 4 && brend_izabranog_proizvoda==2){
                cena=3150;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece ==1 && brend_izabranog_proizvoda==3){
                cena=2500;
                printf("Racun je %d dinara", cena);
            }
            else if(kategorija_odece ==2 && brend_izabranog_proizvoda==3){
                cena=2150;
                printf("Racun je %d dinara", cena);
            }
            else if(kategorija_odece ==3 && brend_izabranog_proizvoda==3) {
                cena=3000;
                popust=cena*0.12;
                cena=cena-popust;
                printf("Racun je %d dinara, ustedeli ste %d dinara., ustedeli ste %d dinara.", cena, popust);
            }
            else if(kategorija_odece ==4 && brend_izabranog_proizvoda==3){
                cena=2800;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece ==1 && brend_izabranog_proizvoda==4) {
                cena=1800;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece ==2 && brend_izabranog_proizvoda==4) {
                cena=2050;
                printf("Racun je %d dinara.", cena);
            }
            else if(kategorija_odece ==3 && brend_izabranog_proizvoda==4) {
                cena=2500;
                popust=cena*0.12;
                cena=cena-popust;
                printf("Racun je %d dinara, ustedeli ste %d dinara.", cena,popust);
            }
            else if(kategorija_odece ==4 && brend_izabranog_proizvoda==4){
                cena=3300;
                printf("Racun je %d dinara.", cena);
            }

    return 0;

}
