#include "pathController.h"
#include "scanController.h"
#include "vectorController.h"
#include "turns.h"
#include <iostream>


pathController* pathController::path_pointer=NULL;

pathController::pathController()
{
    //ctor
}

pathController* pathController::get(){

     if(path_pointer==NULL)
        path_pointer=new pathController();

    return path_pointer;
}



void pathController::pathHandler()
{
    cout<<"Attempting to handle paths with pathHandler()\n";

    for (int i=0;i<vectorController::get()->cells.size();i++){

        path(i,movement::moveUp);
        path(i,movement::moveDown);
        path(i,movement::moveLeft);
        path(i,movement::moveRight);

    }
}

void pathController::path(int i,int direction)
{


    if (vectorController::get()->cells[i].boolean["visible"]){
        cout<<"path() found a visible cell @ "<<i<<" while searching direction "<<direction<<"\n";
            if (scanController::get()->cell_isoccupied(i+direction)){
                    if (vectorController::get()->cells[i+direction].boolean["visible"]){
                            //check that it isn't cell[i]'s color
                            if (vectorController::get()->cells[i].integer["belongs to"]!=vectorController::get()->cells[i+direction].integer["belongs to"]){
                                    if (vectorController::get()->cells[i].integer["belongs to"]!=0){
                                        cout<<"path() found that cell "<<i<<" is the opposite color of cell "<<i+direction<<"\n";

                                        if (vectorController::get()->cells[i].integer["belongs to"]==1)
                                            vectorController::get()->cells[i+direction].integer["belongs to"]=2;
                                        else if (vectorController::get()->cells[i].integer["belongs to"]==2)
                                            vectorController::get()->cells[i+direction].integer["belongs to"]=1;


                                    }
                            }
                    }
            }
        }


 return;
}
