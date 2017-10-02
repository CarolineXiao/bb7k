#ifndef __PLAYER_H__
#define __PLAYER_H__
#include<string>
//#include "grid.h"
//class Controller;
class Grid;
class Player {
       int cash;
       bool inTim;
       std::string name;
       char chr;
       Grid *current;
       int position;
       int numRURC;
       int timRound;
       //Controller *controller;
       bool alive;
       int numResidence;
       int numGym;
       Player *owePlayer;
       int oweMoney;
       int move;
       int asset;
      public: 
       Player(std::string name, char chr);//done
       std::string getName();//done
       char getChr();//done
       Grid *getGrid();//done
       int getPosition();//done
       int getCash();//done
       int getNumResidence();//done
       int getNumGym();//done
       int getOweMoney();//done
       Player *getOwePlayer();//done
       void receiveMoney(int x);//done
       void loseMoney(int x);//done
       void setChr(char ch);//done
       void setName(std::string nm);//done
       void setRURC(int x);//done
       void setCash(int x);//done
       void setInTim(bool x);//done
       void setPosition(int x);//done
       void setOweMoney(int x);//done
       void setOwePlayer(Player *p);//done
       void setNumResidence(int x);//done
       void setNumGym(int x);//done
       void moveto(Grid *grid);//done
       void bankrupt();//done
       bool isAlive();//done
       bool isInTim();//done
       void putInTim();//done
       void outOfTim();//done
       void addRURC();//done
       void decRURC();//done
       int getRURC();//done
       int getTimRound();//done
       void addTimRound();//done
       void clnTimRound();//done
       void setNumTim(int x);//done
       void setMove(int x);//done
       int getMove();//done
       void setAsset(int x);//done
       int getAsset();//done
      };

#endif

