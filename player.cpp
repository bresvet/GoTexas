#include "player.h"
#include <QFont>
#include "boost/bind.hpp"
#include "boost/iterator.hpp"
#include "boost/iterator_adaptors.hpp"
#include <functional>
#include "game.h"
#include "deck.h"
#include "button.h"


unsigned short Player::instancesCounter=0;

//temporary
bool Player::mainPowerCompare(const Player &player1,const Player &player2)
{
    return player1.handMainPower > player2.handMainPower;
}

bool Player::secondaryPowerCompare(const Player &player1,const Player &player2)
{
    return player1.handSecondaryPower > player2.handSecondaryPower;
}

bool Player::cashValueCompare(const Player &player1,const Player &player2)
{
    return player1.cashValue > player2.cashValue;
}

Player::Player(short unsigned index,QString name,std::shared_ptr<Game>game)
    :name(name),game(game)
{
cashValue=game.get()->defaultCash;
cashText=std::make_unique<QGraphicsTextItem>();
cashText->setFont(QFont("courier",20));
cashText->setDefaultTextColor(Qt::white);
cashText->setPlainText("Cash :"+ QString::number(this->cashValue));
mpisa=0;
}

Player::~Player()
{

}

void Player::appendPlayerHand()
{

    creatingHandCards.erase(creatingHandCards.begin(),creatingHandCards.end());

    sortedCHC.erase(sortedCHC.begin(),sortedCHC.end());

    creatingHandCards.push_back(game.get()->deck.get()->undealed[2*this->index]);
    creatingHandCards.push_back(game.get()->deck.get()->undealed[2*this->index+1]);

    creatingHandCards.push_back(game.get()->deck.get()->undealed[this->instancesCounter*2]);
    creatingHandCards.push_back(game.get()->deck.get()->undealed[this->instancesCounter*2+1]);
    creatingHandCards.push_back(game.get()->deck.get()->undealed[this->instancesCounter*2+2]);
    creatingHandCards.push_back(game.get()->deck.get()->undealed[this->instancesCounter*2+3]);
    creatingHandCards.push_back(game.get()->deck.get()->undealed[this->instancesCounter*2+4]);

    sortedCHC=creatingHandCards;


}

void Player::updateHandInfo()
{
    updateHandMainPower();
    updatePossibleHandSecondaryPowers();
}

void Player::updateHandMainPower()
{


    if(*(std::max_element(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end()))==1)
    {
        handMainPower=1;//high card
    }

    if(*(std::max_element(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end()))==2)
    {
        handMainPower=2;//one pair
    }

    if(*(std::max_element(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end()))==2
            && std::count_if(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end(),[](int i){return(i==2);})>=4)
    {
        handMainPower=3;//two pairs
    }

    if(*(std::max_element(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end()))==3)
    {
        handMainPower=4;//three of a kind
    }

    if(std::accumulate(updatingStraightIntegerList.begin(),updatingStraightIntegerList.end(),0)==5)
    {
        handMainPower=5;//straight
    }

    if(*(std::max_element(updatingColorIntegerList.begin(),updatingColorIntegerList.end()))==5)
    {
        handMainPower=6;//flush
    }

    if(*(std::max_element(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end()))==3
            && std::binary_search(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end(),2))
    {
        handMainPower=7;//full house
    }

    if(*(std::max_element(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end()))==4)
    {
        handMainPower=8;//four of a kind
    }

    if(std::accumulate(updatingStraightIntegerList.begin(),updatingStraightIntegerList.end(),0)==5
            && *(std::max_element(updatingColorIntegerList.begin(),updatingColorIntegerList.end()))==5)
    {
        handMainPower=9;//straight flush
    }

}

void Player::updatePossibleHandSecondaryPowers()
{
    possibleHandSecondaryPowers.erase(possibleHandSecondaryPowers.begin(),possibleHandSecondaryPowers.end());
    secondPowersComparetorVec.erase(secondPowersComparetorVec.begin(),secondPowersComparetorVec.end());

    if(handMainPower==1 || handMainPower==2 || handMainPower==3 || handMainPower==4 || handMainPower==7)
{


       for(auto updateItCourt=std::make_pair(updatingCourtIntegerList.begin(),creatingHandCards.begin())
           ;updateItCourt.first<updatingCourtIntegerList.end(),updateItCourt.second<creatingHandCards.end()
           ;updateItCourt.first++,updateItCourt.second++)
     {
         possibleHandSecondaryPowers.push_back(std::make_pair(*(updateItCourt.first),(*(updateItCourt.second))->courtPower));

     }

}

    if(handMainPower==6 || handMainPower==9)
{
        for(auto updateItColor=std::make_pair(updatingColorIntegerList.begin(),creatingHandCards.begin())
            ;updateItColor.first<updatingColorIntegerList.end(),updateItColor.second<creatingHandCards.end()
            ;updateItColor.first++,updateItColor.second++)
     {
         possibleHandSecondaryPowers.push_back(std::make_pair(*(updateItColor.first),(*(updateItColor.second))->colorPower));
     }

}

    if(handMainPower==5)

 {
          for(auto updateItStraight=std::make_pair(updatingStraightIntegerList.begin(),sortedCHC.begin())
              ;updateItStraight.first<updatingStraightIntegerList.end(),updateItStraight.second<sortedCHC.end()
              ;updateItStraight.first++,updateItStraight.second++)

     {
         possibleHandSecondaryPowers.push_back(std::make_pair(*(updateItStraight.first),(*(updateItStraight.second))->courtPower));
     }

}
    secondPowersComparetorVec=possibleHandSecondaryPowers;
    std::sort(secondPowersComparetorVec.begin(),secondPowersComparetorVec.end());

}

void Player::createCourtHelpList()
{
    updatingCourtIntegerList.erase(updatingCourtIntegerList.begin(),updatingCourtIntegerList.end());

    for(auto it=creatingHandCards.begin();it<creatingHandCards.end();it++)
    {
        updatingCourtIntegerList.push_back(std::count_if(creatingHandCards.begin(),creatingHandCards.end()
            ,[&it](std::shared_ptr<Card>card){return card->courtPower==(*it)->courtPower;}));
    }
}

void Player::createColorHelpList()
{
    updatingColorIntegerList.erase(updatingColorIntegerList.begin(),updatingColorIntegerList.end());

     for(auto it=creatingHandCards.begin();it<creatingHandCards.end();it++)
     {
         updatingColorIntegerList.push_back(std::count_if(creatingHandCards.begin(),creatingHandCards.end()
                                                       ,[&it](std::shared_ptr<Card>card){return card->colorPower==(*it)->colorPower;}));
     }
}

void Player::createStraightHelpList()
{
    std::sort(sortedCHC.begin(),sortedCHC.end());

    updatingStraightIntegerList.erase(updatingStraightIntegerList.begin(),updatingStraightIntegerList.end());



    for(auto it=std::next(sortedCHC.begin());it<std::prev(sortedCHC.end());it++)
    {
        auto pv=std::prev(it);
        auto nx=std::next(it);
        updatingStraightIntegerList.push_back(((*it)->courtPower+1 == (*pv)->courtPower )
                                           && ((*it)->courtPower-1 == (*nx)->courtPower));
    }

   if(std::accumulate(updatingStraightIntegerList.begin(),updatingStraightIntegerList.end(),0)==3)
   {
       std::fill(updatingStraightIntegerList.begin(),updatingStraightIntegerList.end(),1);
   }

}


void Player::createHelpLists()
{
createCourtHelpList();
createColorHelpList();
createStraightHelpList();
}

void Player::increaseCash(int upValue)
{
    cashValue+=upValue;
    cashText->setPlainText("Cash :"+QString::number(cashValue));
}

void Player::decreaseCash(int downValue)
{
    cashValue-=downValue;
    this->mpisa+=downValue;
    this->mpisr+=downValue;
    cashText->setPlainText("Cash :"+QString::number(cashValue));
}


