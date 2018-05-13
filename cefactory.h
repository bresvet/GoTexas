#ifndef CEFACTORY_H
#define CEFACTORY_H

#include "plafactory.h"
#include "coopene.h"

class Coopene;

class Cefactory:public Plafactory<Coopene>
{
friend class Game;

private:

  //std::unique_ptr<Player>createPlayer() override;

//std::unique_ptr<>createCreate();

};


#endif // CEFACTORY_H
