#ifndef SETTINGS_H
#define SETTINGS_H
#include <QSettings>
#include <memory>
#include "menu.h"

class Settings:public QSettings
{
  public:
    explicit Settings(std::shared_ptr<Menu>menu);

    //audio

    bool soundOn;
    std::unique_ptr<QSlider>volumeSlider;

    //game

    unsigned long roundsWillBePlayed;
    unsigned int numberOfPlayers;
    bool enemiesCooperates;
    unsigned int numberOfCoopenes;
    unsigned int numberOfIndepenes;
    unsigned int cooperatingEnemiesDensity;
    unsigned int defaultCash;
    unsigned long smallBlind;
    unsigned long bigBlind;


};
#endif // SETTINGS_H
