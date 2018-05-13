#ifndef ROUND_COUNTER_H
#define ROUND_COUNTER_H

#include <QGraphicsTextItem>
#include <QFont>

#include "counter.h"

class RoundCounter:public Counter
{
public:

RoundCounter();
void increase()override;

};
#endif // ROUND_COUNTER_H
