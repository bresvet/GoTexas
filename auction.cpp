#include "auction.h"
#include "round.h"
#include "player.h"

#include <QRect>
#include <QPaintEvent>
#include <QWidget>
#include <QSlider>

int Auction::auctionActionCounter=0;

Auction::Auction(int whichNumber,std::shared_ptr<Round>round)
    :numberOfAuction(whichNumber),round(round)
{
nextAuction=false;
isBetted=false;
}

std::shared_ptr<Player>Auction::whosTurn() const
{
    return round->roundCompetitors[this->auctionActionCounter % round->competitorsQuantity];
}

std::shared_ptr<Player> Auction::nextPlayer() const
{
    return round->roundCompetitors[this->auctionActionCounter % round->competitorsQuantity + 1];
}

std::shared_ptr<Player> Auction::previousPlayer() const
{
    return round->roundCompetitors[this->auctionActionCounter % round->competitorsQuantity - 1];
}

void Auction::resetAuctionActionCounter()
{
    this->auctionActionCounter=0;
}

void Auction::resetMpisa()
{
std::for_each(round->roundCompetitors.begin(),round->roundCompetitors.end(),
              [&](std::shared_ptr<Player>player)mutable{player->mpisa=0;});
}

void Auction::updateInfo()
{
    if(std::any_of(round->roundCompetitors.begin(),round->roundCompetitors.end(),
            [&](std::shared_ptr<Player>player)->bool{player->mpisa!=0;}))
    {
    isBetted=true;
    }
    if(std::all_of(round->roundCompetitors.begin(),round->roundCompetitors.end(),
                   [&](std::shared_ptr<Player>player)->bool{player->mpisa==0;}) && auctionActionCounter>=2)
    {
            nextAuction=true;
    }
}
