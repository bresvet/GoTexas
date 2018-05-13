#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QObject>
#include <memory>


class Player;
class Round;
class Cefactory;
class Ifactory;
class Menu;
class Pot;
class RoundCounter;
class Button;
class Deck;
class Card;


class Game:public QGraphicsView,public std::enable_shared_from_this<Game>
{
    Q_OBJECT

public:

    friend class Player;
    friend class Round;

    explicit Game(std::shared_ptr<Menu>menu);
    std::unique_ptr<Pot>pot;
    std::unique_ptr<RoundCounter>round_counter;

   /* ~Game();
    Game(const Game &gam);
    Game(Game &&gam);
    Game &operator=(const Game &gam);
    Game &operator=(Game &&gam);
*/
private:

    std::unique_ptr<Cefactory>cefactory;
    std::unique_ptr<Ifactory>ifactory;

    std::shared_ptr<Round>round;

    std::unique_ptr<QGraphicsScene>scene;

std::unique_ptr<Deck>deck;

std::vector<std::shared_ptr<Player>>competitors;
std::vector<std::shared_ptr<Player>>playersInOrder;
std::vector<std::unique_ptr<Player>>indepens;
std::vector<std::shared_ptr<Player>>coopenes;
std::vector<std::shared_ptr<Player>>enemies;


unsigned long roundsWillBePlayed;
int numberOfPlayers;
bool enemiesCooperates;
unsigned int numberOfCoopenes;
unsigned int numberOfIndepenes;
unsigned int cooperatingEnemiesDensity;
unsigned int defaultCash;
unsigned long smallBlind;
unsigned long bigBlind;



void start();


public slots:



    void beginNextRound();

};


#endif // GAME_H
