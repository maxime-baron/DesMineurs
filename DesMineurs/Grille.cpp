#include "Grille.h"
#include <cstdlib>
#include <time.h>
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
            //qDebug()<<this->itemAtPosition(i,y)->widget();
           // qDebug()<<qobject_cast<QPushButton *>(this->itemAtPosition(i,y));
           //dynamic_cast<QWidgetItem *>(this->itemAtPosition(i,y))->widget()->hide();

        }
    }
    QObjectList maList = this->layout()->itemAtPosition(1,0);
    qDebug()<<maList;
    int nbrBombe = taille*taille/4;
    this->dynamiteur(nbrBombe);
}

void Grille::dynamiteur(int nbrBombe)
{
    srand(time(NULL));
    for(int i=0;i<nbrBombe;i++)
    {
        int random1 = rand()%1-nbrBombe;
        int random2 = rand()%1-nbrBombe;
        qDebug()<<this->itemAtPosition(random1,random2)->widget();
        /*this->itemAtPosition(random1,random2).setTraped(true);*/
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
