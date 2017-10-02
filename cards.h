#ifndef __CARDS_H__
#define __CARDS_H__
#include<string>
//#include "player.h"
//#include "player.cc"//delete
//class Player;
/*class Card {
    std::string card;
public:
    Card();
    virtual void getCard();
};*/

class SlcCard {
    std::string p1,p2,p3,p4,p5,p6,p7,p8;
    
    std::string SlcStack[24];
    int n;
public:
    SlcCard();
    std::string getCard();
};

class NeedlesCard {
    int money;
    int NeedlesStack[18];
    int m;
public:
    NeedlesCard();
    int getCard();
};
#endif

