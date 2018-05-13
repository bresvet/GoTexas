#ifndef AUCTION_H
#define AUCTION_H


#include <QWidget>
#include <QSlider>
#include <memory>



class Player;
class Round;

class Auction
{
public:

explicit Auction(int whichNumber,std::shared_ptr<Round>round);

static int auctionActionCounter;

bool nextAuction;

bool isBetted;

std::shared_ptr<Round>round;

short int numberOfAuction;

std::shared_ptr<Player>whosTurn() const;
std::shared_ptr<Player>nextPlayer() const;
std::shared_ptr<Player>previousPlayer() const;

void resetAuctionActionCounter();

void resetAuctionBools();

void resetMpisa();

void updateInfo();

};

#endif // AUCTION_H
