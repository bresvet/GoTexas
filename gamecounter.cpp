#include "gamecounter.h"

GameCounter::GameCounter()
{
setPlainText("Game: "+QString::number(counter));
}

void GameCounter::increase()
{
    setPlainText("Game: " + QString::number(counter));
}
