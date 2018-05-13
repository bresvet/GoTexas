#ifndef YOU_H
#define YOU_H
#include "player.h"
class You:public Player
{
public:

   static You *getYou();
    // static std::shared_ptr<You> getYou();
    You(You const&)=delete;
    You &operator=(You const&)=delete;

private:

   // static std::shared_ptr<You>you;
    static You *you;
    You();
    void leaveTable() const;
    void surrenderControlToBot() const;
};
#endif // YOU_H
