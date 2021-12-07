#ifndef DEMINEUR_H
#define DEMINEUR_H

#include"jeu.h"
#include"Grille.h"

class Demineur:public Jeu
{
private:
    Grille maGrille;
public:
    Demineur();
};

#endif // DEMINEUR_H
