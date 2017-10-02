#include <string>
#include <cstdlib>
#include "cards.h"
//#include "player.cc"
using namespace std;

//Card
/*Card::Card() {}
void Card::getCard(Player *p) {}
bool getRURC() {}*/


//SLC
// p1. Back 3  (3)
// p2. Back 2  (4)
// p3. Back 1  (4)
// p4. Forward 1  (3)
// p5. Forward 2  (4)
// p6. Forward 3  (4)
// p7. Go to DC Tims Line  (1)
// p8. Advance to Collect OSAP  (1)



SlcCard::SlcCard() {
                   p1 = "Back 3";
                   p2 = "Back 2";
                   p3 = "Back 1";
                   p4 = "Forward 1";
                   p5 = "Forward 2";
                   p6 = "Forward 3";
                   p7 = "Go to DC Tims Line";
                   p8 = "Advance to Collect OSAP";
                   SlcStack[0]=p1;
                   SlcStack[1]=p1;
                   SlcStack[2]=p1;
                   SlcStack[3]=p2;
                   SlcStack[4]=p2;
                   SlcStack[5]=p2;
                   SlcStack[6]=p2;
                   SlcStack[7]=p3;
                   SlcStack[8]=p3;
                   SlcStack[9]=p3;
                   SlcStack[10]=p3;
                   SlcStack[11]=p4;
                   SlcStack[12]=p4;
                   SlcStack[13]=p4;
                   SlcStack[14]=p5;
                   SlcStack[15]=p5;
                   SlcStack[16]=p5;
                   SlcStack[17]=p5;
                   SlcStack[18]=p6;
                   SlcStack[19]=p6;
                   SlcStack[20]=p6;
                   SlcStack[21]=p6;
                   SlcStack[22]=p7;
                   SlcStack[23]=p8;
                   }
string SlcCard::getCard() {
    n = rand()%24;
    return SlcStack[n];
    /*if (SlcStack[n] == p1) {
        cout << "Move back 3!" << endl;
        p->move(-3);
    }
    else if (SlcStack[n] == p2) {
        cout << "Move back 2!" <<endl;
        p->move(-2);
    }
    else if (SlcStack[n] == p3) {
        cout << "Move back 1!" <<endl;
        p->move(-1);
    }
    else if (SlcStack[n] == p4) {
        cout << "Move forward 1!" << endl;
        p->move(1);
    }
    else if (SlcStack[n] == p5) {
        cout << "Move forward 2!" << endl;
        p->move(2);
    }
    else if (SlcStack[n] == p6) {
        cout << "Move forward 3!" << endl;
        p->move(3);
    }
    else if (SlcStack[n] == p7) {
        cout << "Go to DC Tims Line!" << endl;
        p->moveto(dtl);
    }
    else {
        cout << "Advance to Collect OSAP!" << endl;
        p->moveto(co);
    }*/
}
//bool getRURC() { return isRURC; }


//Needles Hall
//a. -200 (1)
//b. -100 (2)
//c. -50 (3)
//d. 25 (6)
//e. 50 (3)
//f. 100 (2)
//g. 200 (1)


NeedlesCard::NeedlesCard() {
                           NeedlesStack[0]=-200;
                           NeedlesStack[1]=-100;
                           NeedlesStack[2]=-100;
                           NeedlesStack[3]=-50;
                           NeedlesStack[4]=-50;
                           NeedlesStack[5]=-50;
                           NeedlesStack[6]=25;
                           NeedlesStack[7]=25;
                           NeedlesStack[8]=25;
                           NeedlesStack[9]=25;
                           NeedlesStack[10]=25;
                           NeedlesStack[11]=25;
                           NeedlesStack[12]=50;
                           NeedlesStack[13]=50;
                           NeedlesStack[14]=50;
                           NeedlesStack[15]=100;
                           NeedlesStack[16]=100;
                           NeedlesStack[17]=200;
                           }
int NeedlesCard::getCard() {
    m = rand()%18;
    return NeedlesStack[m];
    /*if (NeedlesStack[m] > 0) {
        cout << "Congratulations! You win $" << NeedlesStack[m] << "!" << endl;
        p->receiveMoney(NeedlesStack[m]);
    } else {
        cout << "Sorry! You lose $" << NeedlesStack[m] << "!" << endl;
        p->loseMoney(NeedlesStack[m]);
    }*/
}
//bool getRURC() { return isRURC; }


