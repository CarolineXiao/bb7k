#ifndef __GRID_H__
#define __GRID_H__
#include<string> 
#include "cards.h"
#include "player.h"
class Grid {
      public:
       std::string name;
       Grid(std::string name);
       std::string getName(); 
       virtual std::string getSubject()=0;
       virtual bool isProperty()=0;
       virtual bool isResidence()=0;
       virtual bool isGym()=0;
       virtual bool upgradable()=0;
       virtual bool getMortgaged()=0;
       virtual void setOwner(Player *p)=0;
       virtual int getCost()=0;
       virtual int getTuition()=0;
       virtual Player *getOwner()=0;
       virtual void upgrade()=0;
       virtual void degrade()=0;
       virtual int getLevel()=0;
       virtual int getUpgradePrice()=0;
       virtual void mortgage()=0;
       virtual void unmortgage()=0;
       virtual void clear()=0;
       virtual void function(Player *p, int rurc)=0;
       virtual void setLevel(int x)=0;
      };
      
class Property : public Grid {
      protected:
       int cost;
       int tuition;
       Player *owner;
       bool mortgaged;
      public:
       Property(std::string name); 
       bool isProperty();
       void setCost();
       int getCost();
       Player *getOwner();
       void mortgage();
       void unmortgage();
       bool getMortgaged(); 
       void setOwner(Player *p);
       void setLevel(int x){};
      };

class ABuilding : public Property {
       int improvementCost;
       int level;
       std::string subject;
       int tuitions[6];
      public:
       //ABuilding(string name);
       ABuilding(std::string name, std::string subject, int cost, int improvementCost);
       void setTuition(int lv0, int lv1, int lv2, int lv3, int lv4, int lv5);
       void upgrade();
       void degrade();
       int getTuition();
       std::string getSubject();
       bool upgradable();
       int getLevel();
       int getUpgradePrice();
       void clear();
       bool isResidence();
       bool isGym();
       void function(Player *p, int rurc){};
       void setLevel(int x);
      };

class Residence : public Property {
      public:
       std::string getSubject(){return "";} 
       Residence(std::string name); 
       int getLevel();
       int getTuition();
       bool upgradable();
       bool isResidence();
       bool isGym();
       void clear(){};
       void upgrade(){};
       void degrade(){};
       int getUpgradePrice(){return 0;};
       void function(Player *p, int rurc){};
       void setLevel(int x){};
      };

class Gym : public Property {
      public:
       std::string getSubject(){return "";}      
       Gym(std::string name); 
       int getLevel();
       int getTuition();
       bool upgradable();
       bool isResidence();
       bool isGym();
       void clear(){};
       void upgrade(){};
       void degrade(){};
       int getUpgradePrice(){return 0;};
       void function(Player *p, int rurc){};
       void setLevel(int x){};
      };

class NonProperty : public Grid {
      public:
       NonProperty(std::string name);
       std::string getSubject(){return "";}
       bool isProperty();
       bool isResidence(){return false;}
       bool isGym(){return false;}
       bool upgradable();
       bool getMortgaged(){return false;}
       void setOwner(Player *p){};
       int getCost(){return 0;}
       int getTuition(){return 0;}
       Player *getOwner(){return NULL;}
       void upgrade(){};
       void degrade(){};
       int getLevel(){return 0;}
       int getUpgradePrice(){return 0;}
       void mortgage(){};
       void unmortgage(){};
       void clear(){};
       void function(Player *p, int rurc);
       void setLevel(int x){};
      };
#endif

