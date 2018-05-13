#ifndef BUTTON_H
#define BUTTON_H

#include <QString>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <memory>
#include <QObject>

class Button:public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Button(QString name,int wt,QGraphicsItem *parent=NULL);

    std::unique_ptr<QGraphicsTextItem>text;
    QString name;
    short unsigned int m_wt;

    //wt-which type (1-simple button,here main menu button,2-auction button for bet or raise actions,3-auction button
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:

    virtual void clicked();


};

#endif // BUTTON_H
