#ifndef GAMECOUNTER_H
#define GAMECOUNTER_H

#include <QGraphicsTextItem>
#include <QFont>

#include "counter.h"

class GameCounter:public Counter
{
public:

    GameCounter();
    void increase()override;

};

#endif // GAMECOUNTER_H
