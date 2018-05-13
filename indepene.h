#ifndef INDEPENE_H
#define INDEPENE_H

#include "enemy.h"

class Indepene:public Enemy
{
public:

    Indepene();

    void makeThisCooperating();
    void getPlayIntelligenceRate() const;

};

#endif // INDEPENE_H
