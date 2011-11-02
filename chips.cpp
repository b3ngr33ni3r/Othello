#include "chips.h"
#include "logfile.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Chips::Chips()
{

chip *head = NULL;

totalCells=0;
totalSpaces=0;
}


Chips::chip* Chips::getPos(int n)//should return list[n]   aka list of n aka cell number n
{
    //display();
    int counter=0;
    chip *list = head;
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
void Chips::initNode(int xa,int xb, int ya, int yb){
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

//for not first node
void Chips::addNode(int xa,int xb, int ya, int yb) {
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
