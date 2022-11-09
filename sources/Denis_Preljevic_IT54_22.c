#include <stdio.h>

int main() {

  int odeca, brend, cena, popust = 0;

  while (1) {
    printf("Uneti kategoriju odece:  ");
    scanf("%d", &odeca);
    if (odeca >= 1 && odeca <= 4) {
      break;
    }
    printf("Uneta pogresna opcija odece!\n\n");
  }
  while (1) {
    printf("Uneti Brend izabranog proizvoda:  ");
    scanf("%d", &brend);
    if (brend >= 1 && brend <= 4) {
      break;
    }
    printf("Uneta pogresna opcija brenda!\n\n");
  }
  while (1) {
    if (odeca == 1) {
      if (brend == 1) {
        cena = 2000;
      } else if (brend == 2) {
        cena = 2650;
      } else if (brend == 3) {
        cena = 2500;
      } else cena = 1800;
    }
    if (odeca == 2) {
      if (brend == 1) {
        cena = 1900;
      } else if (brend == 2) {
        cena = 2000;
      } else if (brend == 3) {
        cena = 2150;
      } else cena = 2050;
    }
    if (odeca == 3) {
      if (brend == 1) {
        cena = 3000;
      } else if (brend == 2) {
        cena = 3150;
      } else if (brend == 3) {
        cena = 3000;
      } else cena = 2500;
    }
    if (odeca == 4) {
      if (brend == 1) {
        cena = 2700;
      } else if (brend == 2) {
        cena = 3150;
      } else if (brend == 3) {
        cena = 2800;
      } else cena = 3300;
    }
    break;
  }
  if (odeca == 1 && brend == 1) {
    popust = cena * 0.2;
    cena -= popust;
    printf("\nImate 20 posto popusta!");
    printf("\nRacun je:   %d  dinara\nUstedeli ste:   %d  dinara\n", cena, popust);
  } else if (odeca == 2 && brend == 2) {
    popust = cena * 0.1;
    cena -= popust;
    printf("\nImate 10 posto popusta!");
    printf("\nRacun je:   %d  dinara\nUstedeli ste:   %d  dinara\n", cena, popust);
  } else if (odeca == 3 && brend == 3) {
    popust = cena * 0.12;
    cena -= popust;
    printf("\nImate 12 posto popusta!");
    printf("\nRacun je:   %d  dinara\nUstedeli ste:   %d  dinara\n", cena, popust);
  } else if (odeca == 3 && brend == 4) {
    popust = cena * 0.12;
    cena -= popust;
    printf("\nImate 12 posto popusta!");
    printf("\nRacun je:   %d  dinara\nUstedeli ste:   %d  dinara\n", cena, popust);
  } else {
    printf("\nRacun je:   %d  dinara", cena);
  }
  return 0;
}

