#ifndef JEU_H
#define JEU_H

#include"UIgagne.h"
#include"Joueur.h"

class Jeu
{
public:
    Jeu();
private:
    Joueur * monJoueur;
    UIgagne * gagne;
};

#endif // JEU_H
