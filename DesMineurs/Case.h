#ifndef CASE_H
#define CASE_H

#include <QPushButton>
#include <QMouseEvent>

class Case:public QPushButton
{
    Q_OBJECT

private:


signals:
    void rightClicked();

protected:
    bool a_traped;
    bool a_flaged;
    bool a_clicked;
    void mouseReleaseEvent(QMouseEvent *e);

public:
    int a_valeur;
    int a_posL;
    int a_posC;
    Case(int posL,int posC);
    void setValeur(int p_valeur);
    int getValeur();
    void setTraped(bool p_traped);
    bool getTraped();
    void setFlaged(bool p_flaged);
    bool getFlaged();
    void setClicked(bool p_clicked);
    bool getClicked();

//private slots:
//    void mousePressEvent(QMouseEvent *e);

public slots:
};

#endif // CASE_H
