#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <vector>
#include <memory>

#include "game.h"
//singleton
class Tournament
{
public:
    static std::unique_ptr<Tournament>tournamentInstance();

private:

   Tournament();
   //std::vector<std::unique_ptr<Game>>games;
   static std::unique_ptr<Tournament>tournament;


};

#endif // TOURNAMENT_H
