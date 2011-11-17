#include "framework.h"
#include "vectorController.h"

#define vectorController vectorController::get()


framework::framework()
{
    //ctor
    vectorController->newNode();
    NUMBERCELLS=64;
}

void framework::init_board()
{
    for (int i=0;i<NUMBERCELLS;i++)
    {
        
        vectorController->newNode();
        vectorController->cells[i].boolean["visible"]=false;

        vectorController->cells[i].color["cellbkg"]=sf::Color(37,158,6);
        vectorController->cells[i].color["cellborder"]=sf::Color(68,107,5);
        vectorController->cells[i].color["chipcolorp1"]=sf::Color(255,255,255);
        vectorController->cells[i].color["chipcolorp2"]=sf::Color(0,0,0);

        vectorController->cells[i].integer["belongsto"]=0;//1 for p1,2 for p2 
        
    }
}
