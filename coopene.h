#ifndef COOPENE_H
#define COOPENE_H
#include "enemy.h"
#include "intelligence.h"


class Coopene:public Enemy
{
public:

    Coopene();

    void updateCamp() const;
    void contactWithCoop()const;
    void madeThisNeutral();
    void getPlayIntelligenceRate()const;
    void getCooperatingIntelligenceRate()const;
};
#endif // COOPENE_H
