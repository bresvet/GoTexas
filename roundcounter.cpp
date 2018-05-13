#include "roundcounter.h"

RoundCounter::RoundCounter()
{
setPlainText("Round: "+QString::number(counter));
}

void RoundCounter::increase()
{
    setPlainText("Round: " + QString::number(counter));
}

