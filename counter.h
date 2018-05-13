#ifndef COUNTER_H
#define COUNTER_H
#include <QGraphicsTextItem>
#include <QFont>

//abstract

class Counter:public QGraphicsTextItem
{
public:

explicit Counter();

virtual int getCounter() const;
virtual void increase();

protected:

int counter;
};
#endif // COUNTER_H
