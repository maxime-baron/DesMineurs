#ifndef CASE_H
#define CASE_H

class Case:
{
private:
    bool a_traped;
    bool a_flaged;
    bool a_clicked;

protected:
    int a_valeur;
public:
    Case();
    setValeur(int p_valeur);
    getValeur();
    setTraped(bool p_traped);
    getTraped();
    setFlaged(bool p_flaged);
    getFlaged();
    setClicked(bool p_clicked);
    getClicked();
};

#endif // CASE_H
