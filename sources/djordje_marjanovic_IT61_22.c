#include <stdio.h>


int main() {
    int izbor, izbor2, ustedjeno;


    do {
        printf("Izaberite vrstu odece (1 - 4) i brend (1 - 4): ");
        scanf("%d  %d", &izbor, &izbor2);
        if (izbor <= 0 || izbor >= 5 || izbor2 <= 0 || izbor2 >= 5)
            printf("Uneliste neodgovarajuci izbor!\n");
    } while (izbor <= 0 || izbor >= 5 || izbor2 <= 0 || izbor2 >= 5);

    int cena = 0;
    int snizena_cena = 0;

    //Nike

    if (izbor2 == 1 && izbor == 1) {
        printf("izabrali ste Nike Majicu\n");
        cena = 2000;
        snizena_cena = cena - (cena * 0.20);
        ustedjeno = cena * 0.20;
    } else if (izbor2 == 1 && izbor == 2) {
        printf("izabrali ste Nike Trenerke\n");
        cena = 1900;
    } else if (izbor2 == 1 && izbor == 3) {
        printf("izabrali ste Nike Patike\n");
        cena = 3000;
    } else if (izbor2 == 1 && izbor == 4) {
        printf("izabrali ste Nike Kosulju\n");
        cena = 2700;

        //Adidas

    } else if (izbor2 == 2 && izbor == 1) {
        printf("izabrali ste Adidas Majicu\n");
        cena = 2650;
    } else if (izbor2 == 2 && izbor == 2) {
        printf("izabrali ste Adidas Trenerke\n");
        cena = 2000;
        snizena_cena = cena - (cena * 0.10);
        ustedjeno = cena * 0.10;
    } else if (izbor2 == 2 && izbor == 3) {
        printf("izabrali ste Adidas Patike\n");
        cena = 3150;
    } else if (izbor2 == 2 && izbor == 4) {
        printf("izabrali ste Adidas Kosulju\n");
        cena = 3150;

        //Calvin Klein

    } else if (izbor2 == 3 && izbor == 1) {
        printf("izabrali ste Calvin Klein Majicu\n");
        cena = 2500;
    } else if (izbor2 == 3 && izbor == 2) {
        printf("izabrali ste Calvin Klein Trenerke\n");
        cena = 2150;
    } else if (izbor2 == 3 && izbor == 3) {
        printf("izabrali ste Calvin Klein Patike\n");
        cena = 3000;
        snizena_cena = cena - (cena * 0.12);
        ustedjeno = cena * 0.12;
    } else if (izbor2 == 3 && izbor == 4) {
        printf("izabrali ste Calvin Klein Kosulju\n");
        cena = 2800;
    }

    //Gucci

    else if (izbor2 == 4 && izbor == 1) {
        printf("izabrali ste Gucci Majicu\n");
        cena = 1800;
    } else if (izbor2 == 4 && izbor == 2) {
        printf("izabrali ste Gucci Trenerke\n");
        cena = 2050;
    } else if (izbor2 == 4 && izbor == 3) {
        printf("izabrali ste Gucci Patike\n");
        cena = 2500;
        snizena_cena = cena - (cena * 0.12);
        ustedjeno = cena * 0.12;
    } else if (izbor2 == 4 && izbor == 4) {
        printf("izabrali ste Gucci Kosulju\n");
        cena = 3300;
    }



    if (ustedjeno > 0) {
        printf("Cena odece koju ste izabrali je: %d, ustedeli ste %d", snizena_cena, ustedjeno);
    } else printf("Cena odece koju ste izabrali je : %d", cena);
    return 0;
}
