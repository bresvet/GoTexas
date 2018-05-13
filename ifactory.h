#ifndef IFACTORY_H
#define IFACTORY_H

#include "plafactory.h"
#include "indepene.h"

#include <memory>

class Ifactory:public Plafactory<Indepene>
{
friend class Game;

public:

  //  std::unique_ptr<Player>createPlayer() override;
};
#endif // IFACTORY_H
