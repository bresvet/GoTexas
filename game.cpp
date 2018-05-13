#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPixmap>
#include <vector>

#include "game.h"
#include "pot.h"
#include "deck.h"
#include "roundcounter.h"
#include "button.h"
#include "round.h"
#include "cefactory.h"
#include "ifactory.h"

Game::Game(std::shared_ptr<Menu>menu)
{
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
showFullScreen();
scene=std::make_unique<QGraphicsScene>();
scene->setSceneRect(0,0,this->width(),this->height());
setBackgroundBrush(QBrush(QImage(":/bcgaoc/mainMenuBackround.jpeg")));
setScene(scene.get());
}


/*Game::~Game()
{
    this->close();

    delete playButton;
    delete settingsButton;
    delete aboutButton;
    delete donateButton;
    delete helpButton;
    delete exitButton;

    //delete round;
    delete pot;
    delete round_counter;

    delete you;
    delete enemy;


}

Game::Game(const Game &gam)
    :
      tournamentButton(nullptr),
      playButton(nullptr),
      settingsButton(nullptr),
      aboutButton(nullptr),
      donateButton(nullptr),
      helpButton(nullptr),
      exitButton(nullptr),
      round(nullptr),
      pot(nullptr),
      round_counter(nullptr),
      you(nullptr),
      enemy(nullptr)

{

    playButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    tournamentButton=std::make_unique< Button(gam.tournamentButton->name,gam.tournamentButton->m_wt);
    settingsButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    aboutButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    donateButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    helpButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    exitButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);


    round=std::make_unique<Round>();
    pot=std::make_unique< Pot();
    round_counter=std::make_unique< RoundCounter();

    you=std::make_unique< Player(gam.you->name);
    enemy=std::make_unique< Player(gam.enemy->name);
}

Game::Game(Game &&gam)
    :
      tournamentButton(gam.playButton),
      playButton(gam.playButton),
      settingsButton(gam.settingsButton),
      aboutButton(gam.aboutButton),
      donateButton(gam.donateButton),
      helpButton(gam.helpButton),
      exitButton(gam.exitButton),
      round(gam.round),
      pot(gam.pot),
      round_counter(gam.round_counter),
      you(gam.you),
      enemy(gam.enemy)
{
    tournamentButton=nullptr;
    playButton=nullptr;
    settingsButton=nullptr;
    aboutButton=nullptr;
    donateButton=nullptr;
    helpButton=nullptr;
    exitButton=nullptr;

    round=nullptr;
    pot=nullptr;
    round_counter=nullptr;

    you=nullptr;
    enemy=nullptr;
}

Game &Game::operator=(const Game &gam)
{

    Button *tmp_tournamentButton=std::make_unique< Button(gam.tournamentButton->name,gam.tournamentButton->m_wt);
    Button *tmp_playButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    Button *tmp_settingsButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    Button *tmp_aboutButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    Button *tmp_donateButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    Button *tmp_helpButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);
    Button *tmp_exitButton=std::make_unique< Button(gam.playButton->name,gam.playButton->m_wt);

   // auto tmp_round=std::make_unique<Round>();
    Round::SPointer tmp_round=std::make_unique<Round>();
    Pot *tmp_pot=std::make_unique< Pot();
    RoundCounter *tmp_round_counter=std::make_unique< RoundCounter();

    Player *tmp_you=std::make_unique< Player(gam.you->name);
    Player *tmp_enemy=std::make_unique< Player(gam.enemy->name);

    delete tournamentButton;
    delete playButton;
    delete settingsButton;
    delete aboutButton;
    delete donateButton;
    delete helpButton;
    delete exitButton;

    //delete round;
    delete pot;
    delete round_counter;

    delete you;
    delete enemy;

  tournamentButton=tmp_tournamentButton;
  playButton=tmp_playButton;
  settingsButton=tmp_settingsButton;
  aboutButton=tmp_aboutButton;
  donateButton=tmp_donateButton;
  helpButton=tmp_helpButton;
  exitButton=tmp_exitButton;

  round=tmp_round;
  pot=tmp_pot;
  round_counter=tmp_round_counter;

  you=tmp_you;
  enemy=tmp_enemy;

  return *this;

}

Game &Game::operator=(Game &&gam)
{
    if(this!=&gam)
    {
        delete tournamentButton;
        delete playButton;
        delete settingsButton;
        delete aboutButton;
        delete donateButton;
        delete helpButton;
        delete exitButton;

       // delete round;
        delete pot;
        delete round_counter;

        delete you;
        delete enemy;

        tournamentButton=gam.tournamentButton;
        playButton=gam.playButton;
        settingsButton=gam.settingsButton;
        aboutButton=gam.aboutButton;
        donateButton=gam.donateButton;
        helpButton=gam.helpButton;
        exitButton=gam.exitButton;

        gam.round=nullptr;
        gam.pot=nullptr;
        gam.round_counter=nullptr;

        gam.you=nullptr;
        gam.enemy=nullptr;

        gam.tournamentButton=nullptr;
        gam.playButton=nullptr;
        gam.settingsButton=nullptr;
        gam.aboutButton=nullptr;
        gam.donateButton=nullptr;
        gam.helpButton=nullptr;
        gam.exitButton=nullptr;

        gam.round=nullptr;
        gam.pot=nullptr;
        gam.round_counter=nullptr;

        gam.you=nullptr;
        gam.enemy=nullptr;
    }

    return *this;
}
*/



void Game::start()
{
    round_counter=std::make_unique<RoundCounter>();
    pot=std::make_unique<Pot>();

    for(int x=0;x<numberOfCoopenes;x++)
    {
        competitors.push_back(std::move(cefactory->createPlayer()));
    }

    for(int x=0;x<numberOfIndepenes;x++)
    {
        competitors.push_back(std::move(ifactory->createPlayer()));
    }

    deck=std::make_unique<Deck>();
    round=std::make_unique<Round>(std::enable_shared_from_this<Game>::shared_from_this());
    connect(round.get(),SIGNAL(roundOver()),this,SLOT(beginNextRound()));
    scene->clear();
    round->show();
    round->goRound();
}



void Game::beginNextRound()
{

    for(auto &remIt:round->discoveredCards)
    {
        round->scene->removeItem(remIt.get());
    }


    pot->decreaseToDefault();
    round_counter->increase();
    round->goRound();

    disconnect(round.get(),SIGNAL(roundOver()),this,SLOT(beginNextRound()));
}

