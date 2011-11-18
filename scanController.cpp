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
