#ifndef JEU_H
#define JEU_H

#include"UIgagne.h"
#include"Joueur.h"

class Jeu
{

private:
    Joueur * monJoueur;
    UIgagne * gagne;
    int topScore;
public:

    Jeu();
    void win();
    void lose();
};

#endif // JEU_H
