#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QObjectList>
#include <QLayoutItem>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // étape 1 : on crée une grille de fond
    QGridLayout *mylayout =new QGridLayout();
    for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // étape 2 : on crée des boutons à la volée
                QPushButton* unBouton = new QPushButton();
                unBouton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                // étape 3 : on les disposes sur la grille
                mylayout->addWidget(unBouton,i,j);
            }
        }
    // étape 4 : on associe ce layout à cette fenetre courante (instance en cours)  "this" de la classe (Widget)
    this->setLayout(mylayout);

    //modif du text d'un bouton
    this->changeTextBouton(2,4,"il fait beau");
    //modif de l'image d'un bouton
    this->changeImageBouton(1,2,"://img/image_croix.png");


    //je récupère un boutton 3, 3 au hazard et je gère le click ! vers une fonction de modif image
    QPushButton *myBtn = this->recuperationQPushButton(3,3);
    QObject::connect(myBtn,
                     &QPushButton::clicked,  //static_cast<void (QPushButton::*)(bool)>(
                    this,
                     &Widget::boutonClicked
                     );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeTextBouton(int x, int y, QString text){

    QPushButton * monBtn;
    monBtn = recuperationQPushButton( x, y);
    // modif du text
    monBtn->setText(text);

}

void Widget::changeImageBouton(int x,int y,QString lienImageRessources)
{
    QPushButton * monBtn;
    monBtn = recuperationQPushButton( x, y);
    QPixmap pixmap(lienImageRessources);  //attention à ajouter au ressources images du projet, et y récuperer le path chemin
    QIcon iconBack(pixmap);                    //Qressources sur Qt video lien
    monBtn->setIcon(iconBack);
    monBtn->setIconSize(QSize(65, 65));



}

QPushButton * Widget::recuperationQPushButton(int x,int y)
{
    // récupération des boutons enfants du gridlayout
    QObjectList maList = this->layout()->children();

    // récupération du bouton en x = 1, y = 2 de la grille

    QLayoutItem* item = this->layout()->itemAt( (x-1) + (y-1) * 4); //ici x , y * 4 car on se décalle d'une ligne de 4
    QWidget* widget = item->widget();
    QPushButton* button = dynamic_cast<QPushButton*>(widget);
    return button;
}

void Widget::boutonClicked(bool value)
{
    qDebug()<< "test value :"<<value;
    this->changeImageBouton(3,3,"://img/rond vide.png");
}

