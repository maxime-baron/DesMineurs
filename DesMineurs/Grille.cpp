#include "Grille.h"
#include <cstdlib>
#include <time.h>
//#include <QObjectList>
#include <QLayoutItem>
#include <QDebug>

/*-Constructeur de la grille-*/
Grille::Grille(int lgth):taille(lgth)
{
    this->setSpacing(0);//Aucun espace entre les widgets
    /* INITIALISATION DES CASES DANS LA GRILLE*/
    for(int i=0;i<this->taille;i++)
    {
        for(int y=0;y<this->taille;y++)
        {
            Case* unBouton = new Case(i,y);
            connect(unBouton,&Case::clicked,this,&Grille::bouttonCliquer);
            connect(unBouton,&Case::rightClicked, this,&Grille::onRightClicked);
            //unBouton->setText(QString::number(i)+"-"+QString::number(y));//Affiche la position des boutons
            unBouton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//Taille adaptative
            this->addWidget(unBouton,i,y);
        }
    }
    /* APPELLE DE DYNAMITEEUR */
    int nbrBombe = taille*taille/4;
    this->dynamiteur(nbrBombe);
    this->numerateur();
}

/* -Méthode qui initialise les cases piégé - */
void Grille::dynamiteur(int nbrBombe)
{
    srand(time(NULL));
    for(int i=1;i<nbrBombe;i++)
    {
        int random1 = rand()%taille+0;//Nombre aléatoire entre 0 et taille-1
        int random2 = rand()%taille+0;//Nombre aléatoire entre 0 et taille-1

        QWidget* widget = this->layout()->itemAt( (random1) + (random2) * taille)->widget(); //ici x , y * taille car on se décalle d'une ligne en fonction de la taille
        Case* button = dynamic_cast<Case*>(widget);//Cast du widget en ça classe enfant "Case"
        button->setTraped(true);//Ajt d'une bombe sur la case
        //button->setText(QString::number(button->a_posL)+"-"+QString::number(button->a_posC));//position
        button->setStyleSheet("background-color: red");//CHEAT MODE Colore les bombes en rouges (pour le débbug)
    }
}

/* -Méthode qui initialise la valeur des cases en fonction des bombes- */
void  Grille::numerateur()
{
    /*Boucle qui cherche une bombe*/
    for(int i=0;i<taille;i++)
    {
        for(int y=0;y<taille;y++)
        {
            QWidget* widget = this->layout()->itemAt( (i) + (y) * taille)->widget(); //ici x , y * taille car on se décalle d'une ligne en fonction de la taille puis on récupére le widget
            Case* button = dynamic_cast<Case*>(widget);//Cast du widget en ça classe enfant "Case"

            if(button->getTraped() == true)
            {
                /*Si on trouve une bombe on refais une boucle qui parcour
                les cases jusqu'a trouvé les cases autour de la bombe
                */
                for(int j =0;j<taille;j++)
                {
                    for(int k=0;k<taille;k++)
                    {
                        QWidget* wid = this->layout()->itemAt( (j) + (k) * taille)->widget(); //ici x , y * taille car on se décalle d'une ligne en fonction de la taille puis on récupére le widget
                        Case* btn = dynamic_cast<Case*>(wid);
                        /*Initialisation des valeurs des cases au dessus de la bombe*/
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
                        /*Initialisation des valeurs des cases à coté de la bombe*/
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
                        /*Initialisation des valeurs des cases au dessous de la bombe*/
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

void Grille::bouttonCliquer()
{
    qDebug()<<"test";
    Case *buttoon = (Case *)sender();
    emit digitClicked(buttoon,false);
}

void Grille::onRightClicked()
{
    qDebug()<<"testRight";
    Case *buttoon = (Case *)sender();
    emit digitClicked(buttoon,true);
}

void Grille::digitClicked(Case* cs,bool rgt)
{
    qDebug()<<"test2";
    if(cs->getTraped()==false){
        cs->setText(QString::number(cs->a_valeur));
    }
}
