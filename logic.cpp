#include "logic.h"
#include "chips.h"
#include "board.h"
#include "logfile.h"
#include <string>
#include <sstream>
#include <iostream>
Logic::Logic()
{
    for (int i=0;i<8;i++)
six[i]=-1;

//make sure six array is all -1's, as this way directions will be able to be returned and found via array
}


/*
*   this checks if the player is able to move in a diagonal manner, which as i understand is any time after the first time
*   return true if they can move diagonally, false otherwise
*/
bool Logic::diagonalsAllowed(Chips& callChipsFunction)
{
    return false;//this FIXES the issues with visibleness re: the 11-13 problem. although, we also need to allow diags sometimes, so this will need revision.
    if (callChipsFunction.getClickedTotal()>4){ return true;}else{return false;}
}

/*
*   checks for all valid directions, and is used for checking pathfinding, and most importantly, scanning to determine which
*   direction(s) the player can move
*
*/
int* Logic::visibleness(Chips& callChipsFunction,int cell,bool visibleCheck=true)
{

    for (int i=0;i<8;i++)
six[i]=-1;

    Chips::chip * cur;

if (visibleCheck){
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

}else{

           cur=callChipsFunction.getPos(cell+movement::moveUp);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[0]=cur->index;
            //callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::moveDown);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[1]=cur->index;
              //  callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::moveLeft);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[2]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::moveRight);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[3]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        if (diagonalsAllowed(callChipsFunction))
        {
        cur=callChipsFunction.getPos(cell+movement::diagDL);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[4]=cur->index;
          //  callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::diagUR);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[5]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::diagDR);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[6]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        }

        cur=callChipsFunction.getPos(cell+movement::diagUL);
        if ((cur->visible)&&(!cur->isavail)&&(cur->index>=0)&&(cur->index<64))
        {
            six[7]=cur->index;
           // callChipsFunction.setMovehere(cur->index);
        } }


}
       // }}}}

    return six;//0-3 is prime directions
}

/*
*   This function contains nothing, and does nothing, im just afraid removing it might cause lots of problems.
*   so for now im just having it do nothing
*/
 void Logic::setCellsMovables(int cell,Chips& callChipsFunction,Board& board,Click& click) //if you can move there, awesome, add it to available list as visible
 {
//do nothing. replaced by scanner

 }


/*
*   returuns the index of a cell based on any xy coordinates
*   very useful, though ideally it would be relocated to Chips
*
*/
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

/*
* i was using this to log to a file, and i needed a string instead of an int. not being used now...
*/
std::string Logic::intoString(int i)
{
    std::stringstream ss;//create a stringstream
    ss << i;//add number to the stream
    return ss.str();//return a string with the contents of the str


}

/*
*   Does all the heeavy lfiting, finding cells nearby drawable locations, for each player, and marking them ->isavil and ->isp1 accordingly
*   kind of a big deal. ideally might be located in Board
*/
void Logic::scanner(Board& callBoardFunction,Chips& callChipsFunction,Click& click,sf::RenderWindow& Game,bool callback)
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


/*
if (!log.checkfor(intoString(log.getTime_hr())+std::string(":")+intoString(log.getTime_min())+std::string(":")+intoString(log.getTime_sec())))//ask @MusicAdam about this one, string should allow + but its not.
{//or maybe just write a "last pushed" command, and see if its all the same shit, if so, ignore it.

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
}
*/
if (callback){std::cout<<std::endl<<list->index<<" is "<<list->isp1<<std::endl;}
//get valid directions from currently scanning cell, if direction is not visible its valid (aka if NOTHING is there)

        for (int i=0;i<8;i++)
        {
            if ((directions[i]!=-1)&&(!callChipsFunction.getPos(directions[i])->isavail))
            {
                //set valid directions cells to movable, and give them the p1
                //std::cout<<"\ndirections[i]"<<directions[i]<<"\t";

                callChipsFunction.setMovehere(directions[i]);
                if (callChipsFunction.getClickedTotal()<5)
                    callChipsFunction.setP1(directions[i],list->isp1);//set to whatever isp1 for the scanned cell is, so if scanning a p1 cell, =p1
                else
                    callChipsFunction.setP1(directions[i],!list->isp1); //this creates invalid points, but validates the 11-13 issues
                //std::cout<<"\n-A-"<<list->index<<"-A-";
            }
        }

    }
//std::cout<<"list->index:"<<list->index<<"\n";


//also take care of flipping here. Left<->Right and Up<->Down
/*
if ((callChipsFunction.getPos(list->index+movement::moveDown)->visible)&&(callChipsFunction.getPos(list->index+movement::moveUp)->visible)&&(callChipsFunction.getPos(list->index+movement::moveDown)->isp1==callChipsFunction.getPos(list->index+movement::moveUp)->isp1)&&(callChipsFunction.getPos(list->index+movement::moveRight)->isp1!=list->isp1))//if the up/down is visible, and are both the other isp1 from the current cell
{
    callChipsFunction.setP1(list->index,callChipsFunction.getPos(list->index+movement::moveDown)->isp1);//set it to the movedown (shouldn't matter whether its set to movedown or moveup

}
if ((callChipsFunction.getPos(list->index+movement::moveLeft)->visible)&&(callChipsFunction.getPos(list->index+movement::moveRight)->visible)&&(callChipsFunction.getPos(list->index+movement::moveLeft)->isp1==callChipsFunction.getPos(list->index+movement::moveRight)->isp1)&&(callChipsFunction.getPos(list->index+movement::moveRight)->isp1!=list->isp1))//if the right/left is visible, and a diff isp1
{
    callChipsFunction.setP1(list->index,callChipsFunction.getPos(list->index+movement::moveLeft)->isp1);//set it to the movedown (shouldn't matter whether its set to movedown or moveup
}
*/
//the above is something that might be usefull, but not how to do it.

//pathfinder(callChipsFunction,callBoardFunction);


    list=list->next;

}
//std::cout<<"scannerbottom";
free(list);
}


/*
*   Suposed to be able to check a path by being giving a direction of movement
*   doesn't work. struggling here. do i need to give a starting cell too? probably would help...
*   rather then trying to scan whole board, maybe i should do that?
*/
void Logic::pathfinder(Chips& c,Board& b,int mover)//want this to be scalable, for any boardsize
{
//check each row
int iterator=b.LENGTH/b.INCREMENT;
std::cout<<"\tStartingSCAN\t";
    for (int i=0;i<=iterator;i++)
    {
        for (int a=0;a<=iterator; a++)
        {


            if (i>0)
            {


                        std::cout<<c.path(a+(i*mover),movement::moveUp)<<"|"<<a+(i*mover)<<"|";

            }
            else
            {
                    std::cout<<c.path(i,movement::moveUp)<<"|"<<i<<"|";

            }

    //after first move you can only move where u can move to flip a chip

        }
    }


std::cout<<"\tEndingScan\n";

}





