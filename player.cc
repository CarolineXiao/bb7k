#include <string>
#include <iostream>
#include "player.h"
using namespace std;

Player::Player (string name, char chr){
               this->name=name;
               this->chr=chr;
               current=NULL;
               owePlayer=NULL;
               cash=1500;
               inTim=false;
               alive=true;
               numRURC=0;
               }

string Player::getName(){
       return name;
       }

char Player::getChr(){
     return chr;
     }

Grid *Player::getGrid(){
     return current;
     }

int Player::getPosition(){
    return position;
    }
    
int Player::getCash(){
    return cash;
    }
    
int Player::getOweMoney(){
    return oweMoney;
    }

int Player::getNumResidence(){
    return numResidence;
    }
    
int Player::getNumGym(){
    return numGym;
    }

Player *Player::getOwePlayer(){
       return owePlayer;
       }

void Player::receiveMoney(int x){
     cash=cash+x;
     }

void Player::loseMoney(int x){
     cash=cash-x;
     }

void Player::setPosition(int x){
     position=x;
     }
     
void Player::moveto(Grid *grid){
     current=grid;
     }
     
void Player::bankrupt(){
     alive=false;
     }

void Player::setOweMoney(int x){
     oweMoney=x;
     }
     
void Player::setOwePlayer(Player *p){
     owePlayer=p;
     }

bool Player::isAlive(){
     return alive;
     }

void Player::setNumResidence(int x){
     numResidence=x;
     }

void Player::setNumGym(int x){
     numGym=x;
     }
     
bool Player::isInTim(){
     return inTim;
     }
     
void Player::putInTim(){
     inTim=true;
     }

void Player::outOfTim(){
     inTim=false;
     }

void Player::addRURC(){
     numRURC++;
     }
     
void Player::decRURC(){
     numRURC--;
     }

int Player::getRURC(){
    return numRURC;
    }

int Player::getTimRound(){
    return timRound;
    }
    
void Player::addTimRound(){
     timRound++;
     }
     
void Player::clnTimRound(){
     timRound=0;
     }

void Player::setNumTim(int x){
     timRound=x;
     }

void Player::setMove(int x){
     move=x;
     }

int Player::getMove(){
    return move;
    }
    
void Player::setAsset(int x){
     asset=x;
     }

int Player::getAsset(){
    return asset;
    }

void Player::setRURC(int x) {
    numRURC = x;
}

void Player::setCash(int x) {
    cash = x;
}

void Player::setInTim(bool x) {
    inTim = x;
}

void Player::setChr(char ch) {
     chr=ch;
     }
     
void Player::setName(std::string nm) {
     name=nm;
     }

