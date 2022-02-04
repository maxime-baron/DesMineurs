#include "Demineur.h"
#include<QDebug>
#include<QWidget>
#include<QFormLayout>
#include<QLineEdit>
#include<QLabel>
#include <QPushButton>

Demineur::Demineur()
{
    QWidget *zoneCentrale = new QWidget;
    this->resize(QSize(200,200));

    QPushButton *easyButton = new QPushButton("Facile",zoneCentrale);
    connect(easyButton,&QPushButton::clicked,this,&Demineur::playEasy);
    easyButton->resize(QSize(200, 100));

    QPushButton *hardButton = new QPushButton("Difficile",zoneCentrale);
    connect(hardButton,&QPushButton::clicked,this,&Demineur::playHard);
    hardButton->resize(QSize(200, 100));
    hardButton->move(0, 100);

    setCentralWidget(zoneCentrale);

    qDebug()<<"Demineur";
}

void Demineur::lose()
{
    QWidget *zoneCentrale = new QWidget;

    QLabel *label = new QLabel(zoneCentrale);
    label->setText("Vous avez perdu");
    QFont font = label->font();
    font.setPointSize(52);
    font.setBold(true);
    label->setFont(font);
    this->setFixedSize(600,600);


    if(gameDifficult=="Easy"){
        QPushButton *startButton = new QPushButton("Rejouer",zoneCentrale);
        connect(startButton,&QPushButton::clicked,this,&Demineur::playEasy);
        startButton->resize(QSize(100, 50));
        startButton->move(250,100);
    }
    else if(gameDifficult=="Hard"){
        QPushButton *startButton = new QPushButton("Rejouer",zoneCentrale);
        connect(startButton,&QPushButton::clicked,this,&Demineur::playHard);
        startButton->resize(QSize(100, 50));
        startButton->move(250,100);
    }

    QPushButton *quitButton = new QPushButton("Quitter",zoneCentrale);
    connect(quitButton,&QPushButton::clicked,this,&Demineur::quit);
    quitButton->resize(QSize(100, 50));
    quitButton->move(250,152);

    setCentralWidget(zoneCentrale);
    qDebug()<<"lose";
}

void Demineur::win()
{
    QWidget *zoneCentrale = new QWidget;

    QLabel *label = new QLabel(zoneCentrale);
    label->setText("Vous avez gagner");
    QFont font = label->font();
    font.setPointSize(52);
    font.setBold(true);
    label->setFont(font);
    this->setFixedSize(600,600);

    if(gameDifficult=="Easy"){
        QPushButton *startButton = new QPushButton("Rejouer",zoneCentrale);
        connect(startButton,&QPushButton::clicked,this,&Demineur::playEasy);
        startButton->resize(QSize(100, 50));
        startButton->move(250,100);
    }
    else if(gameDifficult=="Hard"){
        QPushButton *startButton = new QPushButton("Rejouer",zoneCentrale);
        connect(startButton,&QPushButton::clicked,this,&Demineur::playHard);
        startButton->resize(QSize(100, 50));
        startButton->move(250,100);
    }

    QPushButton *quitButton = new QPushButton("Quitter",zoneCentrale);
    connect(quitButton,&QPushButton::clicked,this,&Demineur::quit);
    quitButton->resize(QSize(100, 50));
    quitButton->move(250,152);

    setCentralWidget(zoneCentrale);
    qDebug()<<"win";
}

void Demineur::playEasy()
{
    gameDifficult= "Easy";
    QWidget *zoneCentrale = new QWidget;

    Grille *maGrille = new Grille(5);
    connect(maGrille,&Grille::lose,this,&Demineur::lose);
    connect(maGrille,&Grille::win,this,&Demineur::win);
    this->setFixedSize(600,600);

    setCentralWidget(zoneCentrale);
    zoneCentrale->setLayout(maGrille);
}

void Demineur::playHard()
{
    gameDifficult= "Hard";
    QWidget *zoneCentrale = new QWidget;

    Grille *maGrille = new Grille(10);
    connect(maGrille,&Grille::lose,this,&Demineur::lose);
    connect(maGrille,&Grille::win,this,&Demineur::win);
    this->setFixedSize(600,600);

    setCentralWidget(zoneCentrale);
    zoneCentrale->setLayout(maGrille);
}

void Demineur::quit()
{
    close();
}
