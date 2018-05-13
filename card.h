 #ifndef CARD_H
#define CARD_H

#include <QGraphicsPixmapItem>
#include <QString>

class Card:public QGraphicsPixmapItem
{
public:

    explicit Card(QString court,QString color,int courtPower,int colorPower);

    short unsigned int courtPower;
    short unsigned int colorPower;

private:
    QString court;
    QString color;
    bool operator >(Card &opCard);
   // bool operator ==(Card &opCard);

};

#endif // CARD_H
