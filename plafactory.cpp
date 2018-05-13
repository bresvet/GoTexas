#include "player.h"
#include "plafactory.h"
#include "game.h"


template<typename T>

std::unique_ptr<Player>Plafactory<T>::createPlayer()
{
    return std::make_unique<Player>(game->numberOfPlayers+1,//T.getName()+
                                    std::to_string(game->numberOfPlayers+1),game);
}

