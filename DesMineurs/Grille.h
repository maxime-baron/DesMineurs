#ifndef GRILLE_H
#define GRILLE_H
#include "Demineur.h"
#include "Case.h"

class Grille
{
private:
    Case mesCases[4][4];
public:
    Grille();
    int numerateur();
};

#endif // GRILLE_H
