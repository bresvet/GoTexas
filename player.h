#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QGraphicsTextItem>
#include <algorithm>
#include <memory>

class Card;
class Game;

//abstract base player class
class Player:public QObject
{
    Q_OBJECT
friend class Round;
friend class Game;
friend class Auction;

public:

static bool mainPowerCompare(const Player &player1,const Player &player2);
static bool secondaryPowerCompare(const Player &player1,const Player &player2);
static bool cashValueCompare(const Player &player1,const Player &player2);

static QString getName();

explicit Player(short unsigned index,QString name,std::shared_ptr<Game>game);

virtual ~Player();

  //Player(const Player &pla);
  //  Player(Player &&pla);
  //Player &operator=(const Player &pla);
  //  Player &operator=(Player &&pla);
private:

static unsigned short instancesCounter;

short unsigned index;

QString name;

std::shared_ptr<Game>game;

std::unique_ptr<QGraphicsTextItem>cashText;

int cashValue;

std::vector<std::shared_ptr<Card>>creatingHandCards;
std::vector<std::shared_ptr<Card>>sortedCHC;

std::vector<std::shared_ptr<Card>>updatingCourtCardList;
std::vector<std::shared_ptr<Card>>updatingStraightCardList;
std::vector<std::shared_ptr<Card>>updatingColorCardList;

std::vector<int>updatingCourtIntegerList;
std::vector<int>updatingColorIntegerList;
std::vector<int>updatingStraightIntegerList;

std::vector<std::pair<int,int>>possibleHandSecondaryPowers;
std::vector<std::pair<int,int>>secondPowersComparetorVec;


virtual void appendPlayerHand();
virtual void updateHandInfo();
virtual void updateHandMainPower();
virtual void updatePossibleHandSecondaryPowers();

virtual void createCourtHelpList();
virtual void createColorHelpList();
virtual void createStraightHelpList();
virtual void createHelpLists();

short unsigned int handMainPower;
short unsigned int handSecondaryPower;

virtual void increaseCash(int upValue);
virtual void decreaseCash(int downValue);

unsigned long mpisa;//money put in single auction
unsigned long mpisr;//money put in single round

};



#endif // PLAYER_H
