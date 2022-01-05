#include "Grille.h"
#include <cstdlib>
#include <time.h>
//#include <QObjectList>
#include <QLayoutItem>
#include <QDebug>

Grille::Grille(int lgth):taille(lgth)
{
    this->setSpacing(0);//Aucun espace entre les widgets

    /* INITIALISATION DES CASES */
    for(int i=0;i<taille;i++)
    {
        for(int y=0;y<taille;y++)
        {
            Case* unBouton = new Case();
            unBouton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//Taille adaptative
            this->addWidget(unBouton,i,y);
        }
    }
    /* APPELLE DE DYNAMITEEUR */
    int nbrBombe = taille*taille/4;//Nombre de bombe = nbr de case / 4
    this->dynamiteur(nbrBombe);
}

void Grille::dynamiteur(int nbrBombe)
{
    srand(time(NULL));
    for(int i=1;i<nbrBombe;i++)
    {
        int random1 = rand()%taille+0;//Nombre aléatoire entre 0 et taille-1
        int random2 = rand()%taille+0;//Nombre aléatoire entre 0 et taille-1

        QLayoutItem* item = this->layout()->itemAt( (random1) + (random2) * taille); //ici x , y * taille car on se décalle d'une ligne en fonction de la taille
        QWidget* widget = item->widget();//Séléction du widget dans l'item
        Case* button = dynamic_cast<Case*>(widget);//Cast du widget en ça classe enfant "Case"
        button->setTraped(true);//Ajt d'une bombe sur la case
        button->setStyleSheet("background-color: red");//Colore les bombes en rouges (pour le débbug)
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
