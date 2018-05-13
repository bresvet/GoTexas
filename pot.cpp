#include "pot.h"

Pot::Pot():QGraphicsTextItem()
{
   value=0;
   setPlainText("Pot: "+QString::number(value));
   setDefaultTextColor(Qt::white);
   setFont(QFont("courier",20));
}

int Pot::getPotValue() const
{
    return value;
}

void Pot::increase(int increaseValue)
{
    value+=increaseValue;
    setPlainText("Pot: " + QString::number(value));
}

void Pot::decreaseToDefault()
{
    value=0;
    setPlainText("Pot: " + QString::number(value));

}


