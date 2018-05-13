#ifndef DECK_H
#define DECK_H
#include <vector>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <algorithm>
#include <memory>
#include "card.h"
class Deck:public QObject
{
public:

explicit Deck();

/*~Deck();
    Deck(const Deck &dec);
    Deck(Deck &&dec);
    Deck &operator=(const Deck &dec);
    Deck &operator=(Deck &&dec);
*/
std::vector<std::shared_ptr<Card>>undealed;

private:

void shuffle(std::vector<std::shared_ptr<Card>>&list);
};

#endif // DECK_H
