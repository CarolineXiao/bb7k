#include<string>
#include<fstream>
#include<iostream>
#include <cstdlib>
#include <iomanip>
#include "controller.h"
using namespace std;
void Controller::switchTest(){
     if (testMode) {
                   cout<<"Test mode locked!"<<endl;
                   testMode=false;
                   }
     else {
          cout<<"Test mode unlocked!"<<endl;
          testMode=true;
          }
     }
void Controller::sleep(){
     int i;
     for (i=1;i<300000000;i++);
     }

int Controller::searchForPlayer(string name){
    int i;
    for (i=0;i<numPlayer;i++)
        if (playerList[i]->getName()==name) return i;
    return -1;
    }

int Controller::searchForProperty(string name){
    int i;
    for (i=0;i<40;i++)
        if (board[i]->getName()==name) return i;
    return -1;
    }
    
int Controller::stringToNum(string s){
    int x=0;
    int len=s.length();
    int i;
    for (i=0;i<len;i++)
        x=x*10+s[i]-48;
    return x;
    }
    
bool Controller::isNum(string s){
     int i;
     int len=s.length();
     for (i=0;i<len;i++)
         if (s[i]<'0' || s[i]>'9') return false;
     return true;
     }
     
Controller::Controller(){
                         int i;
                         for (i=0;i<40;i++) board[i]=NULL;
                         for (i=0;i<8;i++) playerList[i]=NULL;
                         testMode=false;
                         }

Controller::~Controller(){
                          int i;
                          for (i=0;i<40;i++) delete board[i];
                          for (i=0;i<numPlayer;i++) delete playerList[i];
                          }

void Controller::initialize(){
     ABuilding *al=new ABuilding("AL","Arts1",40,50);
     al->setTuition(2,10,30,90,160,250);
     ABuilding *ml=new ABuilding("ML","Arts1",60,50);
     ml->setTuition(4,20,60,180,320,450);
     ABuilding *ech=new ABuilding("ECH","Arts2",100,50);
     ech->setTuition(6,30,90,270,400,550);
     ABuilding *pas=new ABuilding("PAS","Arts2",100,50);
     pas->setTuition(6,30,90,270,400,550);
     ABuilding *hh=new ABuilding("HH","Arts2",120,50);
     hh->setTuition(8,40,100,300,450,600);
     ABuilding *rch=new ABuilding("RCH","Eng",140,100);
     rch->setTuition(10,50,150,450,625,750);
     ABuilding *dwe=new ABuilding("DWE","Eng",140,100);
     dwe->setTuition(10,50,150,450,625,750);
     ABuilding *cph=new ABuilding("CPH","Eng",160,100);
     cph->setTuition(12,60,180,500,700,900);
     ABuilding *lhi=new ABuilding("LHI","Health",180,100);
     lhi->setTuition(14,70,200,550,750,950);
     ABuilding *bmh=new ABuilding("BMH","Health",180,100);
     bmh->setTuition(14,70,200,550,750,950);
     ABuilding *opt=new ABuilding("OPT","Health",200,100);
     opt->setTuition(16,80,220,600,800,1000);
     ABuilding *ev1=new ABuilding("EV1","Env",220,150);
     ev1->setTuition(18,90,250,700,875,1050);
     ABuilding *ev2=new ABuilding("EV2","Env",220,150);
     ev2->setTuition(18,90,250,700,875,1050);
     ABuilding *ev3=new ABuilding("EV3","Env",240,150);
     ev3->setTuition(20,100,300,750,925,1100);
     ABuilding *phys=new ABuilding("PHYS","Sci1",260,150);
     phys->setTuition(22,110,330,800,975,1150);
     ABuilding *b1=new ABuilding("B1","Sci1",260,150);
     b1->setTuition(22,110,330,800,975,1150);
     ABuilding *b2=new ABuilding("B2","Sci1",280,150);
     b2->setTuition(24,120,360,850,1025,1200);
     ABuilding *eit=new ABuilding("EIT","Sci2",300,200);
     eit->setTuition(26,130,390,900,1100,1275);
     ABuilding *esc=new ABuilding("ESC","Sci2",300,200);
     esc->setTuition(26,130,390,900,1100,1275);
     ABuilding *c2=new ABuilding("C2","Sci2",320,200);
     c2->setTuition(28,150,460,1000,1200,1400);
     ABuilding *mc=new ABuilding("MC","Math",350,200);
     mc->setTuition(35,175,500,1100,1300,1500);
     ABuilding *dc=new ABuilding("DC","Math",400,200);
     dc->setTuition(50,200,600,1400,1700,2000);
     NonProperty *co = new NonProperty("COLLECT OSAP");
     NonProperty *cf = new NonProperty("COOP FEE");
     NonProperty *nh1 = new NonProperty("NEEDLES HALL");
     NonProperty *nh2 = new NonProperty("NEEDLES HALL");
     NonProperty *nh3 = new NonProperty("NEEDLES HALL");
     Residence *rev = new Residence("REV");
     NonProperty *slc1 = new NonProperty("SLC");
     NonProperty *slc2 = new NonProperty("SLC");
     NonProperty *slc3 = new NonProperty("SLC");
     NonProperty *gtt = new NonProperty("GO TO TIMS");
     Gym *cif = new Gym("CIF");
     Residence *v1 = new Residence("V1");
     NonProperty *gn = new NonProperty("Goose Nesting");
     Residence *uwp = new Residence("UWP");
     Gym *pac = new Gym("PAC");
     NonProperty *dtl = new NonProperty("DC Tims Line");
     Residence *mkv = new Residence("MKV");
     NonProperty *t = new NonProperty("TUITION");
     board[0] = co;
     board[39] = dc;
     board[38] = cf;
     board[37] = mc;
     board[36] = nh3;
     board[35] = rev;
     board[34] = c2;
     board[33] = slc3;
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
     board[22] = nh2;
     board[21] = ev1;
     board[20] = gn;
     board[19] = opt;
     board[18] = bmh;
     board[17] = slc2;
     board[16] = lhi;
     board[15] = uwp;
     board[14] = cph;
     board[13] = dwe;
     board[12] = pac;
     board[11] = rch;
     board[10] = dtl;
     board[9] = hh;
     board[8] = pas;
     board[7] = nh1;
     board[6] = ech;
     board[5] = mkv;
     board[4] = t;
     board[3] = ml;
     board[2] = slc1;
     board[1] = al;
     }
void Controller::start(){
     string nump;
     int temp;
     srand(time(0));
     firstRoundOfLoad=false;
     while (1){
           cout<<"Please input the number of players(2~6):";
           cin>>nump;
           if (!isNum(nump)) {
                             cout<<"Invalid input!  You should enter a number between 2 and 6!"<<endl;
                             continue;
                             }
           temp=stringToNum(nump);
           if (temp<2 || temp>6) {
                                 cout<<"Invalid input!  You should enter a number between 2 and 6!"<<endl;
                                 continue;
                                 }
           break;
           }
     numPlayer=temp;
     numRURC=4;
     int i,j;
     string playerName[8] = {"Goose", "GRTBus", "TimHortonsDoughnut", "Professor", "Student", "Money", "Laptop", "Pinktie"};
     char playerChar[8] = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
     cout<<"Here are several choices for you.  You guys can choose one of the name and char from the following table."<<endl;
     bool choosed[8];
     string choice;
     for (i=0;i<8;i++) choosed[i]=false;
     for (i=0;i<numPlayer;i++){
         while (1){
               for (j=0;j<8;j++){
                   cout<<"No."<<j<<", Char: "<<playerChar[j]<<" Name: "<<playerName[j]<<endl;
                   }
               cout<<"Listen, Player "<<i<<"! Your turn to choose!  Please enter 0~7:";
               cin>>choice;
               if (!isNum(choice)) {
                                   cout<<"Invalid input!  You should enter a number between 0 and 7!"<<endl;
                                   continue;
                                   }
               temp=stringToNum(choice);
               if (temp<0 || temp>7) {
                                     cout<<"Invalid input!  You should enter a number between 0 and 7!"<<endl;
                                     continue;
                                     }
               if (choosed[temp]) {
                                  cout<<"No."<<temp<<" has already been choosed.  Try another one!"<<endl;
                                  continue;
                                  }
               break;
               }
         playerList[i]=new Player(playerName[temp],playerChar[temp]);
         playerList[i]->setPosition(0);
         playerList[i]->moveto(board[0]);
         choosed[temp]=true;
         }
     display();
     }

void Controller::askForTrade(Player *p1, Player *p2, int money, Grid *g){
     cout<<"Listen, "<<p2->getName()<<"!  Player"<<p1->getName();
     cout<<" wants to use $"<<money<<" to exchange for your "<<g->getName()<<"!"<<endl;
     cout<<"Do you agree?  Please input 'yes' or 'no':"<<endl;
     string s;
     while (1){
           cin>>s;
           if (s!="yes" && s!="no") cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
           if (s=="yes" || s=="no") break;
           }
     if (s=="yes"){
        cout<<"Deal!"<<endl;
        p2->receiveMoney(money);
        p1->loseMoney(money);
        g->setOwner(p1);
        }
     if (s=="no"){
        cout<<p2->getName()<<" disagrees because "<<p2->getName()<<" thinks "<<p1->getName()<<" is so mean!"<<endl;
        }
     }
     
void Controller::askForTrade(Player *p1, Player *p2, Grid *g, int money){
     cout<<"Listen, "<<p2->getName()<<"!  Player"<<p1->getName();
     cout<<" wants to use "<<g->getName()<<" to exchange for your $"<<money<<"!"<<endl;
     cout<<"Do you agree?  Please input 'yes' or 'no':"<<endl;
     string s;
     while (1){
           cin>>s;
           if (s!="yes" && s!="no") cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
           if (s=="yes" || s=="no") break;
           }
     if (s=="yes"){
        cout<<"Deal!"<<endl;
        p1->receiveMoney(money);
        p2->loseMoney(money);
        g->setOwner(p2);
        }
     if (s=="no"){
        cout<<p2->getName()<<" disagrees because "<<p2->getName()<<" thinks "<<p1->getName()<<" is so mean!"<<endl;
        }
     }

void Controller::askForTrade(Player *p1, Player *p2, Grid *g1, Grid *g2){
     cout<<"Listen, "<<p2->getName()<<"!  Player"<<p1->getName();
     cout<<" wants to use "<<g1->getName()<<" to exchange for your "<<g2->getName()<<"!"<<endl;
     cout<<"Do you agree? (please input 'yes' or 'no)"<<endl;
     string s;
     while (1){
           cin>>s;
           if (s!="yes" && s!="no") cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
           if (s=="yes" || s=="no") break;
           }
     if (s=="yes"){
        cout<<"Deal!"<<endl;
        g1->setOwner(p2);
        g2->setOwner(p1);
        }
     if (s=="no"){
        cout<<p2->getName()<<" disagrees because "<<p2->getName()<<" thinks "<<p1->getName()<<" is so mean!"<<endl;
        }
     }

void Controller::auction(Grid *t){
     cout<<"This is the auction of the property "<<t->getName()<<endl;
     bool inAuction[numPlayer];
     int i,j,count;
     int currentPrice=t->getCost();
     string s;
     string p;
     int newp;
     for (i=0;i<numPlayer;i++){
         if (playerList[i]->isAlive()) {
            while (1){
                  cout<<"Listen, "<<playerList[i]->getName()<<"!  Do you want to be in the auction?  Please input 'yes' or 'no':";
                  cin>>s;
                  if (s=="yes" || s=="no") break;
                  cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
                  }
            if (s=="yes") inAuction[i]=true;
            else inAuction[i]=false;
            }
         else inAuction[i]=false;
         }
     i=0;
     while (1) {
         count=0;  
         for (j=0;j<numPlayer;j++) {
             if (inAuction[j]) count++;
             }  
         if (count==1) {
            for (j=0;j<numPlayer;j++){
                if (inAuction[j]){
                   cout<<"Now it is the end of the auction for property "<<t->getName()<<endl;
                   cout<<"Player "<<playerList[j]->getName()<<" spends $"<<currentPrice<<" to get the property"<<endl;
                   t->setOwner(playerList[j]);
                   playerList[j]->loseMoney(currentPrice);
                   return; 
                   }
                }
            }
         if (inAuction[i] && playerList[i]->isAlive()){
            cout<<"Listen, "<<playerList[i]->getName()<<":"<<endl;
            cout<<"The current price is "<<currentPrice<<"."<<endl;
            if (playerList[i]->getCash()<=currentPrice) {
               cout<<"You do not have enough money to raise!  So you must quit!"<<endl;
               inAuction[i]=false;
               i++;
               continue;
               }
            while (1){
                  cout<<"Do you want to raise or quit?  Please input 'raise' or 'quit':";
                  cin>>s;
                  if (s=="raise" || s=="quit") break;
                  cout<<"Invalid input!  You should enter 'raise' or 'quit'!"<<endl;
                  }
            if (s=="raise") {
               while (1) {
                     cout<<"Please input the price you want to purchase:";
                     cin>>p;
                     if (!isNum(p)) {
                        cout<<"Invalid input!  You should enter a number!";
                        continue;
                        }
                     newp=stringToNum(p);
                     if (newp<=currentPrice) {
                        cout<<"Your price must be higher than the current price!"<<endl;
                        continue;
                        }
                     if (newp>playerList[i]->getCash()) {
                        cout<<"You don't have enough money!"<<endl;
                        continue;
                        }
                     currentPrice=newp;
                     break;
                     }
               }// end of if raise
            if (s=="quit") {
               cout<<"Player "<<playerList[i]->getName()<<" quits the auction"<<endl;
               inAuction[i]=false;
               }
            }// valid auction player;
            i++;
            if (i==numPlayer) i=0;
         }// while 1
     }

bool Controller::bankrupt(Player *p){
     int i;
     if (p->getCash()>=p->getOweMoney()){
        cout<<"You cannot declair bankrupcy if you are able to give the owed moneny back!"<<endl;
        return false;
        }
     cout<<"Player "<<p->getName()<<" declares bankrupt!"<<endl;
     p->bankrupt();
     if (p->getOwePlayer()==NULL){
     //cout<<"All of Player "<<p->getName()<<"'s properties belong to "<<p->getOwePlayer()->getName()<<"!"<<endl;
     //p->getOwePlayer->receiveMoney(p->getCash());
     for (i=0;i<40;i++){
         if (board[i]->isProperty()){
            if (board[i]->getOwner()==NULL) continue;
            if (board[i]->getOwner()->getName()==p->getName()){
               board[i]->clear();
               auction(board[i]);
               }
            }
         }
     }
     else {
          cout<<"All of Player "<<p->getName()<<"'s properties belong to"<<p->getOwePlayer()->getName()<<"!"<<endl;
          p->getOwePlayer()->receiveMoney(p->getCash());
          for (i=0;i<40;i++){
              if (board[i]->isProperty()){
                 if (board[i]->getOwner()==NULL) continue;
                 if (board[i]->getOwner()->getName()==p->getName()){
                    board[i]->setOwner(p->getOwePlayer());
                    }
                 }
              }
          }
     return true;
     }

void Controller::play(){
     int i;
     if (firstRoundOfLoad) {
        i=startPlayer;
        playerList[i]->setOwePlayer(NULL);
        playerList[i]->setOweMoney(0);
        if (startOweMoney!=0) {
           if (startOwePlayer!="BANK")
              playerList[i]->setOwePlayer(playerList[searchForPlayer(startOwePlayer)]);
           playerList[i]->setOweMoney(startOweMoney);
           } 
        }
     else i=0;
     int temp,tp1,tp2,lv;
     int money;
     int x1,x2;
     string s,name,give,receive,property,bs,yn;
     bool valid;
     while (1){
           if (i==numPlayer) i=0;
           if (!playerList[i]->isAlive()){
              i++;
              continue;
              }
           cout<<"Player "<<playerList[i]->getName()<<"'s turn!"<<endl;
           int ta=calAssets(playerList[i]);
           playerList[i]->setAsset(ta);
           if (firstRoundOfLoad){
              firstRoundOfLoad=false;
              }
           else {
                playerList[i]->setOwePlayer(NULL);
                playerList[i]->setOweMoney(0);
                canRoll=true;
                rollTime=0;
                }
           if (playerList[i]->isInTim()) {
              cout<<"Player "<<playerList[i]->getName()<<" is currently in DC Tims line!"<<endl;
              playerList[i]->addTimRound();
              cout<<"This is round "<<playerList[i]->getTimRound()<<" for "<<playerList[i]->getName()<<" to be in DC Tims Line!"<<endl;
              if (playerList[i]->getTimRound()==3){
                 cout<<"This is the third round in Tim and you have to move out!"<<endl;
                 }
              if (playerList[i]->getRURC()>0) {
                 cout<<"You currently have "<<playerList[i]->getRURC()<<" Roll Up the Rim Cup!"<<endl;
                 while (1) {
                       cout<<"Do you want to use one to get rid of the DC Tims Line?  Please input 'yes' or 'no':";
                       cin>>yn;
                       if (yn=="yes" || yn=="no") break;
                       cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
                       }
                 if (yn=="yes") {
                    cout<<"Player "<<playerList[i]->getName()<<" is now out of DC Tims Line!"<<endl;
                    playerList[i]->decRURC();
                    playerList[i]->clnTimRound();
                    playerList[i]->outOfTim();
                    numRURC++;
                    }
                 }
              if (playerList[i]->isInTim()) {
                 if (playerList[i]->getTimRound()==3) {
                    cout<<"It is round three, and you have to spend $50 to get rid of the DC Tims Line if you do not use Roll Up the Rim Cup!"<<endl;
                    yn="yes";
                    }
                 else
                 while (1) {
                       cout<<"Do you want to spend $50 to get rid of the DC Tims Line?  Please input 'yes' or 'no':";
                       cin>>yn;
                       if (yn=="yes" || yn=="no") break;
                       cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
                       }
                 if (yn=="yes") {
                    cout<<"Player "<<playerList[i]->getName()<<" is now out of DC Tims Line!"<<endl;
                    cout<<"You need to pay $50 to BANK at the end of your turn or before rolling the next time!"<<endl;
                    playerList[i]->setOweMoney(50);
                    playerList[i]->clnTimRound();
                    playerList[i]->outOfTim();
                    }
                 }
              }
           while (1){
                 cout<<"Please input command:";
                 valid=false;
                 cin>>s;
                 if (s=="-testing") {
                                    valid=true;
                                    switchTest();
                                    }
                 if (s=="next"){
                    valid=true;
                    display();
                    if (canRoll) { 
                       cout<<"You cannot pass this turn if you are eligible to roll!"<<endl;
                       continue;
                       }
                    if (playerList[i]->getOweMoney()==0){
                       cout<<"End of "<<playerList[i]->getName()<<"'s turn!"<<endl;
                       i++;
                       break;
                       }
                    else {
                         cout<<"You still owe ";
                         if (playerList[i]->getOwePlayer()==NULL) cout<<"BANK";
                         else cout<<playerList[i]->getOwePlayer()->getName();
                         cout<<" $"<<playerList[i]->getOweMoney()<<"!"<<endl;
                         if (playerList[i]->getCash()<playerList[i]->getOweMoney()){
                            cout<<"You don't have enough cash to give back!  Try to trade or mortgage to get more cash!"<<endl;
                            } 
                         else {
                              while (1){
                                    cout<<"Do you want to give the money back right now?  Please input 'yes' or 'no':";
                                    cin>>yn;
                                    if (yn=="yes" || yn=="no") break;
                                    cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
                                    }
                              if (yn=="yes") {
                                             playerList[i]->loseMoney(playerList[i]->getOweMoney());
                                             if (playerList[i]->getOwePlayer()!=NULL)
                                                playerList[i]->getOwePlayer()->receiveMoney(playerList[i]->getOweMoney());
                                             cout<<"End of "<<playerList[i]->getName()<<"'s turn!"<<endl;
                                             i++;
                                             break;
                                             }
                              }
                         }
                    display();
                    }// if next
                 if (s=="roll"){
                    valid=true;
                    if (!canRoll) {
                       cout<<"You cannot roll dice again in this round!"<<endl;
                       continue;
                       }
                    diydice=false;
                    if (testMode) {
                       if (cin.peek()!='\n'){
                          diydice=true;
                          string s1,s2;
                          cin>>s1;
                          cin>>s2;
                          if ((!isNum(s1)) || (!isNum(s2))) {
                             cout<<"Invalid input!  You should enter two numbers between 0~6!"<<endl;
                             continue;
                             }
                          x1=stringToNum(s1);
                          x2=stringToNum(s2);
                          if (!(x1>=0 && x1<=6 && x2>=0 && x2<=6)) {
                             cout<<"Invalid input!  You should enter two numbers between 0~6!"<<endl;
                             continue;
                             }
                          }
                       }
                    if (playerList[i]->getOweMoney()==0){
                       rollTime++;
                       if (diydice) canRoll=rollDice(playerList[i],rollTime,x1,x2);
                       else canRoll=rollDice(playerList[i],rollTime);
                       //display();
                       }
                    else {
                         cout<<"You still owe ";
                         if (playerList[i]->getOwePlayer()==NULL) cout<<"BANK";
                         else cout<<playerList[i]->getOwePlayer()->getName();
                         cout<<" $"<<playerList[i]->getOweMoney()<<"!"<<endl;
                         if (playerList[i]->getCash()<playerList[i]->getOweMoney()){
                            cout<<"You don't have enough cash to give back!  Try to trade or mortgage to get more cash!"<<endl;
                            } 
                         else {
                              while (1){
                                    cout<<"Do you want to give the money back right now?  Please input 'yes' or 'no':";
                                    cin>>yn;
                                    if (yn=="yes" || yn=="no") break;
                                    cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
                                    }
                              if (yn=="yes") {
                                             playerList[i]->loseMoney(playerList[i]->getOweMoney());
                                             if (playerList[i]->getOwePlayer()!=NULL)
                                                playerList[i]->getOwePlayer()->receiveMoney(playerList[i]->getOweMoney());
                                             playerList[i]->setOwePlayer(NULL);
                                             playerList[i]->setOweMoney(0);
                                             rollTime++;
                                             if (diydice) canRoll=rollDice(playerList[i],rollTime,x1,x2);
                                             else canRoll=rollDice(playerList[i],rollTime);
                                             //display();
                                             }
                              }
                         }
                         //display();
                    }//if roll
                 if (s=="trade"){
                    valid=true;
                    display();
                    cin>>name;
                    cin>>give;
                    cin>>receive;
                    if (name==playerList[i]->getName()) {
                       cout<<"You want to offer a trade to yourself? Lol!  Aren't you ridiculous!"<<endl;
                       continue;
                       }
                    temp=searchForPlayer(name);
                    if (temp==-1){
                       cout<<"Invalid input!  No such a player called "<<name<<"!"<<endl;
                       continue;
                       }
                    if (isNum(give) && isNum(receive)){
                       cout<<"Invalid input!  Does not make sense to give money in return for money!"<<endl;
                       continue;
                       }
                    if (isNum(give)){
                       money=stringToNum(give);
                       tp1=searchForProperty(receive);
                       if (money>playerList[i]->getCash()){
			  cout<<"You don't have enough cash!"<<endl;
                          continue;
			  }
                       if (tp1==-1) {
                                    cout<<"Invalid input!  No such a property called "<<receive<<"!"<<endl;
                                    continue;
                                    }
                       if (board[tp1]->getOwner()==NULL){
                                                         cout<<"Invalid input!  Property "<<receive<<" is unoccupied!"<<endl;
                                                         continue;
                                                         }
                       if (board[tp1]->getOwner()->getName()!=playerList[temp]->getName()){
                          cout<<"Invalid input!  Property "<<receive<<" does not belong to "<<playerList[temp]->getName()<<"!"<<endl;
                          continue;
                          }
                       askForTrade(playerList[i],playerList[temp],money,board[tp1]);
                       continue;
                       }
                    if (isNum(receive)){
                       money=stringToNum(receive);
                       tp1=searchForProperty(give);
		       if (money>playerList[temp]->getCash()){
			  cout<<"Player "<<playerList[temp]->getName()<<" does not have enough cash!"<<endl;
			  continue;
			  }	
                       if (tp1==-1) {
                                    cout<<"Invalid input!  No such a property called "<<give<<"!"<<endl;
                                    continue;
                                    }
                       if (board[tp1]->getOwner()==NULL){
                                                         cout<<"Invalid input!  Property "<<give<<" is unoccupied!"<<endl;
                                                         continue;
                                                         }
                       if (board[tp1]->getOwner()->getName()!=playerList[i]->getName()){
                          cout<<"Invalid input!  Property "<<receive<<" does not belong to you!"<<endl;
                          continue;
                          }
                       askForTrade(playerList[i],playerList[temp],board[tp1],money);
                       continue;
                       }
                    tp1=searchForProperty(give);
                    tp2=searchForProperty(receive);
                    if (tp1==-1) {
                                 cout<<"Invalid input!  No such a property called "<<give<<"!"<<endl;
                                 continue;
                                 }
                    if (board[tp1]->getOwner()==NULL){
                                                      cout<<"Invalid input!  Property "<<give<<" is unoccupied!"<<endl;
                                                      continue;
                                                      }
                    if (board[tp1]->getOwner()->getName()!=playerList[i]->getName()){
                       cout<<"Invalid input!  Property "<<give<<" does not belong to you!"<<endl;
                       continue;
                       }
                    if (tp2==-1) {
                                 cout<<"Invalid input!  No such a property called "<<receive<<"!"<<endl;
                                 continue;
                                 }
                    if (board[tp2]->getOwner()==NULL){
                                                      cout<<"Invalid input!  Property "<<receive<<" is unoccupied!"<<endl;
                                                      continue;
                                                      }
                    if (board[tp2]->getOwner()->getName()!=playerList[temp]->getName()){
                       cout<<"Invalid input!  Property "<<receive<<" does not belong to "<<playerList[temp]->getName()<<"!"<<endl;
                       continue;
                       }
                    askForTrade(playerList[i],playerList[temp],board[tp1],board[tp2]);
                    }// if trade
                 if (s=="improve") {
                    valid=true;
                    //display();
                    cin>>property;
                    tp1=searchForProperty(property);
                    if (tp1==-1) {
                                 cout<<"Invalid input!  No such a property called "<<property<<"!"<<endl;
                                 continue;
                                 }
                    if (!board[tp1]->upgradable()){
                                                   cout<<"Property "<<property<<" cannot be upgraded!"<<endl;
                                                   continue;
                                                   }
                    cin>>bs;
                    if (bs!="buy" && bs!="sell"){
                       cout<<"Invalid input!  You should enter 'buy' or 'sell!"<<endl;
                       continue;
                       }
                    if (bs=="buy"){
                       lv=board[tp1]->getLevel();
                       if (lv==5) {
                                  cout<<"Invalid input!  Property "<<property<<" is in the highest level!"<<endl;
                                  continue;
                                  }
                       if (checkForMonopoly(board[tp1])) {
                          if (playerList[i]->getCash()<board[tp1]->getUpgradePrice()) {
                             cout<<"You do not have enough money to upgrade "<<property<<"!"<<endl;
                             continue;
                             }
                          board[tp1]->upgrade();
                          playerList[i]->loseMoney(board[tp1]->getUpgradePrice());
                          display();
                          }
                          else {
                               cout<<"You cannot upgrade "<<property<<" right now because no monopoly is formed!"<<endl;
                               continue;
                               }
                       }
                    if (bs=="sell"){
                       lv=board[tp1]->getLevel();
                       if (lv==0) {
                                  cout<<"Property "<<property<<" has no improvement to sell!"<<endl;
                                  continue;
                                  }
                       board[tp1]->degrade();
                       playerList[i]->receiveMoney(board[tp1]->getUpgradePrice()/2);
                       display();
                       }
                    }// if improve
                 if (s=="mortgage"){
                    valid=true;
                    display();
                    cin>>property;
                    tp1=searchForProperty(property);
                    if (tp1==-1) {
                                 cout<<"Invalid input!  No such a property called "<<property<<"!"<<endl;
                                 continue;
                                 }
                    if (board[tp1]->getLevel()!=0){
                       cout<<"Cannot mortgage "<<property<<" because there is still improvement there!"<<endl;
                       continue;
                    }
                    if (!board[tp1]->getMortgaged()){
                       cout<<"Cannot mortgage "<<property<<" because it has been mortgaged!"<<endl;
                       continue;
                       }
                    board[tp1]->mortgage();
                    playerList[i]->receiveMoney(board[tp1]->getCost()/2);
                 }//if mortgage
                 if (s=="unmortgage"){
                    valid=true;
                    display();
                    cin>>property;
                    tp1=searchForProperty(property);
                    if (tp1==-1) {
                                 cout<<"Invalid input!  No such a property called "<<property<<"!"<<endl;
                                 continue;
                                 }
                    if (board[tp1]->getMortgaged()){
                       cout<<"Cannot unmortgage "<<property<<" because it has not been mortgaged!"<<endl;
                       continue;
                       }
                    if (playerList[i]->getCash()<board[tp1]->getCost()*0.55){
                       cout<<"Cannot unmortgage "<<property<<" because you do not have enough money!"<<endl;
                       continue;
                       }
                    board[tp1]->unmortgage();
                    playerList[i]->loseMoney(board[tp1]->getCost()*0.55);
                 }//if unmortgage
                 if (s=="assets"){
                    valid=true;
                    bool ttt=false;
                    string plr;
                    int tp;
                    if (cin.peek()!='\n'){
                       cin>>plr;
                       ttt=true;
                       tp=searchForPlayer(plr);
                       if (tp==-1) {
                          cout<<"Invalid input!  No such a player called "<<plr<<"!"<<endl;
                          continue;
                          }
                       }
                    display();
                    if (ttt) getAssets(playerList[tp]);
                    else getAssets(playerList[i]);
                    }//if assets
                 if (s=="bankrupt"){
                    valid=true;
                    display();
                    bool ttt;
                    ttt=bankrupt(playerList[i]);
                    if (ttt) {
 		       if (isWin()){
			  int jj;
			  for (jj=0;jj<numPlayer;jj++)
			      if (playerList[jj]->isAlive()){
				 cout<<"Player "<<playerList[jj]->getName()<<" wins!"<<endl;
				 cout<<"Thanks for playing! :')"<<endl;
				 sleep();
				 return;
				 }
			  }	
	               continue;
		       }
                    }//if bankrupt
                 if (s == "save") {
                    valid = true;
                    string filename;
                    cin >> filename;
                    saveGame(filename,i);
                    } //if save
                 if (s == "help") {
                    valid = true;
                    cout << "roll: if the player can roll, the player rolls two dice, moves the sum of the two dice and takes action on the square they landed on." << endl;
                    cout << "next:  if the player cannot roll, gives control to the next player." << endl;
                    cout << "trade <name> <give> <receive>: offers a trade to name with the current player offering 'give' and requesting 'receive', where give and receive are either amounts of money or a property name. Responses are 'accept' and 'reject'." << endl;
                    cout << "improve <property> buy/sell: attemptes to buy or sell an improvement for 'property'" << endl;
                    cout << "mortgage <property>: attempts to mortgage 'property'" << endl;
                    cout << "unmortgage <property>: attempts to unmortgage 'property'" << endl;
                    cout << "bankrupt: player declares bankruptcy. This conmmand is only available when a player must pay more money then they currently have." << endl;
                    cout << "assets: displays the assets of the current player. Does not work if the player is deciding how to pay Tuition." << endl;
                    cout << "save <filename>: saves the current state of the game to the given file." << endl;
                    cout << "-testing: unlocks the testing mode. Player can specify the dice by entering 'roll <die1> <die2>' and if the dice are not specified, the normal roll command will be used. When entering '-testing' again, testing mode will be locked." << endl;
                    cout << "exit: exit the game." << endl;
                    }  //if help
                 if (s == "exit") {
                    cout << "Thanks for playering! :')" << endl;
		    sleep();
                    return;
                    } //if exit
                 if (!valid) cout<<"Invalid input!  No command names "<<s<<"!"<<endl;
                 }//while (1) for command
           }//while(1) for game
     }

void Controller::saveGame(string filename, int currentPlayer) {
    ofstream out (filename.c_str());
    out << numPlayer << endl;
    out<<currentPlayer<<endl;
    out<<rollTime<<endl;
    out<<canRoll<<endl;
    out<<playerList[currentPlayer]->getOweMoney()<<endl;
    if (playerList[currentPlayer]->getOwePlayer()==NULL) out<<"BANK"<<endl;
    else out<<playerList[currentPlayer]->getOwePlayer()->getName()<<endl;
    for (int n = 0; n < numPlayer; ++n) {
        out << playerList[n]->getName() << " " << playerList[n]->getChr() << " " << playerList[n]->getRURC() << " " << playerList[n]->getCash() << " " << playerList[n]->getPosition();
        if (playerList[n]->getPosition() == 10) {
            if (playerList[n]->isInTim() == false) { out << " " << "0"; }
            else { out << " " << "1" << " " << playerList[n]->getTimRound(); }
        }
        out << endl;
    }
    
    for (int i = 0; i < 40; ++i) {
        if (board[i]->isProperty() && !board[i]->isResidence() && !board[i]->isGym()) {
            if (board[i]->getOwner() == NULL) {
                out << board[i]->getName() << " " << "BANK" << " " << "0" << endl;
            }
            else {
                out << board[i]->getName() << " " << board[i]->getOwner()->getName() << " " << board[i]->getLevel() << endl;
            }
        }
    }
}

void Controller::loadGame(string filename) {
    //initialize(); 
    srand(time(0));
    firstRoundOfLoad=true;
    string read;
    ifstream in (filename.c_str());
    in >> numPlayer;
    in>>startPlayer;
    in>>rollTime;
    in>>canRoll;
    in>>startOweMoney;
    in>>startOwePlayer;
    int i;
    for (i=0;i<numPlayer;i++){
        playerList[i]=new Player("a",'a');
        }
    for (i = 0; i < numPlayer; ++i) {
        in >> read;
        playerList[i]->setName(read);
        in >> read;
        playerList[i]->setChr(read[0]);
        in >> read;
        int x = stringToNum(read);
        playerList[i]->setRURC(x);
        in >> read;
        x = stringToNum(read);
        playerList[i]->setCash(x);
        in >> read;
        x = stringToNum(read);
        playerList[i]->setPosition(x);
        playerList[i]->moveto(board[x]);
        if (read == "10") {
            in >> read;
            if (read == "1") {
                playerList[i]->putInTim();
                in >> read;
                x = stringToNum(read);
                playerList[i]->setNumTim(x);
            }
        }
    }
    
    for (int i = 0; i < 40; ++i) {
        if (board[i]->isProperty() && !board[i]->isResidence() && !board[i]->isGym()) {
            in >> read;
            in >> read;
            if (read == "BANK") {
                board[i]->setOwner(NULL);
                //board[i]->setLevel(0);
                in >> read;
                board[i]->setLevel(0);
            }
            else {
                board[i]->setOwner(playerList[searchForPlayer(read)]);
                in >> read;
                int y = stringToNum(read);
                board[i]->setLevel(y);
            }
        }
    }
    display();
}

void Controller::getAssets(Player *p){
     int i;
     cout<<"Player "<<p->getName()<<"'s assets goes:"<<endl;
     cout<<"Cash: $"<<p->getCash()<<endl;
     cout<<"Properties:"<<endl;
     for (i=0;i<40;i++){
         if (board[i]->isProperty()){
            if (board[i]->getOwner()==NULL) continue;
            if (board[i]->getOwner()->getName()==p->getName()) cout<<board[i]->getName()<<endl;
            }
         }
     }

int Controller::calAssets(Player *p){
    int total=p->getCash();
    int i;
    for (i=0;i<40;i++){
        if (board[i]->isProperty()){
           if (board[i]->getOwner()==NULL) continue;
           if (board[i]->getOwner()->getName()==p->getName()){
              total+=board[i]->getCost()+board[i]->getLevel()*board[i]->getUpgradePrice();
              }
           }  
        }
    return total;
    }

void Controller::putIntoTim(Player *p){
     p->setPosition(10);
     p->moveto(board[10]);
     p->putInTim();
     p->clnTimRound();
     }
     
void Controller::arriveAt(Player *p, int position){
     int cost;
     string s;
     int tuition;
     p->setPosition(position);
     p->moveto(board[position]); 
     //display();
     int i,j;
     int nGym[8], nResi[8];
     for (i=0;i<8;i++){
         nGym[i]=0;
         nResi[i]=0;
         }
     for (i=0;i<40;i++){
         if (!board[i]->isProperty()) continue;
         if (board[i]->getOwner()==NULL) continue;
         if (!board[i]->isGym() && !board[i]->isResidence()) continue;
         for (j=0;j<numPlayer;j++){
             if (playerList[j]->getName()==board[i]->getOwner()->getName()){
                if (board[i]->isGym()) nGym[j]++;
                if (board[i]->isResidence()) nResi[j]++;
                }
             }
         }
     for (i=0;i<numPlayer;i++){
         playerList[i]->setNumResidence(nResi[i]);
         playerList[i]->setNumGym(nGym[i]);
         }
     cout<<"Listen, "<<p->getName()<<"!  You've arrived at "<<board[position]->getName()<<"!"<<endl;
     sleep();
     display();
     if (board[position]->isProperty()) {
        if (board[position]->getOwner()==NULL){
           cost=board[position]->getCost();
           cout<<board[position]->getName()<<" is an unoccupied property that costs you $"<<cost<<endl;
           if (cost>p->getCash()) {
                                  cout<<"You don't have enough money to purchase the property"<<endl;
                                  s="no";
                                  }
           else while (1){
                cout<<"Do you want to purchase the property?  Please input 'yes' or 'no':";
                cin>>s;
                if (s=="yes" || s=="no") break;
                cout<<"Invalid input!  You should enter either 'yes' or 'no'!"<<endl;
                }
           if (s=="yes") {
                         board[position]->setOwner(p);
                         p->loseMoney(cost);
                         cout<<"Property "<<board[position]->getName()<<" now belongs to "<<p->getName()<<"!"<<endl;
                         }
           if (s=="no") {auction(board[position]);}
           }//has no owner
        else {// has owner
           cout<<board[position]->getName()<<" is a property that owned by ";
           if (p->getName()==board[position]->getOwner()->getName()){
              cout<<"you!"<<endl;
              if (board[position]->getMortgaged()) cout<<"And now it is mortgaged!"<<endl;
              }
           else {
                cout<<board[position]->getOwner()->getName()<<"!"<<endl;
                if (board[position]->getMortgaged()) cout<<"And now it is mortgaged!"<<endl;
                else {
                     tuition=board[position]->getTuition();
                     if (checkForMonopoly(board[position])) tuition=tuition*2;
                     cout<<"You need to pay $"<<tuition<<" to "<<board[position]->getOwner()->getName()<<" at the end of your turn or before rolling the next time!"<<endl;
                     p->setOwePlayer(board[position]->getOwner());
                     p->setOweMoney(tuition);
                     }
                }
           }
        }// if is property
     else {
          p->setMove(0);
          board[position]->function(p,numRURC);
          if (p->getMove()!=0) {
             if (p->getMove()==100) putIntoTim(p);
             else if (p->getMove()==200) {
                     cout<<"Player "<<p->getName()<<" just walked passed OSAP and collected $200!"<<endl;
                     p->receiveMoney(200);
                     }
             else if (p->getMove()==300){
                  numRURC--;
                  }
             else {
                  int tx=p->getPosition()+p->getMove();
                  if (tx>40) tx=tx-40;
                  if (tx<0) tx=40+tx;
                  arriveAt(p,tx);
                  }
             }
          }// if is nonproperty
     }

bool Controller::checkForMonopoly(Grid *g){
     if (g->getOwner()==NULL) return false;
     if (g->isGym()) return false;
     if (g->isResidence()) return false;
     string pname=g->getOwner()->getName();
     string sname=g->getSubject();
     int i;
     for (i=0;i<40;i++)
         if (board[i]->isProperty() && (board[i]->getSubject()==sname)) {
            if (board[i]->getOwner()==NULL) return false;
            if (board[i]->getOwner()->getName()!=pname ) return false;
            }
     return true;
     }

bool Controller::isWin(){
     int i;
     int count=0;
     for (i=0;i<numPlayer;i++)
         if (playerList[i]->isAlive()) count++;
     return count==1;
     }

bool Controller::rollDice(Player *p, int t){
     int d1,d2;
     cout<<"Player "<<p->getName()<<" rolls dice!"<<endl;
     sleep();
     d1=rand()%6+1;
     //d1=2;
     d2=rand()%6+1;
     //d2=2;
     cout<<"The outcome is "<<d1<<" and "<<d2<<"!"<<endl;
     sleep();
     if (p->isInTim()) {
        if (d1==d2) {
           cout<<"A double!  Player "<<p->getName()<<" gets rid of DC Tims Line!"<<endl;
           sleep();
           p->outOfTim();
           p->clnTimRound();
           return false;
           }
        else {
             cout<<"Not a double!  Unfortunately Player "<<p->getName()<<" is still in DC Tims Line!"<<endl;
             sleep();
             return false;
             }
        }
     if (t==3 && d1==d2) {
        cout<<"The third double!  Player "<<p->getName()<<" is exausted and needs some caffeine in DC Tims Line!"<<endl;
        sleep();
        putIntoTim(p);
        display();
        return false;
        }
     if (d1==d2) {
                 cout<<"A double!  Player "<<p->getName()<<" has a chance to roll dice again!"<<endl;
                 sleep();
                 }
     int np=p->getPosition()+d1+d2;
     if (np>40){
        cout<<"Player "<<p->getName()<<" just walked passed OSAP and collected $200!"<<endl;
        sleep();
        p->receiveMoney(200);
        }
     np=np%40;
     arriveAt(p,np);
     return d1==d2;
     }
     
bool Controller::rollDice(Player *p, int t, int x1, int x2){
     int d1,d2;
     cout<<"Player "<<p->getName()<<" rolls dice!"<<endl;
     sleep();
     d1=x1;
     d2=x2;
     cout<<"The outcome is "<<d1<<" and "<<d2<<"!"<<endl;
     sleep();
     if (p->isInTim()) {
        if (d1==d2) {
           cout<<"A double!  Player "<<p->getName()<<" gets rid of DC Tims Line!"<<endl;
           sleep();
           p->outOfTim();
           p->clnTimRound();
           return false;
           }
        else {
             cout<<"Not a double!  Unfortunately Player "<<p->getName()<<" is still in DC Tims Line!"<<endl;
             sleep();
             return false;
             }
        }
     if (t==3 && d1==d2) {
        cout<<"The third double!  Player "<<p->getName()<<" is exausted and needs some caffeine in DC Tims Line!"<<endl;
        sleep();
        putIntoTim(p);
        display();
        return false;
        }
     if (d1==d2) {
                 cout<<"A double!  Player "<<p->getName()<<" has a chance to roll dice again!"<<endl;
                 sleep();
                 }
     int np=p->getPosition()+d1+d2;
     if (np>40){
        cout<<"Player "<<p->getName()<<" just walked passed OSAP and collected $200!"<<endl;
        sleep();
        p->receiveMoney(200);
        }
     np=np%40;
     arriveAt(p,np);
     return d1==d2;
     }

void Controller::multiPrint(string str, int size) {
    for (int i = 0; i < size; ++i) {
        cout << str;
    }
}

void Controller::printChr(Grid *g) {
    bool isPos = false;
    string output;
    for (int i = 0; i < numPlayer; ++i) {
        if (playerList[i]->getGrid() == g) {
            output += playerList[i]->getChr();
            isPos = true;
        }
    }
    if (isPos) {
        cout << setw(7) << output;
    }
    else {
        cout << "       ";
    }
}

void Controller::display() {
    multiPrint("-",89);  //line 1
    cout << endl;
    cout << "|Goose  |";
    cout << left << setw(7);
    if (board[21]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[21]->getLevel());  //EV1
    cout << "|NEEDLES|";
    cout << left << setw(7);
    if (board[23]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[23]->getLevel());
    cout << "|";
    cout << left << setw(7);
    if (board[24]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[24]->getLevel());
    cout << "|V1     |";
    cout << left << setw(7);
    if (board[26]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[26]->getLevel());
    cout << "|";
    cout << left << setw(7);
    if (board[27]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[27]->getLevel());
    cout << "|CIF    |";
    cout << left << setw(7);
    if (board[29]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[29]->getLevel());
    cout << "|GO TO  |";  //line 2
    cout << endl;
    cout << "|Nesting|";
    multiPrint("-", 7);
    cout << "|HALL   |";
    multiPrint("-", 7);
    cout << "|";
    multiPrint("-",7);
    cout << "|       |";
    multiPrint("-", 7);
    cout << "|";
    multiPrint("-", 7);
    cout << "|       |";
    multiPrint("-", 7);
    cout << "|TIMS   |";   //line 3
    cout << endl;
    cout << "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";  //line 4
    cout << endl;
    cout << "|";
    printChr(board[20]);
    cout << "|";
    printChr(board[21]);
    cout << "|";
    printChr(board[22]);
    cout << "|";
    printChr(board[23]);
    cout << "|";
    printChr(board[24]);
    cout << "|";
    printChr(board[25]);
    cout << "|";
    printChr(board[26]);
    cout << "|";
    printChr(board[27]);
    cout << "|";
    printChr(board[28]);
    cout << "|";
    printChr(board[29]);
    cout << "|";
    printChr(board[30]);
    cout << "|";   //line 5
    cout << endl;
    cout << "|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|";  //line 6
    cout << endl;
    cout << "|";
    cout << left << setw(7);
    if (board[19]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[19]->getLevel());
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    cout << left << setw(7);
    if (board[31]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[31]->getLevel());
    cout << "|";   // line 7
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 8
    cout << endl;
    cout << "|OPT    |";
    multiPrint(" ", 71);
    cout << "|EIT    |";   //line 9
    cout << endl;
    cout << "|";
    printChr(board[19]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[31]);
    cout << "|";   //line 10
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 11
    cout << endl;
    cout << "|";
    cout << left << setw(7);
    if (board[18]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[18]->getLevel());
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    cout << left << setw(7);
    if (board[32]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[32]->getLevel());
    cout << "|";   //line 12
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";  //line 13
    cout << endl;
    cout << "|BMH    |";
    multiPrint(" ", 71);
    cout << "|ESC    |";  //line 14
    cout << endl;
    cout << "|";
    printChr(board[18]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[32]);
    cout << "|";   //line 15
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";  //line 16
    cout << endl;
    cout << "|SLC    |";
    multiPrint(" ", 71);
    cout << "|SLC    |";   //line 17
    cout << endl;
    cout << "|       |";
    multiPrint(" ", 71);
    cout << "|       |";   //line 18
    cout << endl;
    cout << "|       |";
    multiPrint(" ", 71);
    cout << "|       |";   //line 19
    cout << endl;
    cout << "|";
    printChr(board[17]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[33]);
    cout << "|";   //line 20
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 21
    cout << endl;
    cout << "|";
    cout << left << setw(7);
    if (board[16]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[16]->getLevel());
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    cout << left << setw(7);
    if (board[34]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[34]->getLevel());
    cout << "|";   // line 22
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 23
    cout << endl;
    cout << "|LHI    |";
    multiPrint(" ", 71);
    cout << "|C2     |";   //line 24
    cout << endl;
    cout << "|";
    printChr(board[16]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[34]);
    cout << "|";   //line 25
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 26
    cout << endl;
    cout << "|UWP    |";
    multiPrint(" ", 71);
    cout << "|REV    |";   //line 27
    cout << endl;
    cout << "|       |";
    multiPrint(" ", 71);
    cout << "|       |";   //line 28
    cout << endl;
    cout << "|       |";
    multiPrint(" ", 71);
    cout << "|       |";   //line 29
    cout << endl;
    cout << "|";
    printChr(board[15]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[35]);
    cout << "|";   //line 30
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 31
    cout << endl;
    cout << "|";
    cout << left << setw(7);
    if (board[14]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[14]->getLevel());
    cout << "|";
    multiPrint(" ", 71);
    cout << "|NEEDLES|";   //line 32
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|HALL   |";   //line 33
    cout << endl;
    cout << "|CPH    |";
    multiPrint(" ", 71);
    cout << "|       |";   //line 34
    cout << endl;
    cout << "|";
    printChr(board[14]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[36]);
    cout << "|";   //line 35
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 36
    cout << endl;
    cout << "|";
    cout << left << setw(7);
    if (board[13]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[13]->getLevel());
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    cout << left << setw(7);
    if (board[37]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[37]->getLevel());
    cout << "|";   // line 37
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 38
    cout << endl;
    cout << "|DWE    |";
    multiPrint(" ", 71);
    cout << "|MC     |";   //line 39
    cout << endl;
    cout << "|";
    printChr(board[13]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[37]);
    cout << "|";   //line 40
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 41
    cout << endl;
    cout << "|PAC    |";
    multiPrint(" ", 71);
    cout << "|COOP   |";    //line 42
    cout << endl;
    cout << "|       |";
    multiPrint(" ", 71);
    cout << "|FEE    |";    //line 43
    cout << endl;
    cout << "|       |";
    multiPrint(" ", 71);
    cout << "|       |";    //line 44
    cout << endl;
    cout << "|";
    printChr(board[12]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[38]);
    cout << "|";    //line 45
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 46
    cout << endl;
    cout << "|";
    cout << left << setw(7);
    if (board[11]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[11]->getLevel());
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    cout << left << setw(7);
    if (board[39]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[39]->getLevel());
    cout << "|";   // line 47
    cout << endl;
    cout << "|-------|";
    multiPrint(" ", 71);
    cout << "|-------|";   //line 48
    cout << endl;
    cout << "|RCH    |";
    multiPrint(" ", 71);
    cout << "|DC     |";   //line 49
    cout << endl;
    cout << "|";
    printChr(board[11]);
    cout << "|";
    multiPrint(" ", 71);
    cout << "|";
    printChr(board[39]);
    cout << "|";   //line 50
    cout << endl;
    cout << "|-------|-----------------------------------------------------------------------|-------|";  //line 51
    cout << endl;
    cout << "|DC Tims|";
    cout << left << setw(7);
    if (board[9]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[9]->getLevel());
    cout << "|";
    cout << left << setw(7);
    if (board[8]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[8]->getLevel());
    cout << "|NEEDLES|";
    cout << left << setw(7);
    if (board[6]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[6]->getLevel());
    cout << "|MKV    |";
    cout << "TUITION|";
    cout << left << setw(7);
    if (board[3]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[3]->getLevel());
    cout << "|SLC    |";
    cout << left << setw(7);
    if (board[1]->getLevel() == 0) cout << "       ";
    else multiPrint("I",board[1]->getLevel());
    cout << "|COLLECT|";   //line 52
    cout << endl;
    cout << "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";  //line 53
    cout << endl;
    cout << "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";  //line 54
    cout << endl;
    cout << "|";
    printChr(board[10]);
    cout << "|";
    printChr(board[9]);
    cout << "|";
    printChr(board[8]);
    cout << "|";
    printChr(board[7]);
    cout << "|";
    printChr(board[6]);
    cout << "|";
    printChr(board[5]);
    cout << "|";
    printChr(board[4]);
    cout << "|";
    printChr(board[3]);
    cout << "|";
    printChr(board[2]);
    cout << "|";
    printChr(board[1]);
    cout << "|";
    printChr(board[0]);
    cout << "|";
    cout << endl;
    cout << "|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|";
    cout << endl;
}
