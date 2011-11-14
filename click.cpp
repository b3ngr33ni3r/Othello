#include "click.h"
#include "chips.h"
#include <iostream>
#include <SFML/Graphics.hpp>
Click::Click()
{
    //Derfualt constructor, in which the current turn var is set to player1 so player1 is up
isp1=true;
}

//place a chip at a certain cell. give it a color correctly, etc. put a chip somewhere
void Click::placeChip(int cell,Chips& callChip)
{

if (callChip.getPos(cell)->isavail){
    if (isp1)
    {
    callChip.resetMoveVis(cell);
    callChip.setClicked(cell,sf::Color(100,100,100));
    }
    else
    {
    callChip.resetMoveVis(cell);
    callChip.setClicked(cell,sf::Color(200,200,200));
    }
}else{std::cout<<"\nUnavailable Cell\n";}
}

