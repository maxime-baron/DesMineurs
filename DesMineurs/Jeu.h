#ifndef JEU_H
#define JEU_H

#include"Jeu.h"
#include <QMainWindow>

namespace Ui {
class Jeu;
}

class Jeu : public QMainWindow
{
    Q_OBJECT

public:
    void win();
    void lose();
    explicit Jeu(QWidget *parent = 0);
    ~Jeu();

private:
    Ui::Jeu *ui;
    int topScore;
};
#endif // JEU_H
