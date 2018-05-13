#ifndef DONATE_H
#define DONATE_H
#include <QWidget>
#include "menu.h"

class Donate:public WindowFromMenu
{
public:
    explicit Donate(std::shared_ptr<Menu>menu);

};
#endif // DONATE_H
