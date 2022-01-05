#include "Jeu.h"
#include "ui_jeu.h"

Jeu::Jeu()
{
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
}

/*Jeu::Jeu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Jeu)
    {
        ui->setupUi(this);
    }
*/
Jeu::~Jeu()
{
}

