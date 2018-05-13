#ifndef CASH_H
#define CASH_H
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include "game.h"



class Cash:public QGraphicsTextItem
{
public:

   Cash(QGraphicsItem *parent=0);
   void increase(int upValue);
   void decrease(int downValue);





 //static int value;
int value;

// static QString strvalue;

   const int defaultValue=1000;

};

#endif // CASH_H
