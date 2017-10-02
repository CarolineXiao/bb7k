#include <iostream>
#include <string>
#include <cstdlib>
#include "grid.h"
//#include "player.h"
//#include "cards.cc"
using namespace std;
//class Player;
//Grid
Grid::Grid(string name): name(name) {}
string Grid::getName() { return name; }
/*bool Grid::isProperty() { return true; }
bool Grid::upgradable() { return true; }
bool Grid::getMortgaged() { return true; }
void Grid::setOwner(Player *p) {}
int Grid::getCost() { return 0; }
int Grid::getTuition() { return 0; }
Player *Grid::getOwner() { return 0; }
void Grid::function(Player *p, int code) {}
void Grid::upgrade() {}
void Grid::degrade() {}
int Grid::getLevel() { return 0; }
int Grid::getUpgradePrice() { return 0; }
void Grid::mortgage() {}
void Grid::unmortgage() {}
string Grid::getSubject() {}*/


//Property
Property::Property (string name): Grid(name) {
                   owner=NULL;
                   mortgaged=false;
                   }
bool Property::isProperty() { return true; }
void Property::setCost() {/*
    if (name == "AL") cost = 40;
    else if (name == "ML") cost = 60;
    else if (name == "ECH" || name == "PAS") cost = 100;
    else if (name == "HH") cost = 120;
    else if (name == "RCH" || name == "DWE") cost = 140;
    else if (name == "CPH") cost = 160;
    else if (name == "LHI" || name == "BMH") cost = 180;
    else if (name == "OPT") cost = 200;
    else if (name == "EV1" || name == "EV2") cost = 220;
    else if (name == "EV3") cost = 240;
    else if (name == "PHYS" || name == "B1") cost = 260;
    else if (name == "B2") cost = 280;
    else if (name == "EIT" || name == "ESC") cost = 300;
    else if (name == "C2") cost = 320;
    else if (name == "MC") cost = 350;
    else if (name == "DC") cost = 400;
    else if (name == "MKV" || name == "UWP" || name == "V1") cost = 200;
    else cost = 150;*/
}
int Property::getCost() { return cost; }
Player *Property::getOwner() {
    return owner;
}
void Property::mortgage() { mortgaged = true; }
void Property::unmortgage() { mortgaged = false; }
bool Property::getMortgaged() { return mortgaged; }
void Property::setOwner(Player *p){ owner=p; }


//ABuilding
ABuilding::ABuilding (string name, string subject, int cost, int improvementCost): Property(name){
                     this->subject=subject;
                     this->cost=cost;
                     this->improvementCost=improvementCost;
                     level=0;
                     }       
void ABuilding::setTuition(int lv0, int lv1, int lv2, int lv3, int lv4, int lv5){
    tuitions[0] = lv0;
    tuitions[1] = lv1;
    tuitions[2] = lv2;
    tuitions[3] = lv3;
    tuitions[4] = lv4;
    tuitions[5] = lv5;
}
void ABuilding::upgrade() {
    level++;
}
void ABuilding::degrade() {
    level--;
}
int ABuilding::getTuition() {
    return tuitions[level];
}
string ABuilding::getSubject() {
    return subject;
}
bool ABuilding::upgradable() {
    if (level == 5) return false;
    else return true;
}
int ABuilding::getLevel() {
    return level;
}
void ABuilding::setLevel(int x) {
    level=x;
}
int ABuilding::getUpgradePrice() { return improvementCost; }

bool ABuilding::isResidence(){return false;}

bool ABuilding::isGym(){return false;}

void ABuilding::clear(){level=0; owner=0; mortgaged=false;}

//Residence
Residence::Residence(string name): Property(name) {cost=200;}
bool Residence::isResidence() { return true; }
bool Residence::isGym(){return false;}
int Residence::getLevel() { return 0; }
int Residence::getTuition() {
    int n = owner->getNumResidence();
    if (n == 1) return 25;
    else if (n == 2) return 50;
    else if (n == 3) return 100;
    else return 200;
}
bool Residence::upgradable() { return false; }

//Gym
Gym::Gym(string name): Property(name) {cost=150;}
bool Gym::isResidence(){return false;}
bool Gym::isGym() { return true; }
int Gym::getLevel() { return 0; }
int Gym::getTuition() {
    int sum = 0;
    int x = rand()%6+1;
    sum += x;
    x = rand()%6+1;
    sum += x;
    int n = owner->getNumGym();
    if (n == 1) return 4 * sum;
    else return 10 * sum;
}
bool Gym::upgradable() { return false; }

//NonProperty
NonProperty::NonProperty(string name): Grid(name) {}
bool NonProperty::isProperty() { return false; }
bool NonProperty::upgradable() { return false; }
void NonProperty::function(Player *p, int rurc) {
    int n = 0;
    int i;
    string s;
    if (name == "COLLECT OSAP") {
       cout<<"Player "<<p->getName()<<" arrives at COLLECT OSAP and collects $400!"<<endl;
       p->receiveMoney(400);
       }
    else if (name == "SLC" ) {
         n = rand()%100;
        if ( rurc != 0 && n == 0) {
            cout << "Congratulations! You receive a winning Roll Up the Rim cup!" << endl;
            p->setMove(300);
            p->addRURC();
            return;
        }
        SlcCard *slccard=new SlcCard();
        s=slccard->getCard();
        cout<<"The result is '"<<s<<"'!"<<endl;
        for (i=1;i<300000000;i++);
        if (s=="Back 3") p->setMove(-3);
        if (s=="Back 2") p->setMove(-2);
        if (s=="Back 1") p->setMove(-1);
        if (s=="Forward 1") p->setMove(1);
        if (s=="Forward 2") p->setMove(2);
        if (s=="Forward 3") p->setMove(3);
        if (s=="Go to DC Tims Line") p->setMove(100);
        if (s=="Advance to Collect OSAP") p->setMove(200);
        delete slccard;
    }
    else if (name == "TUITION") {
        string choice;
        cout << "Please choose: 1 for paying $300, 2 for paying 10% of your total worth:";
        while (cin >> choice) {
            if (choice == "1") {
                p->setOweMoney(300);
                break;
            }
            else if (choice == "2") {
                int worth = p->getAsset()*0.1;//p->controller->calcAsset(this);
                p->setOweMoney(worth);
                break;
            }
            else {
                cout << "Invalid input. Please choose from 1 and 2." << endl;
            }
        }
    }
    else if (name == "NEEDLES HALL") {
        n = rand()%100;
        if ( rurc != 0 && n == 0) {
            cout << "Congratulations! You receive a winning Roll Up the Rim cup!" << endl;
            p->setMove(300);
            p->addRURC();
            return;
        }
        NeedlesCard *needlescard=new NeedlesCard();
        int x=needlescard->getCard();
        if (x>0) {
           cout << "Congratulations! You win $" << x << "!" << endl;
           p->receiveMoney(x);
           }
        else {
             x=0-x;
             cout << "Sorry! You lose $" << x << "!" << endl;
             p->setOweMoney(x);
             }
        delete needlescard;
    }
    else if (name == "DC Tims Line") {}
    else if (name == "Goose Nesting") {}
    else if (name == "GO TO TIMS") {
        p->setMove(100);
    }
    else {
        p->setOweMoney(150);
    }
}

Grid *board[40];
/*
void initialboard (board) {
    Grid *co = new NonProperty("COLLECT OSAP", NULL, 0);
    Grid *cf = new NonProperty("COOP FEE", NULL, 0);
    Grid *nh = new NonProperty("NEEDLES HALL", NULL, 0);
    Grid *rev = new Residence("REV", NULL, 0);
    Grid *slc = new NonProperty("SLC", NULL, 0);
    Grid *gtt = new NonProperty("GO TO TIMS", NULL, 0);
    Grid *cif = new Gym("CIF", NULL, 0);
    Grid *v1 = new Residence("V1", NULL, 0);
    Grid *gn = new NonProperty("Goose Nesting", NULL, 0);
    Grid *uwp = new Residence("UWP", NULL, 0);
    Grid *pac = new Gym("PAC", NULL, 0);
    Grid *dtl = new NonProperty("DC Tims Line", NULL, 0);
    Grid *mkv = new Residence("MKV", NULL, 0);
    Grid *t = new NonProperty("TUITION", NULL, 0);
    
    board[0] = co;
    board[39] = dc;
    board[38] = cf;
    board[37] = mc;
    board[36] = nh;
    board[35] = rev;
    board[34] = c2;
    board[33] = slc;
    board[32] = esc;
    board[31] = eit;
    board[30] = gtt;
    board[29] = b2;
    board[28] = cif;
    board[27] = b1;
    board[26] = phys;
    board[25] = v1;
    board[24] = ev3;
    board[23] = ev2;
    board[22] = nh;
    board[21] = ev1;
    board[20] = gn;
    board[19] = opt;
    board[18] = bmh;
    board[17] = slc;
    board[16] = lhi;
    board[15] = uwp;
    board[14] = cph;
    board[13] = dwe;
    board[12] = pac;
    board[11] = rch;
    board[10] = dtl;
    board[9] = hh;
    board[8] = pas;
    board[7] = nh;
    board[6] = ech;
    board[5] = mkv;
    board[4] = t;
    board[3] = ml;
    board[2] = slc;
    board[1] = al;
}*/

