#ifndef HAND_H
#define HAND_H


#include "deck.h"


class Hand:public Deck
{

public:

    Hand();

    int MainPower();
    int SecondaryPower();




   int yourCounterOfSameCourt=0;
    int yourCounterOfSameColor=0;
    int yourCounterOfSccbnobo=0;//counter of same  courts cards next one by one

    int enemyCounterOfSameCourt=0;
    int enemyCounterOfSameColor=0;
    int enemyCounterOfSccbnobo=0;

    int yourHandPower;//basic hand power(set default for particular hand)
    int yourHandHhcp;//hand highest court power
    int enemyHandPower;
    int enemyHandHhcp;




    bool ifYouHaveHighCard=false;
    bool ifEnemyHasHighCard=false;
    bool ifYouHaveOnePair=false;
    bool ifEnemyHasOnePair=false;
    bool ifYouHaveTwoPairs=false;
    bool ifEnemyHasTwoPairs=false;
    bool ifYouHaveThreeOfAKind=false;
    bool ifEnemyHasThreeOfAKind=false;
    bool ifYouHaveStraight=false;
    bool ifEnemyHasStraight=false;
    bool ifYouHaveFlush=false;
    bool ifEnemyHasFlush=false;
    bool ifYouHaveFullHouse=false;
    bool ifEnemyHasFullHouse=false;
    bool ifYouHaveFourOfAKind=false;
    bool ifEnemyHasFourOfAKind=false;
    bool ifYouHaveStraightFlush=false;
    bool ifEnemyHasStraightFlush=false;

    std::vector<Card*>yourhvecctosethhcp;//your helping List created to set hand highest court power
    std::vector<Card*>enemyhvecctosethhcp;//enemy helping List created to set hand highest court power


};

#endif // HAND_H


