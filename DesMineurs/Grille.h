#ifndef GRILLE_H
#define GRILLE_H
#include "Demineur.h"
#include "Case.h"

class Grille
{
private:
    Case mesCases[4][4];
    int taille;
public:
    Grille();
    int numerateur();
    void dynamiteur(int nbrBombe);

};

#endif // GRILLE_H
