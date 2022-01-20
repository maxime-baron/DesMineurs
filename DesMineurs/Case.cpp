#include "Case.h"
#include <QString>
#include <cstdlib>

Case::Case(int posL,int posC):a_traped(false),a_flaged(false),a_clicked(false),a_valeur(0)
{
    a_posL = posL;
    a_posC = posC;
    this->setStyleSheet("border: 1px solid #000;background-color:#fff");//Initialisation du style des cases
}

bool Case::getClicked()
{
    return a_clicked;
}

void Case::setClicked(bool p_clicked)
{
    a_clicked = p_clicked;
}

bool Case::getTraped()
{
    return a_traped;
}

void Case::setTraped(bool p_traped)
{
    a_traped = p_traped;
}

void Case::setFlaged(bool p_flaged)
{
    a_flaged = p_flaged;
}
bool Case::getFlaged()
{
    return a_flaged;
}

void Case::mouseReleaseEvent(QMouseEvent *e) {
        if (e->button() == Qt::RightButton) emit rightClicked();
        else if (e->button() == Qt::LeftButton) emit clicked();
    }

