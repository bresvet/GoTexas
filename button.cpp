#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name,int wt,QGraphicsItem *parent)
    :name(name),m_wt(wt)
{
    // draw the rect
   if(m_wt==1) {setRect(0,0,200,50);}
    if(m_wt==2||m_wt==3) {setRect(0,0,100,25);}

    QBrush brush1;

if(this->m_wt==1)
{
    brush1.setStyle(Qt::SolidPattern);
    brush1.setColor(Qt::darkCyan);
    setBrush(brush1);
}
if(this->m_wt==2||this->m_wt==3)
{
    brush1.setStyle(Qt::SolidPattern);
    brush1.setColor(Qt::darkRed);
    setBrush(brush1);
}

    // draw the text
    text=std::make_unique<QGraphicsTextItem>(name,this);
   if(m_wt==2||m_wt==3) {text->setDefaultTextColor(Qt::white);}
    if(m_wt==1){text->setDefaultTextColor(Qt::black);}
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}





void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
 emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // change color to cyan
QBrush brush2;

if(this->m_wt==1)
{
    brush2.setStyle(Qt::SolidPattern);
    brush2.setColor(Qt::cyan);
}
if(this->m_wt==2||this->m_wt==3)
{
    brush2.setStyle(Qt::SolidPattern);
    brush2.setColor(Qt::darkBlue);
}
    setBrush(brush2);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // change color to dark cyan

    QBrush brush3;

    if(this->m_wt==1)
    {
    brush3.setStyle(Qt::SolidPattern);
    brush3.setColor(Qt::darkCyan);
    }
    if(this->m_wt==2||this->m_wt==3)
    {
    brush3.setStyle(Qt::SolidPattern);
    brush3.setColor(Qt::darkRed);
    }
    setBrush(brush3);
}
