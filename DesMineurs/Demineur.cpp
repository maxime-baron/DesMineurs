#include "Demineur.h"
#include<QDebug>
#include<QWidget>
#include<QFormLayout>
#include<QLineEdit>

Demineur::Demineur()
{
    QWidget *zoneCentrale = new QWidget;

    Grille *maGrille = new Grille(10);
    this->setFixedSize(600,600);

    zoneCentrale->setLayout(maGrille);

    setCentralWidget(zoneCentrale);

    int taille= maGrille->getTaille();
    qDebug()<<"Demineur";
}

/*Demineur::~Demineur(){}*/
