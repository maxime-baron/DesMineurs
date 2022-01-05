#include <QApplication>
#include <QApplication>
#include<QDebug>
#include "Demineur.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Demineur fenetre;
    fenetre.show();
    
    return app.exec();
}
