#include "Demineur.h"
#include<QDebug>
#include<QWidget>
#include<QFormLayout>
#include<QLineEdit>
#include<QLabel>

Demineur::Demineur()
{
    QWidget *zoneCentrale = new QWidget;

    Grille *maGrille = new Grille(10);
    connect(maGrille,&Grille::lose,this,&Demineur::lose);
    connect(maGrille,&Grille::win,this,&Demineur::win);
    this->setFixedSize(600,600);

    zoneCentrale->setLayout(maGrille);

    setCentralWidget(zoneCentrale);

    //int taille= maGrille->getTaille();
    qDebug()<<"Demineur";
}

void Demineur::lose()
{
    QWidget *zoneCentrale = new QWidget;

    QLabel *label = new QLabel(zoneCentrale);
    label->setText("Vous avez perdu");
    this->setFixedSize(600,600);
    setCentralWidget(zoneCentrale);
    qDebug()<<"lose";
}

void Demineur::win()
{
    QWidget *zoneCentrale = new QWidget;

    QLabel *label = new QLabel(zoneCentrale);
    label->setText("Vous avez gagner");
    this->setFixedSize(600,600);
    setCentralWidget(zoneCentrale);
    qDebug()<<"win";
}

/*Demineur::~Demineur(){}*/
