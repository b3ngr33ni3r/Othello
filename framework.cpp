#include "framework.h"
#include "vectorController.h"
#include <SFML/Graphics.hpp>

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

    for (int i=0;i<CELLSPERROW;i++){
        for (int j=0;j<CELLSPERROW;j++){

    vectorController->cells[i].integer["x"]=((i*CELLWIDTH)+board_topleft_x);
    vectorController->cells[i].integer["x2"]=(((i*CELLWIDTH)+board_topleft_x)+CELLWIDTH);

    vectorController->cells[i].integer["y"]=((j*CELLWIDTH)+board_topleft_y);
    vectorController->cells[i].integer["y2"]=(((j*CELLWIDTH)+board_topleft_y)+CELLWIDTH);
        }}

}
