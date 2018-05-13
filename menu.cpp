#include "menu.h"

void Menu::display()
{
        int bxPos,byPos;

        scene=std::make_unique<QGraphicsScene>();

        mainMenuTitleItem=std::make_unique<QGraphicsPixmapItem>();
        mainMenuTitleItem->setPixmap(QPixmap(":/bcgaoc/mainMenuTitleString(1).jpg"));
        mainMenuTitleItem->setPos(0,0);
        scene->addItem(mainMenuTitleItem.get());


        tournamentButton=std::make_unique<Button>(QString("TOURNAMENT"),1);
        bxPos=(this->width()/2-tournamentButton->boundingRect().width()/2);
        byPos=250;
        tournamentButton->setPos(bxPos,byPos);
       // connect(tournamentButton,SIGNAL(clicked()),this,SLOT
        tournamentButton->setPos(bxPos,byPos);
        scene->addItem(tournamentButton.get());

        playButton=std::make_unique<Button>(QString("PLAY"),1);
        bxPos=(this->width()/2-playButton->boundingRect().width()/2);
        byPos=350;
        playButton->setPos(bxPos,byPos);
      //  connect(playButton.get(),SIGNAL(clicked()),this,SLOT(start()));
        scene->addItem(playButton.get());

        settingsButton=std::make_unique<Button>(QString("SETTINGS"),1);
        bxPos=(this->width()/2-settingsButton->boundingRect().width()/2);
        byPos=450;
        settingsButton->setPos(bxPos,byPos);

        scene->addItem(settingsButton.get());

        aboutButton=std::make_unique<Button>(QString("ABOUT"),1);

        byPos=550;
        aboutButton->setPos(bxPos,byPos);

        scene->addItem(aboutButton.get());

        donateButton=std::make_unique<Button>(QString("DONATE"),1);
        byPos=650;
        donateButton->setPos(bxPos,byPos);

        scene->addItem(donateButton.get());

        helpButton=std::make_unique<Button>(QString("HELP"),1);
        bxPos=(this->width()/2-helpButton->boundingRect().width()/2);
        byPos=750;
        helpButton->setPos(bxPos,byPos);

        scene->addItem(helpButton.get());

        exitButton=std::make_unique<Button>(QString("EXIT"),1);
        bxPos=(this->width()/2-exitButton->boundingRect().width()/2);
        byPos=850;
        exitButton->setPos(bxPos,byPos);
        //connect(exitButton.get(),SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(exitButton.get());
}

