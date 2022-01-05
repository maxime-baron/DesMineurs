#include "Demineur.h"
#include<QDebug>

Demineur::Demineur()
{
    maGrille = new Grille(5);
    int taille= maGrille->getTaille();
    qDebug()<<"Demineur";
}

/*Demineur::~Demineur(){}*/
