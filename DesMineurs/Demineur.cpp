#include "Demineur.h"
#include<QDebug>
#include<QWidget>
#include<QFormLayout>
#include<QLineEdit>

Demineur::Demineur()
{
    QWidget *zoneCentrale = new QWidget;

    Grille *maGrille = new Grille(5);

    zoneCentrale->setLayout(maGrille);

    setCentralWidget(zoneCentrale);

    maGrille = new Grille(5);
    int taille= maGrille->getTaille();
    qDebug()<<"Demineur";
}

/*Demineur::~Demineur(){}*/
