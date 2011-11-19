#include "framework.h"
#include "vectorController.h"
#include <SFML/Graphics.hpp>

//define vectorClass vectorController
//#define vectorController vectorController::get()
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

        vectorController::get()->newNode();
        vectorController::get()->cells[i].boolean["visible"]=false;
        vectorController::get()->cells[i].boolean["valid space"]=false;

        vectorController::get()->cells[i].color["cell bkg"]=sf::Color(37,158,6);
        vectorController::get()->cells[i].color["cell border"]=sf::Color(68,107,5);
        vectorController::get()->cells[i].color["chip color p1"]=sf::Color(255,255,255);
        vectorController::get()->cells[i].color["chip color p2"]=sf::Color(0,0,0);
        vectorController::get()->cells[i].color["valid space color"]=sf::Color(255,251,0);

        vectorController::get()->cells[i].integer["chip radius addition"]=(CELLWIDTH/2);
        vectorController::get()->cells[i].integer["chip radius"]=10;
        vectorController::get()->cells[i].integer["valid space radius"]=3;
        vectorController::get()->cells[i].integer["belongs to"]=0;//1 for p1,2 for p2
        vectorController::get()->cells[i].integer["valid space belongs to"]=0;
        //and .integer[x,y,x2,y2] will be set when dimensions are set
    }
    write_initial_four();
    write_dimensions();
}

void framework::write_dimensions()
{
int counter=0;

    for (int i=0;i<CELLSPERROW;i++){
        for (int j=0;j<CELLSPERROW;j++){

            if (counter<64){
                vectorController::get()->cells[counter].integer["x"]=((i*CELLWIDTH)+board_topleft_x);
                vectorController::get()->cells[counter].integer["x2"]=(((i*CELLWIDTH)+board_topleft_x)+CELLWIDTH);

                vectorController::get()->cells[counter].integer["y"]=((j*CELLWIDTH)+board_topleft_y);
                vectorController::get()->cells[counter].integer["y2"]=(((j*CELLWIDTH)+board_topleft_y)+CELLWIDTH);
            counter++;
            }
        }}
return;
}



int framework::returnCell(int x,int y)
{
     vector<vectorController::node>::iterator it;
     int count=0;
  for ( it=vectorController::get()->cells.begin() ; it < vectorController::get()->cells.end(); it++ )
  {
      if (((*it).integer["x"]<x)&&((*it).integer["x2"]>x)&&((*it).integer["y"]<y)&&((*it).integer["y2"]>y))
      return count;

      count++;
  }
  return -1;
}


void framework::write_initial_four()
{
    vectorController::get()->cells[27].boolean["visible"]=true;
    vectorController::get()->cells[27].integer["belongs to"]=1;

    vectorController::get()->cells[28].boolean["visible"]=true;
    vectorController::get()->cells[28].integer["belongs to"]=2;

    vectorController::get()->cells[35].boolean["visible"]=true;
    vectorController::get()->cells[35].integer["belongs to"]=2;

    vectorController::get()->cells[36].boolean["visible"]=true;
    vectorController::get()->cells[36].integer["belongs to"]=1;

    return;
}
