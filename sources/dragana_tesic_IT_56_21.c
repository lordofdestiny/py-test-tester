#include <stdio.h>

int main()
{
    int kategorija, brend;
    do
        {
            printf("Izaberite kategoriju odece:\n1.Majica\n2.Trenerka\n3.Patike\n4.Kosulja\n");
            scanf("%d",&kategorija);
            printf("Izaberite brend odece:\n1.Nike\n2.Adidas\n3.Calvin Clein\n4.Gucci\n");
            scanf("%d",&brend);
            if(kategorija<=0 || kategorija>4 || brend <=0 || brend > 4)
            {
                printf("Izabrane opcije ne postoje, pokusajte ponovo!\n");

            }
        }while(kategorija<=0 || kategorija>4 || brend<=0 || brend>4);

    int racun=0;
    int usteda=0;
    if(kategorija==1)
    {
        if(brend==1)
        {
            usteda=2000/100*20;
            racun=2000-usteda;
        }
        else if(brend==2)
        {
            racun=2650;
        }
        else if(brend==3)
        {
            racun=2500;
        }
        else if(brend==4)
        {
            racun=1800;
        }
    }
    else if(kategorija==2)
    {
        if(brend ==1)
        {
            racun=1900;
        }
        else if(brend ==2)
        {
            usteda=2000/100*10;
            racun=2000-usteda;
        }
        else if(brend == 3)
        {
            racun=2150;
        }
        else if(brend == 4)
        {
            racun=2050;
        }
    }
    else if(kategorija==3)
    {
        if(brend == 1)
        {
            racun = 3000;
        }
        else if(brend == 2)
        {
            racun = 3150;
        }
        else if(brend == 3)
        {
            usteda=3000/100*12;
            racun=3000-usteda;
        }
        else if(brend == 4)
        {
            usteda=2500/100*12;
            racun=2500-usteda;
        }
    }
    else if(kategorija==4)
    {
        if(brend == 1)
        {
            racun = 2700;
        }
        else if(brend == 2)
        {
            racun = 3150;
        }
        else if(brend == 3)
        {
            racun = 2800;
        }
        else if(brend == 4)
        {
            racun = 3300;
        }
    }
    if(usteda>0)
    {
        printf("Racun je %d dinara, ustedeli ste %d dinara.",racun,usteda);
    }
    else
    {
        printf("Racun je %d dinara.",racun);
    }


}
