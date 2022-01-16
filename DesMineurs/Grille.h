#ifndef GRILLE_H
#define GRILLE_H

#include "Case.h"
#include <QGridLayout>


class Grille : public QGridLayout
{

    Q_OBJECT

private:
    int taille;
public:

    Case* caseClick;
    Grille(int lgth);
    void numerateur();
    void click();
    void dynamiteur(int nbrBombe);
    void setTaille(int p_taille);
    int getTaille();
    Case * recuperationCase(int p_x,int p_y);
signals:
    void digitClicked(Case* cs,bool right);

private slots:
    void bouttonCliquer();
    void onRightClicked();

};

#endif // GRILLE_H
