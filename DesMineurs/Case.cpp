#include "Case.h"
#include <cstdlib>

Case::Case():a_traped(false),a_flaged(false),a_clicked(false),a_valeur(0){}

bool Case::getTraped()
{
    return a_traped;
}

void Case::setTraped(bool p_traped)
{
    a_traped = p_traped;
}
