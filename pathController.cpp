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
        cout<<"path("<<i<<") found a visible cell @ "<<i<<" while searching direction "<<direction<<"\n";
            if (scanController::get()->cell_isoccupied(i+direction)){
                   //useless check  if (vectorController::get()->cells[i+direction].boolean["visible"]){
                            //check that it isn't cell[i]'s color
                            if (vectorController::get()->cells[i].integer["belongs to"]!=vectorController::get()->cells[i+direction].integer["belongs to"]){
                                    if (vectorController::get()->cells[i].integer["belongs to"]!=0){
                                        cout<<"path("<<i<<") found that cell "<<i<<" is the opposite color of cell "<<i+direction<<"\n";
                                        cout<<"\t.integer[\"belongs to\"] = "<<vectorController::get()->cells[i+direction].integer["belongs to"]<<"\n";
                                        cout<<"\tsetting cell "<<i+direction<<"'s belongs to value.\n";
                                        //however, before doing this, must check direction+direction contains cell, and that that cell is same color as i and not 0
                                        if (vectorController::get()->cells[i].integer["belongs to"]==1)
                                            vectorController::get()->cells[i+direction].integer["belongs to"]=2;
                                        else if (vectorController::get()->cells[i].integer["belongs to"]==2)
                                            vectorController::get()->cells[i+direction].integer["belongs to"]=1;

                                        cout<<"\t.integer[\"belongs to\"] = "<<vectorController::get()->cells[i+direction].integer["belongs to"]<<"\n";
                                    }
                            }
              //useless check      }else{cout<<"path("<<i<<") found that direction "<<direction<<" terminated @ "<<i+direction<<". no cell found.\n";}
            }else{cout<<"path("<<i<<") found that direction "<<direction<<" terminated @ "<<i+direction<<". cell not occupied.\n";}
        }


 return;
}
