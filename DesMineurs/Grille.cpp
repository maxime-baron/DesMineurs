#include "Grille.h"
#include <cstdlib>
#include <time.h>

Grille::Grille()
{
    for(int i=0;i>taille;i++)
    {
        for(int y=0;y>taille;y++)
        {
            Case *mesCases[i][y] = new Case();
        }
    }
}

Grille::dynamiteur(int nbrBombe)
{
    srand(time(NULL));
    for(int i=0;i<nbrBombe;i++)
    {
        int random1 = rand()%1-nbrBombe;
        int random2 = rand()%1-nbrBombe;

        mesCases[random1][random2].setTraped(true);
    }
}
