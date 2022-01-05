#ifndef GRILLE_H
#define GRILLE_H

#include "Case.h"
#include <QGridLayout>

class Grille : public QGridLayout
{
private:
    int taille;
public:
    Grille(int lgth);
    int numerateur();
    void dynamiteur(int nbrBombe);
    void setTaille(int p_taille);
    int getTaille();

};

#endif // GRILLE_H
