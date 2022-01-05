#ifndef JEU_H
#define JEU_H

#include"Jeu.h"
#include <QtWidgets>

/*namespace Ui {
class Jeu;
}*/

class Jeu : public QMainWindow
{
    public:
        void win();
        void lose();
        /*explicit Jeu(QWidget *parent = 0);*/
        Jeu();
        ~Jeu();

    private:
        /*Ui::Jeu *ui;*/
        int topScore;
};
#endif // JEU_H
