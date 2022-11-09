#include <stdio.h>

int main(){

    int kategorija, brend;



    while (1){
        printf("Unesite kategoriju i brend odece:");
        scanf("%d %d", &kategorija, &brend);

        if (kategorija >= 1 && kategorija <= 4 && brend >= 1 && brend <= 4){
            break;
        }
        printf("Izabrane opcije ne postoje, pokusajte ponovo!\n");
    }

    int cena, usteda = 0;


    if (kategorija == 1 && brend == 1){
        cena = 2000;
        usteda = cena * 20 / 100;
        cena = cena - usteda;
        printf("Racun je %d dinara, ustedeli ste %d dinara.", cena, usteda);
    }

    else if (kategorija == 1 && brend == 2){
        cena = 2650;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 1 && brend == 3){
        cena = 2500;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 1 && brend == 4){
        cena = 1800;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 2 && brend == 1){
        cena = 1900;
        printf("Racun je %d dinara", cena);
    }
    else if (kategorija == 2 && brend == 2){
        cena = 2000;
        usteda = cena * 10 /100;
        cena = cena - usteda;
        printf("Racun je %d dinara, ustedeli ste %d dinara.", cena, usteda);
    }

    else if (kategorija == 2 && brend == 3){
        cena = 2150;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 2 && brend == 4){
        cena = 2050;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 3 && brend == 1){
        cena = 3000;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 3 && brend == 2){
        cena = 3150;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 3 && brend == 3){
        cena = 3000;
        usteda = cena * 12 / 100;
        cena = cena - usteda;
        printf("Racun je %d dinara, ustedeli ste %d dinara.", cena, usteda);
    }

    else if (kategorija == 3 && brend == 4){
        cena = 2500;
        usteda = cena * 12 / 100;
        cena = cena - usteda;
        printf("Racun je %d dinara, ustedeli ste %d dinara.", cena, usteda);
    }

    else if (kategorija == 4 && brend == 1){
        cena = 2700;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 4 && brend == 2){
        cena = 3150;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 4 && brend == 3){
        cena = 2800;
        printf("Racun je %d dinara", cena);
    }

    else if (kategorija == 4 && brend == 4){
        cena = 3300;
        printf("Racun je %d dinara", cena);
    }




    return 0;
}
