#include <stdio.h>

/*
                1.          2.          3.              4.
                Nike        Adidas      CalvinKlein     Gucci
1.  Majica      2000        2650        2500            1800
2.  Trenerka    1900        2000        2150            2050
3.  Patike      3000        3150        3000            2500
4.  Košulja     2700        3150        2800            3300
*/

int validDimension(int dimension) {
    return dimension >= 1 && dimension <= 4;
}

int getDiscount(int a, int b) {
    if (a == 1 && b == 1) return 20;
    if (a == 2 && b == 2) return 10;
    if (a == 3 && (b == 3 || b == 4)) return 12;
    return 0;
}

int main() {
    int values[4][4] = {
        {2000, 2650, 2500, 1800},
        {1900, 2000, 2150, 2050},
        {3000, 3150, 3000, 2500},
        {2700, 3150, 2800, 3300}
    };


    do {
        int tip = 0, brend = 0;
        scanf("%d %d", &tip, &brend);
        int discount = getDiscount(tip, brend);

        if (!validDimension(tip) || !validDimension(brend)) {
            printf("Izabrane opcije ne postoje, pokusajte ponovo!\n");
            continue;
        }

        int cena = values[tip - 1][brend - 1];

        if (discount == 0) {
            printf("Racun je %d dinara.", cena);
        } else {
            float discountAmount = (cena * discount) / 100.0;
            float final = cena - discountAmount;
            printf("Racun je %.0f dinara, ustedeli ste %.0f dinara.", final, discountAmount);
        }

        break;
    } while (1);
}