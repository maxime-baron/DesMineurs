#include "Grille.h"
#include <cstdlib>
#include <time.h>
//#include <QObjectList>
#include <QLayoutItem>
#include <QDebug>

Grille::Grille(int lgth):taille(lgth)
{
    qDebug()<<"Grille";
    for(int i=0;i<taille;i++)
    {
        for(int y=0;y<taille;y++)
        {
            Case* unBouton = new Case();
            unBouton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            this->addWidget(unBouton,i,y);
        }
    }
    // Dynamiteur
    int nbrBombe = taille*taille/4;
    this->dynamiteur(nbrBombe);
}

void Grille::dynamiteur(int nbrBombe)
{
    srand(time(NULL));
    for(int i=1;i<nbrBombe;i++)
    {
        int random1 = rand()%taille+0;
        int random2 = rand()%taille+0;

        QLayoutItem* item = this->layout()->itemAt( (random1) + (random2) * 5); //ici x , y * 4 car on se décalle d'une ligne de 4
        QWidget* widget = item->widget();
        Case* button = dynamic_cast<Case*>(widget);
        button->setTraped(true);
        QColor col = QColor(Qt::red);
        QString qss = QString("background-color: %1").arg(col.name());
        button->setStyleSheet(qss);
    }
}

void Grille::setTaille(int p_taille)
{
    this->taille = p_taille;
}

int Grille::getTaille()
{
    return this->taille;
}
