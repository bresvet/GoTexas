#ifndef ROUND_H
#define ROUND_H

#include <QWidget>
#include <QSlider>
#include <QScopedPointer>
#include <QDebug>
#include <QGraphicsView>
#include <cmath>
#include <memory>




class Auction;
class Game;
class Card;
class Button;
class Player;
class Deck;
class Pot;
class RoundCounter;

class Round:public QGraphicsView,public std::enable_shared_from_this<Round>
{
    Q_OBJECT

public:
   explicit Round(std::shared_ptr<Game>game);
    ~Round();
  /*  Round(const Round &rou);
    Round(Round &&rou);
    Round &operator=(const Round &rou);
    Round &&operator=(Round &rou);
*/

std::shared_ptr<Game>game;

void goRound();
void auctionMove(std::shared_ptr<Auction>auction);
static bool auctionButtonClicked;
std::unique_ptr<QGraphicsScene>scene;
bool ifEnd=false;

static std::unique_ptr<Button>raiseButton;
static std::unique_ptr<Button>callButton;
static std::unique_ptr<Button>checkButton;
static std::unique_ptr<Button>foldButton;
static std::unique_ptr<Button>betButton;
static std::unique_ptr<Button>allInButton;

static std::unique_ptr<QSlider>brSlider;//bet or raise slider

static std::shared_ptr<Auction>auction;

static std::shared_ptr<Auction>afterHandAuction;
static std::shared_ptr<Auction>afterFlopAuction;
static std::shared_ptr<Auction>afterTurnAuction;
static std::shared_ptr<Auction>afterRiverAuction;


std::vector<std::shared_ptr<Card>>inRoundPlayingCards;
std::vector<std::shared_ptr<Card>>discoveredCards;
std::vector<std::shared_ptr<Card>>eclipsedCards;

std::vector<std::shared_ptr<Player>>roundCompetitors;
std::vector<std::shared_ptr<Player>>temporaryFinalCompetitorsVec;

size_t competitorsQuantity=roundCompetitors.size();

static std::unique_ptr<QGraphicsPixmapItem>dv1;//deckviewfirst
static std::unique_ptr<QGraphicsPixmapItem>dv2;//deckviewsecond
static std::unique_ptr<QGraphicsPixmapItem>dv3;//deckviewthrid
static std::unique_ptr<QGraphicsPixmapItem>ev1;//enemyviewfirst
static std::unique_ptr<QGraphicsPixmapItem>ev2;//enemyviewsecond

void sbb();// small and big blind
void roundIsAboutToBeFinished();

void actionAfterHandAuction();
void actionAfterFlopAuction();
void actionAfterTurnAuction();
void finalHandVerification();
void afterClickingAction();

void resetMpisr();



public slots:

void fold();
void check();
void bet_or_raise();
void call();
void allIn();


signals:

void roundOver();

private:

int sHeight=scene->height();
int sWidth=scene->width();
const double fi=(1+sqrt(5))/2;

const int sxPos=675;
const int syPos=525;

const int sixPos=675;
const int siyPos=575;

const int baxPosBoR=550;
const int bayPosBoR=450;

const int baxPosChoCa=550;
const int bayPosChoCa=500;

const int baxPosAI=675;
const int bayPosAI=475;

const int baxPosF=550;
const int bayPosF=550;

const int sb=50;
const int bb=100;
};

#endif // ROUND_H
