#include <iostream>
#include <string>
#include "controller.h"
using namespace std;

int main(){
    cout << "Hello! Welcome come to BB7K designed by Caroline && Derek! :')" << endl;
    cout << "Enter '-new' to start a new game; enter '-load' to load a saved game:";
    string command;
    while (1) {
        cin >> command;
        if (command == "-new" || command == "-load") {
            if (command == "-new") {
                Controller *c=new Controller();
                c->initialize();
                c->start();
                c->play();
                delete c;
            }
            else {
                cout << "Please enter the name of file you want to load:" << endl;
                string filename;
                cin >> filename;
                Controller *s = new Controller();
                s->initialize();
                s->loadGame(filename);
                s->play();
                delete s;
            }
            break;
        }
        else {
            cout << "Please enter '-new' or '-load' !" << endl;
        }
    }
}

