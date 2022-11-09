#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unosPrvi = 0, unosDrugi = 0;

    float cenaTotal;
    float popustFinal;

    float cene[4][4] = {
        {2000, 1900, 3000, 2700}, //Nike
        {2650, 2000, 3150, 3150}, //Addidas
        {2500, 2150, 3000, 2800}, //CK
        {1800, 2050, 2500, 3300}  //Gucci
    };

    float popust[4] = {20, 10, 12, 12}; //Nike, Addidas, CK i Gucci

    char brend[4][13] = {"Nike", "Addidas", "Calvin Klein", "Gucci"};

    char kategorije[4][9] = {"Majica", "Trenerka", "Patike", "Kosulja"};


    ///Ispisuje imena proizvoda iz Niza

    for(int i = 0; i < 4; i++) {
       printf(" %d. %s ", i + 1, kategorije[i]);
    }

    printf("\n");

    ///Ispisuje cene tih proizvoda zajedno sa imenom brenda na kraju

    for(int i = 0; i < 4; i++) {
        printf("\n ");

        for(int j = 0; j < 4; j++) {

            printf("%7.0f     ", cene[i][j]);

        }

        printf("%d. %s",i+1, brend[i]);
    }

    printf("\n\nIzaberite proizvod (Ime proizvoda zatim Brend): ");


    ///Ceka se unos i proverava da li je validan

    while (1) {
        scanf("%d %d", &unosDrugi, &unosPrvi);

        if(unosPrvi < 5 && unosPrvi > 0 && unosDrugi < 5 && unosDrugi > 0) break;

        printf("Izabrane opcije ne postoje, pokusajte ponovo: ");
    }


    ///Posto su redni brojevi pored proizvoda ispisani od 1 do 4 vrednost unosa se smanjuje za 1

    unosPrvi--;
    unosDrugi--;

    ///Proverava da li proizvod ima akciju i zavrsava program

    if(unosDrugi == 0 && unosPrvi == 0) {

        cenaTotal = cene[unosPrvi][unosDrugi] - (cene[unosPrvi][unosDrugi] * (popust[unosPrvi] / 100));

        popustFinal = cene[unosPrvi][unosDrugi] * (popust[unosPrvi] / 100);

        printf("Racun je: %.0f dinara. Ustedeli ste %.0f dinara", cenaTotal, popustFinal);
        return 0;
    }

    if(unosDrugi == 1 && unosPrvi == 1) {

        cenaTotal = cene[unosPrvi][unosDrugi] - (cene[unosPrvi][unosDrugi] * (popust[unosPrvi] / 100));

        popustFinal = cene[unosPrvi][unosDrugi] * (popust[unosPrvi] / 100);

        printf("Racun je: %.0f dinara. Ustedeli ste %.0f dinara", cenaTotal, popustFinal);
        return 0;
    }

    if(unosDrugi == 2 && unosPrvi == 3|| unosDrugi == 2 && unosPrvi == 2) {

        cenaTotal = cene[unosPrvi][unosDrugi] - (cene[unosPrvi][unosDrugi] * (popust[unosPrvi] / 100));

        popustFinal = cene[unosPrvi][unosDrugi] * (popust[unosPrvi] / 100);

        printf("Racun je: %.0f dinara. Ustedeli ste %.0f dinara", cenaTotal, popustFinal);
        return 0;
    }

    cenaTotal = cene[unosPrvi][unosDrugi];
    printf("Racun je: %.0f dinara", cenaTotal);

    return 0;
}
