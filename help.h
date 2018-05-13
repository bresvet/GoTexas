#ifndef HELP_H
#define HELP_H
#include "menu.h"

class Help:public WindowFromMenu
{
public:
  explicit Help(std::shared_ptr<Menu>menu);

};
#endif // HELP_H
