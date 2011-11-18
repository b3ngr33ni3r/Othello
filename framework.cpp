#include "framework.h"
#include "vectorController.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define vectorController vectorController::get()
//#define window windowController::get()
//do the above so it looks a little prettier

framework::framework(sf::RenderWindow& window)
{
    //ctor

    NUMBERCELLS=64;
    CELLWIDTH=30;
    CELLSPERROW=8;

    board_topleft_x=((window.GetWidth()/2)-((CELLWIDTH*CELLSPERROW)/2));
    board_topleft_y=((window.GetHeight()/2)-((CELLWIDTH*CELLSPERROW)/2));

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
        //and .integer[x,y,x2,y2] will be set when dimensions are set
    }
    write_dimensions();
}

void framework::write_dimensions()
{

for (int a=0;a<NUMBERCELLS;a++){
    std::cout<<((a%CELLSPERROW)+1)<<std::endl;
    /*
    vectorController->cells[a].integer["x"]=(((a%CELLSPERROW)*CELLWIDTH)+board_topleft_x);
    vectorController->cells[a].integer["x2"]=((((a%CELLSPERROW)*CELLWIDTH)+board_topleft_x)+CELLWIDTH);

    vectorController->cells[a].integer["y"]=(((a%CELLSPERROW)*CELLWIDTH)+board_topleft_y);
    vectorController->cells[a].integer["y2"]=((((a%CELLSPERROW)*CELLWIDTH)+board_topleft_y)+CELLWIDTH);
    */

}


}
