#ifndef ABOUT_H
#define ABOUT_H
#include <QWindow>
#include <QWidget>
#include <QTextObject>
#include <QTextFrame>
#include <QFile>
#include <QFileInfo>
#include "menu.h"

class About:public QWindow
{
    Q_OBJECT
    explicit About(std::shared_ptr<Menu>menu);
    std::allocator<typename>;

};
#endif // ABOUT_H
