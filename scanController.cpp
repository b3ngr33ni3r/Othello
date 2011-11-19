#include "scanController.h"
#include <iostream>
#include "vectorController.h"
#include "turns.h"

scanController* scanController::scan_pointer=NULL;

scanController::scanController()
{
    //ctor
    last_valid_cell=-1;
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
        if ((cell_isoccupied(cell+((-1)*direction))))
     {

         return true;
     }


    }else
    return false;


    return false;
}

bool scanController::cell_isoccupied(int cell)
{

if ((cell>=0)&&(cell<64)){
 if((vectorController::get()->cells[cell].integer["belongs to"]!=0)&&(vectorController::get()->cells[cell].boolean["visible"]))
 {
    //save this cell is valid info somewhere, so when checks is ran below, so i know what cells[index] to work with
    last_valid_cell=cell;
     return true;
 }
 else
     return false;
}else
    return false;

}

void scanController::checks(int i)
{
    int v_cell=-1;

    if (scanController::get()->direction_isvalid(i,movement::moveUp)){
                v_cell=scanController::get()->get_last_valid_space_index();
            if (v_cell!=-1){
                vectorController::get()->cells[i].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i].integer["valid space belongs to"]=2;
            }

            }
            if (scanController::get()->direction_isvalid(i,movement::moveDown)){
                v_cell=scanController::get()->get_last_valid_space_index();
            if (v_cell!=-1){
                vectorController::get()->cells[i].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i].integer["valid space belongs to"]=2;
            }

            }
            if (scanController::get()->direction_isvalid(i,movement::moveLeft)){
                v_cell=scanController::get()->get_last_valid_space_index();
            if (v_cell!=-1){
                vectorController::get()->cells[i].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i].integer["valid space belongs to"]=2;
            }

            }
            if (scanController::get()->direction_isvalid(i,movement::moveRight)){
                v_cell=scanController::get()->get_last_valid_space_index();
            if (v_cell!=-1){
                vectorController::get()->cells[i].boolean["valid space"]=true;
                if (turns::get()->turn==2)
                vectorController::get()->cells[i].integer["valid space belongs to"]=1;
                if (turns::get()->turn==1)
                vectorController::get()->cells[i].integer["valid space belongs to"]=2;
            }

            }


}


int scanController::get_last_valid_space_index()
{
    int last_valid_cell_t=last_valid_cell;
    reset_last_valid_space_index();
    return last_valid_cell_t;
}

void scanController::reset_last_valid_space_index()
{
    last_valid_cell=-1;
    return;
}
