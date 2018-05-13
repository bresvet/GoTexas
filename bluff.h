#ifndef BLUFF_H
#define BLUFF_H
#include "decision.h"

class Bluff:public Decision
{
    explicit Bluff();
    void updateBluffInfo() const;
};

#endif // BLUFF_H
