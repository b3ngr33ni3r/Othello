#include "scanController.h"
#include <iostream>
#include "vectorController.h"

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

bool scanController::direction_isvalid(int cell,int direction)
{
    if ((cell+direction>63) || (cell+direction<0))
    return false;

    if(vectorController::get()->cells[cell+direction].integer["belongs to"]==0)
    return true;
    else
    return false;
}
