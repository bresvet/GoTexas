#include "round.h"
#include "cstdlib"
#include <utility>
#include <algorithm>
#include <memory>
#include <tuple>
#include <functional>

#include "game.h"
#include "auction.h"
#include "button.h"
#include "deck.h"
#include "player.h"
#include "pot.h"
#include "roundcounter.h"

std::unique_ptr<Button>Round::raiseButton=nullptr;
std::unique_ptr<Button>Round::callButton=nullptr;
std::unique_ptr<Button>Round::checkButton=nullptr;

std::unique_ptr<Button>Round::foldButton=nullptr;
std::unique_ptr<Button>Round::betButton=nullptr;
std::unique_ptr<Button>Round::allInButton=nullptr;

std::unique_ptr<QSlider>Round::brSlider=nullptr;

std::shared_ptr<Auction>Round::auction=nullptr;
std::shared_ptr<Auction>Round::afterHandAuction=nullptr;
std::shared_ptr<Auction>Round::afterFlopAuction=nullptr;
std::shared_ptr<Auction>Round::afterTurnAuction=nullptr;
std::shared_ptr<Auction>Round::afterRiverAuction=nullptr;

bool Round::auctionButtonClicked=false;

std::unique_ptr<QGraphicsPixmapItem>Round::dv1=nullptr;
std::unique_ptr<QGraphicsPixmapItem>Round::dv2=nullptr;
std::unique_ptr<QGraphicsPixmapItem>Round::dv3=nullptr;

std::unique_ptr<QGraphicsPixmapItem>Round::ev1=nullptr;
std::unique_ptr<QGraphicsPixmapItem>Round::ev2=nullptr;


Round::Round(std::shared_ptr<Game>game)
    :game(game)
{
scene=std::make_unique<QGraphicsScene>();
raiseButton=std::make_unique<Button>(QString("RAISE"),2);
callButton=std::make_unique<Button>(QString("CALL"),2);
checkButton=std::make_unique<Button>(QString("CHECK"),2);
foldButton=std::make_unique<Button>(QString("FOLD"),2);
betButton=std::make_unique<Button>(QString("BET"),2);
allInButton=std::make_unique<Button>(QString("ALL IN"),2);
brSlider=std::make_unique<QSlider>(Qt::Orientation::Horizontal);
brSlider->setTickPosition(QSlider::TicksBothSides);
brSlider->setGeometry(sxPos,syPos,100,25);
betButton->setPos(baxPosBoR,bayPosBoR);
raiseButton->setPos(baxPosBoR,bayPosBoR);
checkButton->setPos(baxPosChoCa,bayPosChoCa);
callButton->setPos(baxPosChoCa,bayPosChoCa);
foldButton->setPos(baxPosF,bayPosF);
allInButton->setPos(baxPosAI,bayPosAI);

dv1=std::make_unique<QGraphicsPixmapItem>();
dv2=std::make_unique<QGraphicsPixmapItem>();
dv3=std::make_unique<QGraphicsPixmapItem>();
ev1=std::make_unique<QGraphicsPixmapItem>();
ev2=std::make_unique<QGraphicsPixmapItem>();

scene->setSceneRect(0,0,800,600);
setBackgroundBrush(QBrush(QImage(":/bcgaoc/background.jpg")));
setScene(scene.get());


/*

(game->you->cashText->setPos(0,500);

game->enemy->cashText->setPos(600,0);
*/

int xDvPos;
int yDvPos;
xDvPos=0;
yDvPos=double(23/100+fi/6+1/2)*sHeight;
dv1->setPos(xDvPos,yDvPos);
dv1->setPixmap(QPixmap(":bcgaoc/cardbackside.jpg").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));
scene.get()->addItem(dv1.get());

xDvPos+=double(1/60)*sWidth;
yDvPos+=double(fi/60)*sHeight;
dv2->setPos(xDvPos,yDvPos);
dv2->setPixmap(QPixmap(":bcgaoc/cardbackside.jpg").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));
scene.get()->addItem(dv2.get());

xDvPos+=double(1/60)*sWidth;
yDvPos+=double(fi/60)*sHeight;
dv3->setPos(xDvPos,yDvPos);
dv3->setPixmap(QPixmap(":bcgaoc/cardbackside.jpg").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));
scene.get()->addItem(dv3.get());

//game->ev1->setPos(375,25);

//scene.get()->addItem(game->ev1);

//game->ev2->setPos(625,25);

//scene.get()->addItem(game->ev2);
}

Round::~Round()
{
    this->close();

    /* delete raiseButton;
     delete callButton;
     delete checkButton;
     delete foldButton;
     delete  betButton;
     delete allInButton;
     delete brSlider;

     delete  dv1;
     delete dv2;
     delete dv3;
     delete ev1;
     delete ev2;

     delete afterHandAuction;
     delete afterFlopAuction;
     delete afterTurnAuction;
     delete  afterRiverAuction;

     delete game->deck;

     */
}
 /*
Round::Round(const Round &rou)
    :raiseButton(nullptr),
      callButton(nullptr),
      checkButton(nullptr),
      foldButton(nullptr),
      betButton(nullptr),
      allInButton(nullptr),
      brSlider(nullptr),
      dv1(nullptr),
       dv2(nullptr),
       dv3(nullptr),
       ev1(nullptr),
      ev2(nullptr),
      afterHandAuction(nullptr),
       afterFlopAuction(nullptr),
      raiseButton(nullptr),
      afterTurnAuction(nullptr),
      afterRiverAuction(nullptr),
      game->deck(nullptr)

{

  raiseButton=new Button(rou.raiseButton->name,rou.raiseButton->m_wt);
  callButton=new Button(rou.callButton->name,rou.callButton->m_wt);
  checkButton=new Button(rou.checkButton->name,rou.checkButton->m_wt);
  foldButton=new Button(rou.foldButton->name,rou.foldButton->m_wt);
  betButton=new Button(rou.betButton->name,rou.betButton->m_wt);
  allInButton=new Button(rou.allInButton->name,rou.allInButton->m_wt);
  brSlider=new Button(rou.brSlider->name,rou.brSlider->m_wt);


  dv1=new QGraphicsPixmapItem(*(rou.dv1));
  dv2=new QGraphicsPixmapItem(*(rou.dv2));
  dv3=new QGraphicsPixmapItem(*(rou.dv3));
  ev1=new QGraphicsPixmapItem(*(rou.ev1));
  ev2=new QGraphicsPixmapItem(*(rou.ev2));

  afterHandAuction=new Auction(*(rou.afterHandAuction));
  afterFlopAuction=new Auction(*(rou.afterFlopAuction));
  afterTurnAuction=new Auction(*(rou.afterTurnAuction));
  afterRiverAuction=std::make_shared< Auction(*(rou.afterRiverAuction));


   game->deck=new Deck(*(rou.game->deck));
}

Round::Round(Round &&rou)
{

}

Round &Round::operator=(const Round &rou)
{

}

Round &Round::operator=(Round &&rou)
{

}
*/
void Round::goRound()
{
    //dis//connect(this,SIGNAL(roundOver()),game.get(),SLOT(beginNextRound()));
    srand(time(NULL));

    resetMpisr();

    afterHandAuction=std::make_shared<Auction>(1,std::enable_shared_from_this<Round>::shared_from_this());
    afterFlopAuction=std::make_shared<Auction>(2,std::enable_shared_from_this<Round>::shared_from_this());
    afterTurnAuction=std::make_shared<Auction>(3,std::enable_shared_from_this<Round>::shared_from_this());
    afterRiverAuction=std::make_shared<Auction>(4,std::enable_shared_from_this<Round>::shared_from_this());

       roundCompetitors=game->competitors;

    for(int x=0;x<2*game.get()->numberOfPlayers+5;x++)
    {
        inRoundPlayingCards.push_back(game->deck.get()->undealed[x]);
    }
    for(int x=0;x<2*game.get()->numberOfPlayers;x++)
    {
        eclipsedCards.push_back(game->deck.get()->undealed[x]);
    }
    for(int x=2*game.get()->numberOfPlayers;x<2*game.get()->numberOfPlayers+5;x++)
    {
        discoveredCards.push_back(game->deck.get()->undealed[x]);
    }

    std::for_each(game.get()->competitors.begin(),game.get()->competitors.end(),
                  [](std::shared_ptr<Player>player){return player.get()->appendPlayerHand();});
    std::for_each(game.get()->competitors.begin(),game.get()->competitors.end(),
                  [](std::shared_ptr<Player>player){return player.get()->createHelpLists();});
    std::for_each(game.get()->competitors.begin(),game.get()->competitors.end(),
                  [](std::shared_ptr<Player>player){return player.get()->updateHandInfo();});

    long xPos;
    long yPos;
    long int sWidth=game.get()->width();
    long int sHeight=game.get()->height();
    int counterOfInserts=0;


    for(int x=0;x<game.get()->numberOfPlayers;x++)
    {
        if(counterOfInserts==0)
        {
        xPos=(double(1/12)+double(1/(game.get()->numberOfPlayers+3)+1))*sWidth;
        yPos=(23/100+1/4+fi/12+1/4)*sHeight;
        inRoundPlayingCards[x].get()->setPos(xPos,yPos);
        xPos+=(1/24)*sWidth;
        inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
        counterOfInserts++;
        }
        if(counterOfInserts==1)
        {
            xPos=(double(1/12)+double(1/(game.get()->numberOfPlayers+3)+1))*sWidth;
            yPos=(23/100)*sHeight;
            inRoundPlayingCards[x].get()->setPos(xPos,yPos);
            counterOfInserts++;
            xPos+=(1/24)*sWidth;
            inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
            counterOfInserts++;
        }
        if(counterOfInserts==2)
        {
            xPos=(23/100)*sWidth;
            yPos=(double(1/12)+double(1/(game.get()->numberOfPlayers+3)))*sHeight;
            inRoundPlayingCards[x].get()->setPos(xPos,yPos);
            counterOfInserts++;
            yPos+=(1/24)*sHeight;
            inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
            counterOfInserts++;
        }
        if(counterOfInserts==3)
        {
            xPos=(23/100+1/4+fi/12+1/4)*sWidth;
            yPos=(double(1/12)+double(1/game.get()->numberOfPlayers))*sHeight;
            inRoundPlayingCards[x].get()->setPos(xPos,yPos);
            counterOfInserts++;
            yPos+=(1/24)*sHeight;
            inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
            counterOfInserts++;
        }
        if(counterOfInserts==4)
        {
            xPos=(double(1/12)+double(1/(game.get()->numberOfPlayers+3))+double(1/2*game.get()->numberOfPlayers))*sWidth;
            yPos=(23/100+1/4+fi/12+1/4)*sHeight;
            inRoundPlayingCards[x].get()->setPos(xPos,yPos);
            counterOfInserts++;
            xPos+=(1/24)*sWidth;
            inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
            counterOfInserts++;
        }

        if(counterOfInserts==5)
        {
        xPos=(double(1/12)+double(1/(game.get()->numberOfPlayers+3))+double(1/game.get()->numberOfPlayers))*sWidth;
        yPos=(23/100)*sHeight;
        inRoundPlayingCards[x].get()->setPos(xPos,yPos);
        xPos+=(1/24)*sWidth;
        inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
        counterOfInserts++;
        }
        if(counterOfInserts==6)
        {
            xPos=(23/100)*sWidth;
            yPos=(double(1/12)+double(1/2*game.get()->numberOfPlayers)+double(1/(game.get()->numberOfPlayers+3)))*sHeight;
            inRoundPlayingCards[x].get()->setPos(xPos,yPos);
            counterOfInserts++;
            yPos+=(1/24)*sHeight;
            inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
            counterOfInserts++;
        }
        if(counterOfInserts==7)
        {

            xPos=(77/100)*sWidth;
            yPos=(double(1/12)+double(1/2*game.get()->numberOfPlayers)+double(1/(game.get()->numberOfPlayers+3)))*sHeight;
            inRoundPlayingCards[x].get()->setPos(xPos,yPos);
            counterOfInserts++;
            xPos+=(1/24)*sWidth;
            inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
            counterOfInserts++;
        }
        if(counterOfInserts==8)
        {
            xPos=(double(1/12)+2*(double(1/(game.get()->numberOfPlayers+3))+double(1/2*game.get()->numberOfPlayers)))*sWidth;
            yPos=double(23/100+1/4+fi+1/4)*sHeight;
            inRoundPlayingCards[x].get()->setPos(xPos,yPos);
            counterOfInserts++;
            xPos+=(1/24)*sWidth;
            inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
            counterOfInserts++;
        }

        if(counterOfInserts==9)
        {
        xPos=(double(1/12)+2*(double(1/(game.get()->numberOfPlayers+3))+double(1/2*game.get()->numberOfPlayers)))*sWidth;
        yPos=double(23/100)*sHeight;
        inRoundPlayingCards[x].get()->setPos(xPos,yPos);
        xPos+=(1/24)*sWidth;
        inRoundPlayingCards[x+1].get()->setPos(xPos,yPos);
        counterOfInserts++;
        }
        roundCompetitors[x]->cashText.get()->setPos(xPos,yPos+(1/30)*sHeight);
    }

    int xDPos=double(1/12)*sWidth;
    int yDPos=double(23/100+fi/12+1/4)*sHeight;

for(int x=0;x<5;x++)
{
    xDPos+=double(5/72)*sWidth;
    inRoundPlayingCards[2*game.get()->numberOfPlayers+x].get()->setPos(xDPos,yDPos);
    scene.get()->addItem(inRoundPlayingCards[2*game.get()->numberOfPlayers+x].get());

}
int xPPos;
int yPPos;

xPPos=(11/12)*sWidth;
yPPos=(11/12)*sHeight;

   game->pot->setPos(xPPos,yPPos);
   game->round_counter->setPos(0,0);


    scene.get()->addItem(game.get()->pot.get());
    scene.get()->addItem(game.get()->round_counter.get());
    for(auto ctIt=roundCompetitors.begin();ctIt<roundCompetitors.end();ctIt++)
    {
    scene.get()->addItem((*ctIt)->cashText.get());
    }

    game->round_counter->setPlainText("Rounds: "+QString::number(game->round_counter->getCounter()));

    scene->addWidget(brSlider.get());

    auction=std::move(afterHandAuction);
    auctionMove(auction);
}


void Round::auctionMove(std::shared_ptr<Auction>auction)
{

    if(auction->numberOfAuction==1)
    {
        sbb();
    }
    auction->updateInfo();
    auto minCashIt=std::min_element(roundCompetitors.begin(),roundCompetitors.end(),
                                     [](std::shared_ptr<Player>player1,std::shared_ptr<Player>player2)->bool
    {return player1->cashValue > player2->cashValue;});
    int minCashVal=(*minCashIt)->cashValue;
    brSlider->setRange(1,minCashVal);
    brSlider->setTickInterval(auction->whosTurn()->cashValue);

if(!auction->isBetted)
{
      scene.get()->addItem(betButton.get());
      scene.get()->addItem(checkButton.get());
      scene.get()->addItem(foldButton.get());
      scene.get()->addItem(allInButton.get());
}

if(auction->isBetted)
{
        scene.get()->addItem(raiseButton.get());
        scene.get()->addItem(callButton.get());
        scene.get()->addItem(foldButton.get());
        scene.get()->addItem(allInButton.get());
}

    //connect(brSlider.get(),SIGNAL(valueChanged(int)),brSlider.get(),SLOT(setValue(int)));
    //connect(betButton.get(),SIGNAL(clicked()),this,SLOT(bet_or_raise()));
    //connect(raiseButton.get(),SIGNAL(clicked()),this,SLOT(bet_or_raise()));
    //connect(checkButton.get(),SIGNAL(clicked()),this,SLOT(check()));
    //connect(callButton.get(),SIGNAL(clicked()),this,SLOT(call()));
    //connect(foldButton.get(),SIGNAL(clicked()),this,SLOT(fold()));
    //connect(allInButton.get(),SIGNAL(clicked()),this,SLOT(allIn()));
}

void Round::sbb()
{
    auction->whosTurn()->decreaseCash(sb);
    auction->nextPlayer()->decreaseCash(bb);
    game->pot->increase(sb+bb);
    auction->auctionActionCounter+=2;
}

void Round::roundIsAboutToBeFinished()
{
    emit roundOver();
}

void Round::bet_or_raise()
{
    //dis//connect(betButton.get(),SIGNAL(clicked()),this,SLOT(bet_or_raise()));
    //dis//connect(raiseButton.get(),SIGNAL(clicked()),this,SLOT(bet_or_raise()));
    game->pot->increase(brSlider->value());
    auction->whosTurn()->decreaseCash(brSlider->value());

   auction->auctionActionCounter++;
   auction->updateInfo();

   brSlider->setValue(0);
   scene->removeItem(raiseButton.get());
   scene->removeItem(callButton.get());
   scene->removeItem(foldButton.get());
   scene->removeItem(allInButton.get());

   afterClickingAction();

}

void Round::fold()
{

   //dis////connect(foldButton.get(),SIGNAL(clicked()),this,SLOT(fold()));
   std::remove(roundCompetitors.begin(),roundCompetitors.end(),auction->whosTurn());
   if(!(auction->isBetted))
    {
      scene->removeItem(betButton.get());
      scene->removeItem(checkButton.get());
      scene->removeItem(foldButton.get());
      scene->removeItem(allInButton.get());
    }

if(auction->isBetted)
    {
        scene->removeItem(raiseButton.get());
        scene->removeItem(callButton.get());
        scene->removeItem(foldButton.get());
        scene->removeItem(allInButton.get());
    }
}


void Round::call()
{
//dis//connect(callButton.get(),SIGNAL(clicked()),this,SLOT(call()));
auto maxCashIt=std::max_element(roundCompetitors.begin(),roundCompetitors.end(),
                                    [](std::shared_ptr<Player>player1,std::shared_ptr<Player>player2)->bool
{return player1->cashValue > player2->cashValue;});

auto minCashIt=std::min_element(roundCompetitors.begin(),roundCompetitors.end(),
                                [](std::shared_ptr<Player>player1,std::shared_ptr<Player>player2)->bool
{return player1->cashValue > player2->cashValue;});

int richestPlayerCashValue=(*maxCashIt)->cashValue;
int poorestPlayerCashValue=(*minCashIt)->cashValue;

int tDiff=richestPlayerCashValue-poorestPlayerCashValue;

auction->whosTurn()->decreaseCash(tDiff);
game->pot->increase(tDiff);
auction->auctionActionCounter++;
auction->updateInfo();

  scene->removeItem(raiseButton.get());
  scene->removeItem(callButton.get());
  scene->removeItem(foldButton.get());
  scene->removeItem(allInButton.get());


  afterClickingAction();
}

void Round::allIn()
{
//dis//connect(allInButton.get(),SIGNAL(clicked()),this,SLOT(allIn()));
auto tItMin=std::min_element(roundCompetitors.begin(),roundCompetitors.end(),
                                [](std::shared_ptr<Player>player1,std::shared_ptr<Player>player2)->bool
{return player1->cashValue > player2->cashValue;});
int tMin=(*tItMin)->cashValue;
game->pot->increase(tMin);
auction->whosTurn()->decreaseCash(tMin);

auction->auctionActionCounter++;

auction->updateInfo();

  if(!(auction->isBetted))
 {
   scene->removeItem(betButton.get());
   scene->removeItem(checkButton.get());
   scene->removeItem(foldButton.get());
   scene->removeItem(allInButton.get());
}

if(auction->isBetted)
{
     scene->removeItem(raiseButton.get());
     scene->removeItem(callButton.get());
     scene->removeItem(foldButton.get());
     scene->removeItem(allInButton.get());
}
afterClickingAction();
}



void Round::check()
{
//dis//connect(checkButton.get(),SIGNAL(clicked()),this,SLOT(check()));
auction->auctionActionCounter++;
auction->updateInfo();
scene->removeItem(betButton.get());
scene->removeItem(checkButton.get());
scene->removeItem(foldButton.get());
scene->removeItem(allInButton.get());
afterClickingAction();
}

void Round::actionAfterHandAuction()
{
    scene.get()->addItem(discoveredCards[0].get());
    scene.get()->addItem(discoveredCards[1].get());
    scene.get()->addItem(discoveredCards[2].get());
    auction=std::move(afterFlopAuction);
    auction->resetAuctionActionCounter();
    auction->resetMpisa();
    auction->resetAuctionBools();
    auction->updateInfo();
    auctionMove(auction);
}

void Round::actionAfterFlopAuction()
{
  scene.get()->addItem(discoveredCards[3].get());
  auction=std::move(afterTurnAuction);
  auction->resetAuctionActionCounter();
  auction->resetMpisa();
  auction->resetAuctionBools();
  auctionMove(auction);
}

void Round::actionAfterTurnAuction()
{
scene.get()->addItem(discoveredCards[4].get());
auction=std::move(afterRiverAuction);
auction->resetAuctionActionCounter();
auction->resetMpisa();
auction->resetAuctionBools();
auctionMove(auction);
}


void Round::finalHandVerification()//actionAfterRiverAuction
{
std::for_each(roundCompetitors.begin(),roundCompetitors.end(),[](std::shared_ptr<Player>player){player->handSecondaryPower=0;});

for(auto y=roundCompetitors.begin();y<=roundCompetitors.end();y++)
{
   auto mapItPlayer=(*y)->secondPowersComparetorVec.rbegin();
   (*y)->handSecondaryPower=(*mapItPlayer).second;
   mapItPlayer=std::prev(mapItPlayer);
}

  auto maxSEleIt=std::max_element(roundCompetitors.begin(),roundCompetitors.end(),
                                  [](std::shared_ptr<Player>player1,std::shared_ptr<Player>player2)->bool
  {return player1->handSecondaryPower > player2->handSecondaryPower;});

  auto maxMEleIt=std::max_element(roundCompetitors.begin(),roundCompetitors.end(),
                                  [](std::shared_ptr<Player>player1,std::shared_ptr<Player>player2)->bool
  {return player1->handMainPower > player2->handMainPower;});

int mainPowerDuplicatesCounter=std::count_if(roundCompetitors.begin(),roundCompetitors.end(),
                                             [&](std::shared_ptr<Player>player)->bool{return player->handMainPower==(*maxMEleIt)->handMainPower;});

int secondaryPowerDuplicatesCounter=std::count_if(roundCompetitors.begin(),roundCompetitors.end(),
                                                  [&](std::shared_ptr<Player>player)->bool{return player->handSecondaryPower==(*maxSEleIt)->handSecondaryPower;});
if(mainPowerDuplicatesCounter==1)
{
    (*maxMEleIt)->increaseCash(game->pot->value);
}

if(mainPowerDuplicatesCounter>1 && secondaryPowerDuplicatesCounter==1)
{
           (*maxSEleIt)->increaseCash(game->pot->value);
}
        if(mainPowerDuplicatesCounter>1 && secondaryPowerDuplicatesCounter>1)
        {
            std::copy_if(roundCompetitors.begin(),roundCompetitors.end(),std::back_inserter(temporaryFinalCompetitorsVec),
                         [&maxSEleIt](std::shared_ptr<Player>player)mutable{return player->handSecondaryPower == (*maxSEleIt)->handSecondaryPower;});
            std::for_each(temporaryFinalCompetitorsVec.begin(),
                          temporaryFinalCompetitorsVec.end(),
                          [&](std::shared_ptr<Player>player)mutable
            {player->increaseCash(game->pot->value/temporaryFinalCompetitorsVec.size());});
        }

//connect(this,SIGNAL(roundOver()),game.get(),SLOT(beginNextRound()));
roundIsAboutToBeFinished();
}

void Round::afterClickingAction()
{
    if(!auction->nextAuction)
    {
       auctionMove(auction);
    }

    if(auction->nextAuction && auction->numberOfAuction==1)
    {
            actionAfterHandAuction();
    }

    if(auction->nextAuction && auction->numberOfAuction==2)
    {
            actionAfterFlopAuction();
    }

    if(auction->nextAuction && auction->numberOfAuction==3)
    {
            actionAfterTurnAuction();
    }

    if(auction->nextAuction && auction->numberOfAuction==4)
    {
            finalHandVerification();
    }

}

void Round::resetMpisr()
{
    std::for_each(roundCompetitors.begin(),roundCompetitors.end(),[](std::shared_ptr<Player>player){player->mpisr=0;});
}



