#include "turns.h"
#include <iostream>

turns* turns::turns_pointer=NULL;

turns::turns()
{
    turn=1;
    //ctor
}


 turns* turns::get()
{
    if(turns_pointer==NULL)
    turns_pointer=new turns();

    return turns_pointer;
}
