#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

//abstract
class Player;
class Intelligence;

class Enemy:public Player
{
public:

    explicit Enemy();

    virtual void leaveTable() const;
    virtual void makeDecision() const;
    virtual void updateStrategyData () const;

private:

    //std::unique_ptr<Intelligence>intelligence;

};

#endif // ENEMY_H
