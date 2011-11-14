#include "chips.h"
#include "logfile.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Chips::Chips()
{
//Default constructor for Chips
chip *head = NULL;
pathfinder_array *head2 = NULL;

pathfinder_int=0;
totalCells=0;
totalSpaces=0;
}

/*
* returns an entire element of the chip list, the element of int VERY USEFUL
*/
Chips::chip* Chips::getPos(int n)//should return list[n]   aka list of n aka cell number n
{
    //display();
    int counter=0;

    chip *list = head;

//    pathfinder_array *list=head2;

	while((list) && (counter<n) && (n<64) &&(n>-1))
	{
        list=list->next;
        counter++;
	}

	return list;
}

/*
*   Trying to overload to allow returning a pathfinder_Array. probably wont use, seems difficult as hell
*
*/
Chips::pathfinder_array* Chips::getPos(int n,bool other)//should return list[n]   aka list of n aka cell number n
{
    //display();
    int counter=0;
    pathfinder_array *list=head2;

	while((list) && (counter<n) && (n<64) &&(n>-1))
	{
        list=list->next;
        counter++;
	}

	return list;
}


/*
* set a cell (int) to have been clicked (->visible), and also assign its draw color to it (though im not sure i do this)
*/
void Chips::setClicked(int n,sf::Color color)
{
    chip* temp=head;

    while (head->next!=NULL)
    {
        if(head->index==n){

            if (!head->visible){
            head->visible=true; head->color=color;}}
        head=head->next;
    }
    head=temp;
}


/*
// only for the 1st Node
* The following functions are used for node manipulation, adding to chips and (maybe) pathfinder_array
* this initNode is used to add the first element only, as it is a differnet condition
* i overloaded it with a defualt bool value so i could use it as pathfinder_array, but i dont think im gunna
*/
void Chips::initNode(int xa,int xb=0, int ya=0, int yb=0,bool other=false){
    if (!other){
    head=new chip;
    head->x = xa;
	head->x2 = xb;
	head->y=ya;
	head->isavail=false;
	head->y2=yb;
	head->index=Chips::totalCells;
	head->next =NULL;
	head->isp1=false;
	head->visible=false;
	//std::cout<<Chips::totalCells<<"|";
    }
else
    {
    head2=new pathfinder_array;
    head2->index=pathfinder_int;
    pathfinder_int++;
    head2->cnum=xa;
    head2->next=NULL;
    }
}

/*
//for not first node
* For every other node, also to add.
* same as above overloaded with a default bool to allow possible (though unlikely) use of pathfinder_Array
*/
void Chips::addNode(int xa,int xb=0, int ya=0, int yb=0,bool other=false) {
	if (!other){
	chip *newNode = new chip;
	newNode->x = xa;
	newNode->isavail=false;
	newNode->x2 = xb;
	newNode->y=ya;
	newNode->y2=yb;
	newNode->isp1=false;
	newNode->visible=false;
	newNode->index=Chips::totalCells;
	newNode->next = NULL;

	chip *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}

	}else{

	pathfinder_array *newNode = new pathfinder_array;
	newNode->index=pathfinder_int;
	newNode->next = NULL;
	newNode->cnum = xa;

	pathfinder_array *cur = head2;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}




	}

}

//whats actually called to add to the chips, because this determines which adder to use
void Chips::addCell(int xa,int xb,int ya, int yb)
{

 if (totalCells==0)
 {
     initNode(xa,xb,ya,yb);
 }else
 {
     addNode(xa,xb,ya,yb);
 }

 Chips::totalCells++;
}

//overloaded addCell to allow (possible though unlikey) use of pathfinder_Array
void Chips::addCell(int xa,bool is)
{

 if (pathfinder_int==0)
 {
     initNode(xa,true);
 }else
 {
     addNode(xa,true);
 }


}


/*
* writes the entire chip array to a file at a momemnts notice, also verbally, to the console
* useful to see list at any given time
*/
void Chips::display() {
	logfile log;
	chip *list = head;
	while(list) {
		log.write(list->x,"-v");
		log.write(",","-v");
		log.write(list->y,"-v");
		log.write("\t","-v");
		log.write(list->x2,"-v");
		log.write(",","-v");
		log.write(list->y2,"-v");
		log.write("     Visible:","-v");
		log.write(list->visible,"-v");
		log.write("\t","-v");
		log.write(list->index,"-v");
		log.write("\tlist->isavail:","-v");
		log.write(list->isavail,"-v");
		log.write("\tlist->isp1:","-v");
		log.write(list->isp1,"-v");
		log.write("\n","-v");

		list = list->next;
	}
	//free(list);
	std::cout << std::endl;
	std::cout << std::endl;
}




/*
* called to set int (cell) to be a valid place to move, containing no chip, but a valid move marker
*/
void Chips::setMovehere(int n)
{
      chip* temp=head;

    while (head->next!=NULL)
    {
        if(head->index==n){

            head->visible=true; head->isavail=true;
        }
        head=head->next;
    }
    head=temp;
}

//resets (reverses) the above
void Chips::resetMoveVis(int n)
{
      chip* temp=head;

    while (head->next!=NULL)
    {
        if(head->index==n){head->visible=false; head->isavail=false;}
        head=head->next;
    }
    head=temp;

}



//returns how many cells are placed on the board
int Chips::getClickedTotal()
{
    int counter=0;
    for (int i=0;i<64;i++)
    if (getPos(i)->visible)
        if (!getPos(i)->isavail)
    counter++;

    return counter;
}


//sets a chip (int n) ->isp1 value to true, indicatign it belongs to player 1
void Chips::setP1(int n)
{
          chip* temp=head;

    while (head->next!=NULL)
    {
        if(head->index==n){

            head->isp1=true;
        }
        head=head->next;
    }
    head=temp;
}

//do above, but allow specifying a value for ->isp1
void Chips::setP1(int n,bool set)
{
          chip* temp=head;

    while (head->next!=NULL)
    {
        if(head->index==n){

            head->isp1=set;
        }
        head=head->next;
    }
    head=temp;
}


//returns whether a slot is a gamepeice
bool Chips::is_gamepiece(int cell)
{
    if ((getPos(cell)->isavail)&&(getPos(cell)->visible)&&(cell>-1)&&(cell<64))
    return true;
    else
    return false;
}

//returns whether a cell is of the same color
bool Chips::does_colormatch(int cell, bool ISP1)
{
    if (getPos(cell)->isp1==ISP1)
    return true;
    else
    return false;
}





                ////////////////////////////////////////////////////

 //check valid directions, pick a valid direction, stick with it. check if valid cell found in that direction, check tht cells color, if same
//check valid direction (same as b4) check if valid cell found, check color(should be op).  kill on color diff or no cell. on same cell color, set line color


                int Chips::path(int init,int newdirection)
                {
                if (is_gamepiece(init+newdirection))
                    {
                         std::cout<<init<<" is valid";

                         if (does_colormatch(init+newdirection,getPos(init)->isp1))
                         {
                            std::cout<<" and is also the correct color\n";
                            return path((init+newdirection),newdirection);
                         }else
                            return (init+newdirection);
                    std::cout<<std::endl;
                    }
                    else
                    {
                        std::cout<<(init+newdirection)<<" is not a valid cell\n";
                        return -1;
                    }


                }
                /////////////////////////////////////////////////////
