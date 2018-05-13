#ifndef PLAFACTORY_H
#define PLAFACTORY_H
#include <memory>
#include <typeinfo>
#include <QString>



class Player;
class Game;

//abstract

template<typename T>

class Plafactory
{
public:

    explicit Plafactory(std::shared_ptr<Game>game)
        :game(game)
    {

    }

 protected:

    std::shared_ptr<Game>game;
    QString instanceTypeName;
    virtual std::unique_ptr<Player>createPlayer();
};

#endif // PLAFACTORY_H
