#ifndef GRILLE_H
#define GRILLE_H

#include "Case.h"
#include <QObjectList>
#include <QGridLayout>

class Grille : public QGridLayout
{
private:
    int taille;
public:
    Grille(int lgth);
    int numerateur();
    void dynamiteur(int nbrBombe);

};

#endif // GRILLE_H
