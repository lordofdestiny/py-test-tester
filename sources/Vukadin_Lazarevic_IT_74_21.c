#include <stdio.h>

int main()
{
    int proizvod = 1, brend = 1;
    while (1) {
        scanf("%d %d", &proizvod, &brend);
        
        if (proizvod >= 1 && proizvod <= 4 && brend >= 1 && brend <= 4)
            break;
        else
            printf("Izabrane opcije ne postoje, pokusajte ponovo!\n");
    }

    if (proizvod == 1 && brend == 1) {
        printf("Racun je 1600 dinara, ustedeli ste 400 dinara.");
    }
    else if (proizvod == 1 && brend == 2){
        printf("Racun je 2650 dinara.");
    }
    else if (proizvod == 1 && brend == 3){
        printf("Racun je 2500 dinara.");
    }
    else if (proizvod == 1 && brend == 4){
        printf("Racun je 1800 dinara.");
    }
    else if (proizvod == 2 && brend == 1){
        printf("Racun je 1900 dinara.");
    }
    else if (proizvod == 2 && brend == 2){
        printf("Racun je 1800 dinara, ustedeli ste 200 dinara.");
    }
    else if (proizvod == 2 && brend == 3){
        printf("Racun je 2150 dinara.");
    }
    else if (proizvod == 2 && brend == 4){
        printf("Racun je 2050 dinara.");
    }
    else if (proizvod == 3 && brend == 1){
        printf("Racun je 3000 dinara.");
    }
    else if (proizvod == 3 && brend == 2){
        printf("Racun je 3150 dinara.");
    }
    else if (proizvod == 3 && brend == 3){
        printf("Racun je 2640 dinara, ustedeli ste 360 dinara.");
    }
    else if (proizvod == 3 && brend == 4){
        printf("Racun je 2200 dinara, ustedeli ste 300 dinara.");
    }
    else if (proizvod == 4 && brend == 1){
        printf("Racun je 2700 dinara.");
    }
    else if (proizvod == 4 && brend == 2){
        printf("Racun je 3150 dinara.");
    }
    else if (proizvod == 4 && proizvod == 3){
        printf("Racun je 2800 dinara.");
    }
    else if (proizvod == 4 && proizvod == 4){
        printf("Racun je 3300 dinara.");
    }

    return 0;
}