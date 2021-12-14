#include "Jeu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Jeu w;
    w.show();
    
    return a.exec();
}
