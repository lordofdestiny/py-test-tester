#include <stdio.h>
/*
                    1. Nike       2. Adidas     3. CK     4. Gucci
    1  majica        2000            2650        2500        1800
    2  trenerka      1900            2000        2150        2050
    3  patike        3000            3150        3000        2500
    4  kosulja       2700            3150        2800        3300

*/

int main() {
    int odeca, brend, cenaPopust, imaPopust=0;
    float usteda, popust;
    

    int cene[4][4] = {
        {2000, 2650, 2500, 1800},
        {1900, 2000, 2150, 2050},
        {3000, 3150, 3000, 2500},
        {2700, 3150, 2800, 3300}
    };

    while(1) {
        printf("Unesite broj koji oznacava odecu: ");
        scanf("%d", &odeca);
        printf("\nUnesite broj koji oznacava brend: ");
        scanf("%d", &brend);
        
        if(odeca > 4 || odeca < 1 || brend < 1 || brend > 4) {
        	printf("\nIzabrane opcije ne postoje, pokusajte ponovo!\n\n");
        	continue;
        	
		
		} 
        
        if(odeca==1 && brend==1) {
        	popust = 0.2;
        	imaPopust = 1;
        	
		}
		if(odeca==2 && brend==2) {
			popust = 0.1;
			imaPopust = 1;
			
		}
		
		if(odeca==3 && brend==3 || odeca==3 && brend==4) {
			popust = 0.12;
			imaPopust = 1;
				
		}
		
		cenaPopust = cene[odeca-1][brend-1] * (1-popust);
		usteda = cene[odeca-1][brend-1] * popust;
		
			
		if(imaPopust == 1) {
			
			printf("\nCena je: %d dinara, a usteda je: %.2f dinara.\n", cenaPopust, usteda); 
			break;
		}
		
		else{
		
		 printf("\nCena je: %d dinara.\n", cene[--odeca][--brend]); 
		 break;
	     }

    }
    return 0;
}
