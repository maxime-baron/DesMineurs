#ifndef DEMINEUR_H
#define DEMINEUR_H

#include "jeu.h"
#include "Grille.h"
#include "UIgagne.h"
#include "Joueur.h"

class UIgagne;
class Joueur;
class Grille;

class Demineur:public Jeu
{
private:
    Grille * maGrille;
    Joueur * monJoueur;
    UIgagne * gagne;
public:
    Demineur();
};

#endif // DEMINEUR_H
