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
    if(vectorController::get()->cells[cell+direction].boolean["visible"])
    return false;
    else
    return true;
}
