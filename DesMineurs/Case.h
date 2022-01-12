#ifndef CASE_H
#define CASE_H

#include <QPushButton>

class Case:public QPushButton
{
private:
    bool a_traped;
    bool a_flaged;
    bool a_clicked;

protected:

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
};

#endif // CASE_H
