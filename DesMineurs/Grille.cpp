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
            Case* unBouton = new Case(i,y);
            //unBouton->setText(QString::number(i)+"-"+QString::number(y));//position
            unBouton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//Taille adaptative
            this->addWidget(unBouton,i,y);
        }
    }
    /* APPELLE DE DYNAMITEEUR */
    int nbrBombe = taille*taille/4;
    this->dynamiteur(nbrBombe);
    this->numerateur();

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
        //button->setText(QString::number(button->a_posL)+"-"+QString::number(button->a_posC));//position
        //button->setStyleSheet("background-color: red");//Colore les bombes en rouges (pour le débbug)
    }
}

void  Grille::numerateur()
{
    for(int i=0;i<taille;i++)
    {
        for(int y=0;y<taille;y++)
        {
            QLayoutItem* item = this->layout()->itemAt( (i) + (y) * taille); //ici x , y * taille car on se décalle d'une ligne en fonction de la taille
            QWidget* widget = item->widget();//Séléction du widget dans l'item
            Case* button = dynamic_cast<Case*>(widget);//Cast du widget en ça classe enfant "Case"

            if(button->getTraped() == true)
            {
                for(int j =0;j<taille;j++)
                {
                    for(int k=0;k<taille;k++)
                    {
                        QWidget* wid = this->layout()->itemAt( (j) + (k) * taille)->widget(); //ici x , y * taille car on se décalle d'une ligne en fonction de la taille
                        Case* btn = dynamic_cast<Case*>(wid);
                        for(int LH = -1;LH<2;LH++)
                        {
                            if(btn->a_posL == button->a_posL-1 && btn->a_posC == button->a_posC-LH)
                            {
                                if(btn->getTraped()!=true)
                                {
                                    btn->a_valeur++;
                                }
                            }
                        }
                        for(int L = -1;L<2;L++)
                        {
                            if(btn->a_posL == button->a_posL && btn->a_posC == button->a_posC-L)
                            {
                                if(btn->getTraped()!=true)
                                {
                                    btn->a_valeur++;
                                }
                            }
                        }
                        for(int LB = -1;LB<2;LB++)
                        {
                            if(btn->a_posL == button->a_posL+1 && btn->a_posC == button->a_posC-LB)
                            {
                                if(btn->getTraped()!=true)
                                {
                                    btn->a_valeur++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
//    for(int i=0;i<taille;i++)
//    {
//        for(int y=0;y<taille;y++)
//        {
//            QLayoutItem* item = this->layout()->itemAt( (i) + (y) * taille); //ici x , y * taille car on se décalle d'une ligne en fonction de la taille
//            QWidget* widget = item->widget();//Séléction du widget dans l'item
//            Case* button = dynamic_cast<Case*>(widget);//Cast du widget en ça classe enfant "Case"

//            button->setText(QString::number(button->a_valeur));
//        }
//    }
}

void Grille::setTaille(int p_taille)
{
    this->taille = p_taille;
}

int Grille::getTaille()
{
    return this->taille;
}
void Grille::click()
{
    for (int i = 0; i < taille; i++)
        {
            for (int j = 0; j < taille; j++)
            {
                connect(this->recuperationQPushButton(i,j),&Case::clicked,this,&Grille::bouttonCliquer);
            }
        }
}

void Grille::recuperationQPushButton(int x,int y)
{
    QLayoutItem* item = this->layout()->itemAt( (x-1) + (y-1) * 4); //ici x , y * 4 car on se décalle d'une ligne de 4
    QWidget* widget = item->widget();
    QPushButton* button = dynamic_cast<QPushButton*>(widget);
    return button;
}
void Grille::bouttonCliquer()
{

}
