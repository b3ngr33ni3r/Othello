#include "board.h"
#include "chips.h"
#include "draw.h"
#include "click.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Board::Board(sf::RenderWindow& MainWindow,Chips& callChipsFunction)
{
//defualt constructor
LENGTH=210;
INCREMENT=30;
xLENGTH=LENGTH+INCREMENT;//horozontal lines length
yLENGTH=LENGTH+INCREMENT;//vertical lines length
offsety=((MainWindow.GetHeight()/2)-(yLENGTH/2));
offsetx=((MainWindow.GetWidth()/2)-(xLENGTH/2));
wHeight=MainWindow.GetHeight();
wWidth=MainWindow.GetWidth();
//global variables f0r board shape

//callChipsFunction=caller;
addcell=true;


}


//init the board
int Board::start(Chips callChipsFunction)
{
    int A=1+(LENGTH/INCREMENT);

    int halfcells=-1+((1+(LENGTH/INCREMENT))/2);

Chips::chip* cur;

cur=callChipsFunction.getPos(halfcells+1+(A*3));

callChipsFunction.setClicked(cur->index,sf::Color(200,200,200));

//callChipsFunction.setMovehere(cur->index+movement::moveLeft);
//callChipsFunction.setMovehere(cur->index+movement::moveDown);
callChipsFunction.setP1(cur->index);

//callChipsFunction.setP1(cur->index+movement::moveDown);
//callChipsFunction.setP1(cur->index+movement::moveLeft);
cur=callChipsFunction.getPos(halfcells+1+(A*4));
callChipsFunction.setClicked(cur->index,sf::Color(100,100,100));
//callChipsFunction.setMovehere(cur->index+movement::moveRight);
//callChipsFunction.setMovehere(cur->index+movement::moveDown);
cur=callChipsFunction.getPos(halfcells+(A*3));
callChipsFunction.setClicked(cur->index,sf::Color(100,100,100));
//callChipsFunction.setMovehere(cur->index+movement::moveUp);
//callChipsFunction.setMovehere(cur->index+movement::moveLeft);
cur=callChipsFunction.getPos(halfcells+(A*4));
callChipsFunction.setClicked(cur->index,sf::Color(200,200,200));

//callChipsFunction.setMovehere(cur->index+movement::moveRight);
//callChipsFunction.setMovehere(cur->index+movement::moveUp);
callChipsFunction.setP1(cur->index);

//callChipsFunction.setP1(cur->index+movement::moveRight);
//callChipsFunction.setP1(cur->index+movement::moveUp);
}


//prepare the board for drawing
int  Board::drawBoard(sf::RenderWindow& MainWindow,Chips& callChipsFunction,Click& click)
{


if (addcell){
for (int genX=0;genX<(LENGTH/INCREMENT)+1;genX++)//THIS IS SET DYNAMICALLY
    for (int genY=0;genY<(LENGTH/INCREMENT)+1;genY++)
        {
            callChipsFunction.addCell(((genX*INCREMENT)+offsetx),((genX*INCREMENT)+offsetx)+INCREMENT,((genY*INCREMENT)+offsety),((genY*INCREMENT)+offsety)+INCREMENT);

        }

        start(callChipsFunction);


}

if (addcell){
addcell=false;
}


/*
    * Now we'll draw the physical board, after creating the points in our list
    * basically, we scroll through our list
    * and output a shape using list values before moving on.
    *
*/

//do actual draw call from Redner
return EXIT_SUCCESS;
}
