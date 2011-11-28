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
if ((cell==37)&&(direction==8))
cout<<"\t\t37 moving left";

    if ((cell+direction>63) || (cell+direction<0) || (((cell%8)==7)&&(direction==movement::moveDown)) || (((cell%8)==0)&&(direction==movement::moveUp)))
    return false;

    if(vectorController::get()->cells[cell+direction].integer["belongs to"]==0){
        if ((cell_isoccupied(cell+((-1)*direction))))
     {
        cout<<"-returning true, direction="<<direction<<"\n";
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

if (vectorController::get()->cells[i].boolean["visible"]){

cout<<"checks("<<i<<")\n";
//check left
    if (scanController::get()->direction_isvalid(i,movement::moveLeft)){
        cout<<"\tMove Left Set True\n";
        vectorController::get()->cells[i+movement::moveLeft].boolean["valid space"]=true;
        if (vectorController::get()->cells[i].integer["belongs to"]==1){
        vectorController::get()->cells[i+movement::moveLeft].integer["valid space belongs to"]=2;
        cout<<"\t\tvalid space belongs to SET TO 2\n";
        }
        if (vectorController::get()->cells[i].integer["belongs to"]==2){
        vectorController::get()->cells[i+movement::moveLeft].integer["valid space belongs to"]=1;
        cout<<"\t\tvalid space belongs to SET TO 1\n";
        }

    }

//check right
    if (scanController::get()->direction_isvalid(i,movement::moveRight)){
        cout<<"\tMove Right Set True\n";
        vectorController::get()->cells[i+movement::moveRight].boolean["valid space"]=true;
        if (vectorController::get()->cells[i].integer["belongs to"]==1){
        vectorController::get()->cells[i+movement::moveRight].integer["valid space belongs to"]=2;
        cout<<"\t\tvalid space belongs to SET TO 2\n";
        }
        if (vectorController::get()->cells[i].integer["belongs to"]==2){
        vectorController::get()->cells[i+movement::moveRight].integer["valid space belongs to"]=1;
        cout<<"\t\tvalid space belongs to SET TO 1\n";
        }

    }

//check up
    if (scanController::get()->direction_isvalid(i,movement::moveUp)){
        cout<<"\tMove Up Set True\n";
        vectorController::get()->cells[i+movement::moveUp].boolean["valid space"]=true;
        if (vectorController::get()->cells[i].integer["belongs to"]==1){
        vectorController::get()->cells[i+movement::moveUp].integer["valid space belongs to"]=2;
        cout<<"\t\tvalid space belongs to SET TO 2\n";
        }
        if (vectorController::get()->cells[i].integer["belongs to"]==2){
        vectorController::get()->cells[i+movement::moveUp].integer["valid space belongs to"]=1;
        cout<<"\t\tvalid space belongs to SET TO 1\n";
        }

    }

//check down
    if (scanController::get()->direction_isvalid(i,movement::moveDown)){
        cout<<"\tMove Down Set True\n";
        vectorController::get()->cells[i+movement::moveDown].boolean["valid space"]=true;
        if (vectorController::get()->cells[i].integer["belongs to"]==1){
        vectorController::get()->cells[i+movement::moveDown].integer["valid space belongs to"]=2;
        cout<<"\t\tvalid space belongs to SET TO 2\n";
        }
        if (vectorController::get()->cells[i].integer["belongs to"]==2){
        vectorController::get()->cells[i+movement::moveDown].integer["valid space belongs to"]=1;
        cout<<"\t\tvalid space belongs to SET TO 1\n";
        }

    }

}
return;
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



void scanController::print_cells(string type,string key){

int counter=0;
int temp=-1;

cout<<"scanController::print_cells() is printing ."<<type<<"['"<<key<<"'] \n";
//the direction is slanted so left side is top.
    if (type=="boolean"){
        for (int i=0;i<vectorController::get()->cells.size();i++){
            if (i%8 == 0){ cout<<vectorController::get()->cells[i].boolean[key]<<" "; temp=counter;}
            if (i%8 == 1){ cout<<vectorController::get()->cells[i].boolean[key]<<" ";}
            if (i%8 == 2){ cout<<vectorController::get()->cells[i].boolean[key]<<" ";}
            if (i%8 == 3){ cout<<vectorController::get()->cells[i].boolean[key]<<" ";}
            if (i%8 == 4){ cout<<vectorController::get()->cells[i].boolean[key]<<" ";}
            if (i%8 == 5){ cout<<vectorController::get()->cells[i].boolean[key]<<" ";}
            if (i%8 == 6){ cout<<vectorController::get()->cells[i].boolean[key]<<" ";}
            if (i%8 == 7){ cout<<vectorController::get()->cells[i].boolean[key]<<" "; counter++;}
            if (counter>temp){cout<<"\n";}
            }
    }else if (type=="integer"){
        for (int i=0;i<vectorController::get()->cells.size();i++){
            if (i%8 == 0){ cout<<vectorController::get()->cells[i].integer[key]<<" "; temp=counter;}
            if (i%8 == 1){ cout<<vectorController::get()->cells[i].integer[key]<<" ";}
            if (i%8 == 2){ cout<<vectorController::get()->cells[i].integer[key]<<" ";}
            if (i%8 == 3){ cout<<vectorController::get()->cells[i].integer[key]<<" ";}
            if (i%8 == 4){ cout<<vectorController::get()->cells[i].integer[key]<<" ";}
            if (i%8 == 5){ cout<<vectorController::get()->cells[i].integer[key]<<" ";}
            if (i%8 == 6){ cout<<vectorController::get()->cells[i].integer[key]<<" ";}
            if (i%8 == 7){ cout<<vectorController::get()->cells[i].integer[key]<<" "; counter++;}
            if (counter>temp){cout<<"\n";}
            }
    }else {cout<<"Oops.. "<<type<<" is an invalid type.\n";}

}




