#ifndef UIGAGNE_H
#define UIGAGNE_H
#include "Demineur.h"
#include <QString>

class Demineur;
class UIgagne
{
private:
    Demineur * leDemineur;
public:
    UIgagne();
    QString getUsername();
};

#endif // UIGAGNE_H
