#ifndef JEU_H
#define JEU_H

#include"Jeu.h"
#include <QtWidgets>

/*namespace Ui {
class Jeu;
}*/

class Jeu : public QMainWindow
{
protected slots:
    void win();
    void lose();
public:
        Jeu();
        ~Jeu();

    private:
        /*Ui::Jeu *ui;*/
        int topScore;
};
#endif // JEU_H
