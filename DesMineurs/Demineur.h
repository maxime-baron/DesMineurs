#ifndef DEMINEUR_H
#define DEMINEUR_H

#include "jeu.h"
#include "Grille.h"
#include "UIgagne.h"
#include "Joueur.h"
#include <QPushButton>

class UIgagne;
class Joueur;
class Grille;

class Demineur:public Jeu
{
protected slots:
    void win();
    void lose();
    void playHard();
    void playEasy();
    void quit();
private:
    Grille * maGrille;
    Joueur * monJoueur;
    UIgagne * gagne;
    QString gameDifficult;
public:
    Demineur();
};

#endif // DEMINEUR_H
