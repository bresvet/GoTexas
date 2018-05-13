#ifndef MENU_H
#define MENU_H
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "button.h"

#include <memory>

class Menu:public QGraphicsView,public std::enable_shared_from_this<Menu>
{
    Q_OBJECT
public:

   std::shared_ptr<Menu>menu;
   void display();

public slots:

   void start();
   void close()const;
   void openSettings() const;
   void openAbout() const;
   void openDonate() const;
   void openHelp() const;

private:

   explicit Menu();

   std::unique_ptr<QGraphicsPixmapItem>mainMenuTitleItem;

    std::unique_ptr<QGraphicsScene>scene;

   std::unique_ptr<Button>tournamentButton;
   std::unique_ptr<Button>playButton;
   std::unique_ptr<Button>settingsButton;
   std::unique_ptr<Button>aboutButton;
   std::unique_ptr<Button>donateButton;
   std::unique_ptr<Button>helpButton;
   std::unique_ptr<Button>exitButton;
};

#endif // MENU_H
