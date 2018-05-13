#include "counter.h"

Counter::Counter():QGraphicsTextItem()
{
   setDefaultTextColor(Qt::white);
   setFont(QFont("courier",20));
   this->counter=0;
}


void Counter::increase()
{
   counter++;
}

int Counter::getCounter() const
{
    return counter;
}
