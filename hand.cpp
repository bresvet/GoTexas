#include "hand.h"

Hand::Hand()
{





for(int x=0;x<7;x++)
{
    if(yourHandCards[x]->m_court==yourHandCards[x+1]->m_court && yourHandCards[x+1]->m_court!=yourHandCards[x+2]->m_court)
    {

        yourCounterOfSameCourt++;//one pair
        yourhvecctosethhcp.push_back(yourHandCards[x]);

    }
    if(yourHandCards[x]->m_court==yourHandCards[x+1]->m_court && yourHandCards[x+1]->m_court==yourHandCards[x+2]->m_court
            &&  yourHandCards[x+2]->m_court!=yourHandCards[x+3]->m_court)
    {
        yourCounterOfSameCourt+=9;//three of a kind

        yourhvecctosethhcp.push_back(yourHandCards[x]);
        yourhvecctosethhcp.push_back(yourHandCards[x]);
        yourhvecctosethhcp.push_back(yourHandCards[x]);
        yourhvecctosethhcp.push_back(yourHandCards[x]);
        yourhvecctosethhcp.push_back(yourHandCards[x]);

    }

    if(yourHandCards[x]->m_court==yourHandCards[x+1]->m_court && yourHandCards[x+1]->m_court==yourHandCards[x+2]->m_court
            &&  yourHandCards[x+2]->m_court==yourHandCards[x+3]->m_court)
    {
        yourCounterOfSameCourt+=4;//four of a kind
        yourhvecctosethhcp.push_back(yourHandCards[x]);
    }
    if(yourHandCards[x]->m_color==yourHandCards[x+1]->m_color)
    {
        yourCounterOfSameColor++;
        yourhvecctosethhcp.push_back(yourHandCards[x]);
    }
    if((yourHandCards[x]->m_cpower)+1==yourHandCards[x+1]->m_cpower)

    {

    yourCounterOfSccbnobo++;
     yourhvecctosethhcp.push_back(yourHandCards[x]);

    }



if(yourCounterOfSameCourt==0 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo<4)
{

    ifYouHaveHighCard=true;
    yourHandPower=1;//high card
    yourHandHhcp=yourHandCards[0]->m_cpower;
}

if(yourCounterOfSameCourt==1 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo<4)
{
    ifYouHaveOnePair=true;
    yourHandPower=2;//one pair
    yourHandHhcp=yourhvecctosethhcp[yourhvecctosethhcp.size()-1]->m_cpower;
}


if(yourCounterOfSameCourt==2 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo<4)
{
    ifYouHaveTwoPairs=true;
    yourHandPower=3;//two pairs

    yourHandHhcp=yourhvecctosethhcp[yourhvecctosethhcp.size()-1]->m_cpower;

}

if(yourCounterOfSameCourt==3 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo<4)
{
    ifYouHaveTwoPairs=true;
    yourHandPower=3;
    //two pairs, but 3 pairs in whole hand so to main hand we take two highest pairs
    yourHandHhcp=yourhvecctosethhcp[yourhvecctosethhcp.size()-1]->m_cpower;

}

if(yourCounterOfSameCourt==9 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo<4)
{
    ifYouHaveThreeOfAKind=true;
    yourHandPower=4;//three of a kind
    yourHandHhcp=yourhvecctosethhcp[0]->m_cpower;
}


if(yourCounterOfSameCourt<2 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo>=4)
{
    ifYouHaveStraight=true;
    yourHandPower=5;//straight
    yourHandHhcp=yourhvecctosethhcp[yourhvecctosethhcp.size()-1]->m_cpower;

}


if(yourCounterOfSameCourt<4 && yourCounterOfSameColor>=4 && yourCounterOfSccbnobo<4)
{
    ifYouHaveFlush=true;
    yourHandPower=6;//flush
    cps(yourhvecctosethhcp);
    yourHandHhcp=yourhvecctosethhcp[yourhvecctosethhcp.size()-1]->m_cpower;
}


if(yourCounterOfSameCourt==12 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo<4)
{
    ifYouHaveFullHouse=true;
    yourHandPower=7;//full house
    yourHandHhcp=yourhvecctosethhcp[(yourhvecctosethhcp.size()/2)-1]->m_cpower;

}


if(yourCounterOfSameCourt==4 && yourCounterOfSameColor<4 && yourCounterOfSccbnobo<4)
{
    ifYouHaveFourOfAKind=true;
    yourHandPower=8;//four of a kind
    yourHandHhcp=yourhvecctosethhcp[0]->m_cpower;
}


if(yourCounterOfSameCourt<2 && yourCounterOfSameColor>=4 && yourCounterOfSccbnobo>=4)
{
    ifYouHaveStraightFlush=true;
    yourHandPower=9;//straight flush

    yourHandHhcp=yourhvecctosethhcp[yourhvecctosethhcp.size()-1]->m_cpower;
}

//make the same for enemy

for(int x=0;x<7;x++)
{
    if(enemyHandCards[x]->m_court==enemyHandCards[x+1]->m_court && enemyHandCards[x+1]->m_court!=enemyHandCards[x+2]->m_court)
    {
        enemyCounterOfSameCourt++;//one pair
        enemyhvecctosethhcp.push_back(enemyHandCards[x]);

    }
    if(enemyHandCards[x]->m_court==enemyHandCards[x+1]->m_court && enemyHandCards[x+1]->m_court==enemyHandCards[x+2]->m_court
            &&  yourHandCards[x+2]->m_court!=yourHandCards[x+3]->m_court)
