#include "scanController.h"
#include <iostream>
#include "vectorController.h"
#include "turns.h"

scanController* scanController::scan_pointer=NULL;

scanController::scanController()
{
    //ctor
}

 scanController* scanController::get()
{
    if(scan_pointer==NULL)
    scan_pointer=new scanController();

    return scan_pointer;
}

//one of these two functions is causing a crash effect. dislike
bool scanController::direction_isvalid(int cell,int direction,bool internal)
{


    if ((cell+direction>63) || (cell+direction<0))
    return false;

    if(vectorController::get()->cells[cell+direction].integer["belongs to"]==0){
        if ((cell_isoccupied((cell+direction)+movement::moveUp))||(cell_isoccupied((cell+direction)+movement::moveDown))||(cell_isoccupied((cell+direction)+movement::moveLeft))||(cell_isoccupied((cell+direction)+movement::moveRight)))
     return true;

    }else
    return false;


    return false;
}

bool scanController::cell_isoccupied(int cell)
{

if ((cell>=0)&&(cell<64)){
 if((vectorController::get()->cells[cell].integer["belongs to"]!=0)&&(vectorController::get()->cells[cell].boolean["visible"]))
     return true;
 else
     return false;
}else
    return false;

}

void scanController::checks(int i)
{

    if (scanController::get()->direction_isvalid(i,movement::moveUp)){
                vectorController::get()->cells[i+movement::moveUp].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i+movement::moveUp].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i+movement::moveUp].integer["valid space belongs to"]=2;
            }
            if (scanController::get()->direction_isvalid(i,movement::moveDown)){
                vectorController::get()->cells[i+movement::moveDown].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i+movement::moveDown].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i+movement::moveDown].integer["valid space belongs to"]=2;
            }
            if (scanController::get()->direction_isvalid(i,movement::moveLeft)){
                vectorController::get()->cells[i+movement::moveLeft].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i+movement::moveLeft].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i+movement::moveLeft].integer["valid space belongs to"]=2;
            }
            if (scanController::get()->direction_isvalid(i,movement::moveRight)){
                vectorController::get()->cells[i+movement::moveRight].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i+movement::moveRight].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i+movement::moveRight].integer["valid space belongs to"]=2;
            }


}
