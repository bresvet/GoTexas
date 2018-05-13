#ifndef BET_H
#define BET_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsItem>


class Pot:public QGraphicsTextItem
{
public:
    explicit Pot();
    void increase(int increaseValue);
    int value;
    void decreaseToDefault();
    int getPotValue() const;
};

#endif // BET_H
