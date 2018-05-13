#include "card.h"

Card::Card(QString court,QString color,int courtPower,int colorPower)
    :court(std::move(court)),color(std::move(color)),courtPower(std::move(courtPower)),colorPower(std::move(colorPower))
{
    //  m_pathName="\":/cards/\""+court+color+".png\"";
}

bool Card::operator >(Card &opCard)
{
    return(this->courtPower > opCard.courtPower);
}

/*
bool Card::operator ==(Card &opCard)
{
    return(this->courtPower == opCard.courtPower);
}

*/

