#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include<string>
#include<iostream>
#include "grid.h"

class Controller{
       Player *playerList[8];
       int numPlayer;
       int currentPlayer;
       int numRURC;
       Grid *board[40];
       int searchForPlayer(std::string name);//done
       int searchForProperty(std::string name);//done
       int stringToNum(std::string s);//done
       bool isNum(std::string s);//done
       void multiPrint(std::string str, int size);//done
       void printChr(Grid *g);//done
       void sleep();//done
       bool testMode;
       bool diydice;
       void switchTest();//done
       bool canRoll;
       bool firstRoundOfLoad;
       int rollTime;
       int startPlayer;
       int startOweMoney;
       std::string startOwePlayer;
      public:
       Controller();//done
       ~Controller();//done
       void initialize();//done
       void start();//done
       void askForTrade(Player *p1, Player *p2, int money, Grid *g);//done
       void askForTrade(Player *p1, Player *p2, Grid *g, int money);//done
       void askForTrade(Player *p1, Player *p2, Grid *g1, Grid *g2);//done
       void auction(Grid *t);//done
       bool bankrupt(Player *p);//done
       void saveGame(std::string filename, int currentPlayer);
       void loadGame(std::string filename);
       void play();//done
       void display();
       void getAssets(Player *p);//done
       int calAssets(Player *p);
       void putIntoTim(Player *p);//done
       void arriveAt(Player *p, int position);//done
       bool checkForMonopoly(Grid *g);//done
       bool isWin();//done
       bool rollDice(Player *p, int t);//done
       bool rollDice(Player *p, int t, int x1, int x2);
      };
#endif

