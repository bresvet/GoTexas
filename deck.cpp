#include "deck.h"
#include "cstdlib"
#include "random"




Deck::Deck()
{

std::shared_ptr<Card>AceClubs=std::make_shared<Card>("Ace","Clubs",13,4);
undealed. push_back (AceClubs);
AceClubs->setPixmap(QPixmap(":/cards/AceClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

std::shared_ptr<Card>AceDiamonds=std::make_shared<Card>("Ace","Diamonds",13,2);
undealed. push_back (AceDiamonds);
AceDiamonds->setPixmap(QPixmap(":/cards/AceDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

std::shared_ptr<Card>AceHearts=std::make_shared<Card>("Ace","Hearts",13,1);
undealed. push_back (AceHearts);
AceHearts->setPixmap(QPixmap(":/cards/AceHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>AceSpades=std::make_shared<Card>("Ace","Spades",13,3);
    undealed. push_back (AceSpades);
    AceSpades->setPixmap(QPixmap(":/cards/AceSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>KingClubs=std::make_shared<Card>("King","Clubs",12,4);
    undealed. push_back (KingClubs);
    KingClubs->setPixmap(QPixmap(":/cards/KingClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>KingDiamonds=std::make_shared<Card>("King","Diamonds",12,2);
    undealed. push_back (KingDiamonds);
     KingDiamonds->setPixmap(QPixmap(":/cards/KingDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

      std::shared_ptr<Card>KingHearts=std::make_shared<Card>("King","Hearts",12,1);
    undealed. push_back (KingHearts);
     KingHearts->setPixmap(QPixmap(":/cards/KingHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>KingSpades=std::make_shared<Card>("King","Spades",12,3);
    undealed. push_back (KingSpades);
     KingSpades->setPixmap(QPixmap(":/cards/KingSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>QueenClubs=std::make_shared<Card>("Queen","Clubs",11,4);
    undealed. push_back (QueenClubs);
     QueenClubs->setPixmap(QPixmap(":/cards/QueenClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>QueenDiamonds=std::make_shared<Card>("Queen","Diamonds",11,2);
    undealed. push_back (QueenDiamonds);
     QueenDiamonds->setPixmap(QPixmap(":/cards/QueenDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>QueenHearts=std::make_shared<Card>("Queen","Hearts",11,1);
    undealed. push_back (QueenHearts);
     QueenHearts->setPixmap(QPixmap(":/cards/QueenHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>QueenSpades=std::make_shared<Card>("Queen","Spades",11,3);
    undealed. push_back (QueenSpades);
     QueenSpades->setPixmap(QPixmap(":/cards/QueenSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>JackClubs=std::make_shared<Card>("Jack","Clubs",10,4);
    undealed. push_back (JackClubs);
     JackClubs->setPixmap(QPixmap(":/cards/JackClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>JackDiamonds=std::make_shared<Card>("Jack","Diamonds",10,2);
   undealed. push_back (JackDiamonds);
    JackDiamonds->setPixmap(QPixmap(":/cards/JackDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>JackHearts=std::make_shared<Card>("Jack","Hearts",10,1);
    undealed. push_back (JackHearts);
     JackHearts->setPixmap(QPixmap(":/cards/JackHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>JackSpades=std::make_shared<Card>("Jack","Spades",10,3);
    undealed. push_back (JackSpades);
     JackSpades->setPixmap(QPixmap(":/cards/JackSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

      std::shared_ptr<Card>TenClubs=std::make_shared<Card>("Ten","Clubs",9,4);
    undealed. push_back (TenClubs);
     TenClubs->setPixmap(QPixmap(":/cards/TenClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>TenDiamonds=std::make_shared<Card>("Ten","Diamonds",9,2);
    undealed. push_back (TenDiamonds);
     TenDiamonds->setPixmap(QPixmap(":/cards/TenDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>TenHearts=std::make_shared<Card>("Ten","Hearts",9,1);
    undealed. push_back (TenHearts);
     TenHearts->setPixmap(QPixmap(":/cards/TenHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>TenSpades=std::make_shared<Card>("Ten","Spades",9,3);
    undealed. push_back (TenSpades);
     TenSpades->setPixmap(QPixmap(":/cards/TenSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>NineClubs=std::make_shared<Card>("Nine","Clubs",8,4);
    undealed. push_back (NineClubs);
     NineClubs->setPixmap(QPixmap(":/cards/NineClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>NineDiamonds=std::make_shared<Card>("Nine","Diamonds",8,2);
    undealed. push_back (NineDiamonds);
     NineDiamonds->setPixmap(QPixmap(":/cards/NineDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>NineHearts=std::make_shared<Card>("Nine","Hearts",8,1);
    undealed. push_back (NineHearts);
     NineHearts->setPixmap(QPixmap(":/cards/NineHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

      std::shared_ptr<Card>NineSpades=std::make_shared<Card>("Nine","Spades",8,3);
    undealed. push_back (NineSpades);
     NineSpades->setPixmap(QPixmap(":/cards/NineSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>EightClubs=std::make_shared<Card>("Eight","Clubs",7,4);
    undealed. push_back (EightClubs);
     EightClubs->setPixmap(QPixmap(":/cards/EightClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>EightDiamonds=std::make_shared<Card>("Eight","Diamonds",7,2);
    undealed. push_back (EightDiamonds);
    EightDiamonds->setPixmap(QPixmap(":/cards/EightDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>EightHearts=std::make_shared<Card>("Eight","Hearts",7,1);
    undealed. push_back (EightHearts);
     EightHearts->setPixmap(QPixmap(":/cards/EightHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>EightSpades=std::make_shared<Card>("Eight","Spades",7,3);
    undealed. push_back (EightSpades);
     EightSpades->setPixmap(QPixmap(":/cards/EightSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>SevenClubs=std::make_shared<Card>("Seven","Clubs",6,4);
    undealed. push_back (SevenClubs);
     SevenClubs->setPixmap(QPixmap(":/cards/SevenClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>SevenDiamonds=std::make_shared<Card>("Seven","Diamonds",6,2);
    undealed. push_back (SevenDiamonds);
     SevenDiamonds->setPixmap(QPixmap(":/cards/SevenDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

      std::shared_ptr<Card>SevenHearts=std::make_shared<Card>("Seven","Hearts",6,1);
    undealed. push_back (SevenHearts);
    SevenHearts->setPixmap(QPixmap(":/cards/SevenHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>SevenSpades=std::make_shared<Card>("Seven","Spades",6,3);
    undealed. push_back (SevenSpades);
    SevenSpades->setPixmap(QPixmap(":/cards/SevenSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>SixClubs=std::make_shared<Card>("Six","Clubs",5,4);
    undealed. push_back (SixClubs);
    SixClubs->setPixmap(QPixmap(":/cards/SixClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>SixDiamonds=std::make_shared<Card>("Six","Diamonds",5,2);
    undealed. push_back (SixDiamonds);
     SixDiamonds->setPixmap(QPixmap(":/cards/SixDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

      std::shared_ptr<Card>SixHearts=std::make_shared<Card>("Six","Hearts",5,1);
    undealed. push_back (SixHearts);
     SixHearts->setPixmap(QPixmap(":/cards/SixHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

      std::shared_ptr<Card>SixSpades=std::make_shared<Card> ("Six","Spades",5,3);
    undealed. push_back (SixSpades);
    SixSpades->setPixmap(QPixmap(":/cards/SixSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FiveClubs=std::make_shared<Card>("Five","Clubs",4,4);
    undealed. push_back (FiveClubs);
     FiveClubs->setPixmap(QPixmap(":/cards/FiveClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FiveDiamonds=std::make_shared<Card>("Five","Diamonds",4,2);
    undealed. push_back (FiveDiamonds);
     FiveDiamonds->setPixmap(QPixmap(":/cards/FiveDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FiveHearts=std::make_shared<Card>("Five","Hearts",4,1);
    undealed. push_back (FiveHearts);
     FiveHearts->setPixmap(QPixmap(":/cards/FiveHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FiveSpades=std::make_shared<Card>("Five","Spades",4,3);
    undealed. push_back (FiveSpades);
     FiveSpades->setPixmap(QPixmap(":/cards/FiveSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FourClubs=std::make_shared<Card>("Four","Clubs",3,4);
    undealed. push_back (FourClubs);
     FourClubs->setPixmap(QPixmap(":/cards/FourClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FourDiamonds=std::make_shared<Card>("Four","Diamonds",3,2);
    undealed. push_back (FourDiamonds);
     FourDiamonds->setPixmap(QPixmap(":/cards/FourDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FourHearts=std::make_shared<Card>("Four","Hearts",3,1);
    undealed. push_back (FourHearts);
    FourHearts->setPixmap(QPixmap(":/cards/FourHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

     std::shared_ptr<Card>FourSpades=std::make_shared<Card>("Four","Spades",3,3);
    undealed. push_back (FourSpades);
     FourSpades->setPixmap(QPixmap(":/cards/FourSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

      std::shared_ptr<Card>ThreeClubs=std::make_shared<Card>("Three","Clubs",2,4);
    undealed. push_back (ThreeClubs);
     ThreeClubs->setPixmap(QPixmap(":/cards/ThreeClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>ThreeDiamonds=std::make_shared<Card>("Three","Diamonds",2,2);
    undealed. push_back (ThreeDiamonds);
    ThreeDiamonds->setPixmap(QPixmap(":/cards/ThreeDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>ThreeHearts=std::make_shared<Card>("Three","Hearts",2,1);
    undealed. push_back (ThreeHearts);
    ThreeHearts->setPixmap(QPixmap(":/cards/ThreeHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>ThreeSpades=std::make_shared<Card>("Three","Spades",2,3);
    undealed. push_back (ThreeSpades);
    ThreeSpades->setPixmap(QPixmap(":/cards/ThreeSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>TwoClubs=std::make_shared<Card>("Two","Clubs",1,4);
    undealed. push_back (TwoClubs);
    TwoClubs->setPixmap(QPixmap(":/cards/TwoClubs.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>TwoDiamonds=std::make_shared<Card>("Two","Diamonds",1,2);
    undealed. push_back (TwoDiamonds);
    TwoDiamonds->setPixmap(QPixmap(":/cards/TwoDiamonds.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>TwoHearts=std::make_shared<Card>("Two","Hearts",1,1);
    undealed. push_back (TwoHearts);
    TwoHearts->setPixmap(QPixmap(":/cards/TwoHearts.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    std::shared_ptr<Card>TwoSpades=std::make_shared<Card>("Two","Spades",1,3);
    undealed. push_back (TwoSpades);
    TwoSpades->setPixmap(QPixmap(":/cards/TwoSpades.png").scaled(80,112,Qt::KeepAspectRatio,Qt::SmoothTransformation));


     shuffle(undealed);

     //Card *firstAbstractCardItem=new Card("abccourt1","abccolor1",-1);
     //Card *secondAbstractCardItem=new Card("abccourt2","abccolor2",-2);
     //Card *thirdAbstractCardItem=new Card("abccourt3", "abccolor3",-3);

}
/*
Deck::Deck(Deck &&dec)
{
    undealed= (dec.undealed);
}

Deck::~Deck()
{
    qDeleteAll(undealed);
    qDeleteAll(yourHandCards);
    qDeleteAll(enemyHandCards);
}

Deck::Deck(const Deck &dec)
    :undealed(dec.undealed.size()),yourHandCards(dec.yourHandCards.size()),enemyHandCards(dec.enemyHandCards.size())
{
    auto startUn=undealed.begin();
    auto finishUn=undealed.cbegin();
    auto startYo=yourHandCards.begin();
    auto finishYo=yourHandCards.cbegin();
    auto startEn=enemyHandCards.begin();
    auto finishEn=enemyHandCards.cbegin();

}

Deck::Deck(Deck &&dec)
{

}

Deck &&Deck::operator=(const Deck &deck)
{

}

Deck &&Deck::operator=(Deck &&deck)
{

}

*/


void Deck::shuffle(std::vector<std::shared_ptr<Card>>&list)
{
   srand(time(NULL));
   std::random_shuffle(list.begin(),list.end());
}




