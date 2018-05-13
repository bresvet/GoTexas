#include <QApplication>
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<Menu>menu;
    menu.get()->display();

    return a.exec();
}
