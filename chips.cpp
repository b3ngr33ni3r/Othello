#include "chips.h"
#include "logfile.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Chips::Chips()
{

chip *head = NULL;
pathfinder_array *head2 = NULL;

pathfinder_int=0;
totalCells=0;
totalSpaces=0;
}


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



// only for the 1st Node
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

//for not first node
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




int Chips::getClickedTotal()
{
    int counter=0;
    for (int i=0;i<64;i++)
    if (getPos(i)->visible)
        if (!getPos(i)->isavail)
    counter++;

    return counter;
}



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



bool Chips::is_gamepiece(int cell)
{
    if ((getPos(cell)->isavail)&&(getPos(cell)->visible)&&(cell>-1)&&(cell<64))
    return true;
    else
    return false;
}


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
                         std::cout<<init<<" is valid\n";

                         if (does_colormatch(init+newdirection,getPos(init)->isp1))
                            return path((init+newdirection),newdirection);
                         else
                            return (init+newdirection);
                    }
                    else
                    {
                        std::cout<<(init+newdirection)<<" is not a valid cell\n";
                        return -1;
                    }


                }
                /////////////////////////////////////////////////////
