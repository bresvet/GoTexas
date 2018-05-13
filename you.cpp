#include "you.h"

//std::shared_ptr<You>You::you=nullptr;

You *You::you=0;
/*
std::shared_ptr<You>You::getYou()
{
    if(!you)
    {
         you=new You;
    }
    return you;
}
*/
You *You::getYou()
{
    if(you==0)
    {
         you=new You();
    }
    return you;
}

