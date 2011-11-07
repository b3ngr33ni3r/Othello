#include "click.h"
#include "chips.h"
#include <iostream>
#include <SFML/Graphics.hpp>
Click::Click()
{
isp1=true;
}


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

