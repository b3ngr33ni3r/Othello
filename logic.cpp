#include "logic.h"
#include "chips.h"
#include "board.h"
#include "logfile.h"
#include <string>
#include <iostream>
Logic::Logic()
{
    for (int i=0;i<8;i++)
six[i]=-1;

}

bool Logic::diagonalsAllowed(Chips& callChipsFunction)
{
    if (callChipsFunction.getClickedTotal()>4){ return true;}else{return false;}
}

int* Logic::visibleness(Chips& callChipsFunction,int cell)
{

    for (int i=0;i<8;i++)
six[i]=-1;

    Chips::chip * cur;

        cur=callChipsFunction.getPos(cell+movement::moveUp);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[0]=cur->index;
            //callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::moveDown);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[1]=cur->index;
              //  callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::moveLeft);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[2]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::moveRight);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[3]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        if (diagonalsAllowed(callChipsFunction))
        {
        cur=callChipsFunction.getPos(cell+movement::diagDL);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[4]=cur->index;
          //  callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::diagUR);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[5]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::diagDR);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[6]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::diagUL);
        if ((!cur->visible)&&(cur->index>=0)&&(cur->index<64))
        {
            six[7]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        } }


       // }}}}

    return six;//0-3 is prime directions
}

 void Logic::setCellsMovables(int cell,Chips& callChipsFunction,Board& board,Click& click) //if you can move there, awesome, add it to available list as visible
 {
//do nothing. replaced by scanner

 }



int Logic::returnCell(int xa,int ya,Chips& callChipsFunction,Board& board)
 {

Chips::chip *list=callChipsFunction.head;
xa=xa-board.INCREMENT;    //Upper Left/ Lower Right is broke outside board
ya=ya-board.INCREMENT;
while(list)
{
    if ((( list->x > xa )&&( xa < list->x2 ))&&(( list->y > ya )&&( ya < list->y2 ))){
        if ((board.offsetx-board.INCREMENT < xa) && (board.wWidth-board.offsetx > xa))
        if ((board.offsety-board.INCREMENT < ya) && (board.wHeight-board.offsety > ya)){

        //std::cout<<" | "<<list->x<<">"<<xa<<" "<<xa<<"<"<<list->x2<<" "<<list->y<<">"<<ya<<" "<<ya<<"<"<<list->y2<<" | ";
        return list->index;
                                                            }
        }//check this for (offset??) problems that would cause the cells to be incorrect. 1:18PM 10/18/2011
    list=list->next;
}
return -1; //not found
 }


void Logic::scanner(Board& callBoardFunction,Chips& callChipsFunction,Click& click,sf::RenderWindow& Game)
{

int* directions;
Chips::chip* list=callChipsFunction.head;
logfile log;
//std::cout<<"scannertop";
while (list)
{



    if ((list->visible)&&(!list->isavail))// icontains no chip, and contains no possible-chip-placement as of right now.
    {
        //then its a cell to scan

    /*oh-hai!*/
    directions=visibleness(callChipsFunction,list->index);
    //directions=testarray;//this makes it so it wont setMovehere() for any directions of any new cell, becuase, it was crashing it in visibleness();

log.write(log.addTime());
log.write("cell#:");
log.write(list->index);
log.write("\tdirections:");
log.write(directions[0]);
log.write(",");
log.write(directions[1]);
log.write(",");
log.write(directions[2]);
log.write(",");
log.write(directions[3]);
log.write(",");
log.write(directions[4]);
log.write(",");
log.write(directions[5]);
log.write(",");
log.write(directions[6]);
log.write(",");
log.write(directions[7]);
log.write("\n\n");


//get valid directions from currently scanning cell, if direction is not visible its valid (aka if NOTHING is there)

        for (int i=0;i<8;i++)
        {
            if (directions[i]!=-1)
            {
                //set valid directions cells to movable, and give them the p1
                //std::cout<<"\ndirections[i]"<<directions[i]<<"\t";
                callChipsFunction.setMovehere(directions[i]);
                callChipsFunction.setP1(directions[i],list->isp1);//overload to allow setting to false/true, set to whatever isp1 for the scanned cell is, so if scanning a p1 cell, =p1
                //std::cout<<"\n-A-"<<list->index<<"-A-";
            }
        }

    }
//std::cout<<"list->index:"<<list->index<<"\n";
    list=list->next;

}
//std::cout<<"scannerbottom";
free(list);
}

