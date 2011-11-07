#ifndef BOARD_H
#define BOARD_H
#include <SFML/Graphics.hpp>
#include "chips.h"
#include "click.h"


namespace movement{
    enum{
    moveUp=-1,
    moveDown=1,
    moveLeft=-8,
    moveRight=8,
    diagUL=-9,
    diagDL=-7,
    diagUR=7,
    diagDR=9
    };}



class Board
{
    public:

      //all these are for board generation/manipulation
        int xLENGTH;
        int INCREMENT;
        int LENGTH;
        int offsetx;
        int offsety;
        int yLENGTH;
        int wHeight;
        int wWidth;


    Board(sf::RenderWindow& MainWindow,Chips& callChipsFunction);
    int start(Chips callChipsFunction);
    int drawBoard(sf::RenderWindow& MainWindow,Chips& callChipsFunction,Click& click);
    protected:
    private:
    bool addcell;
   // Chips callChipsFunction;

};

#endif // Board_H

