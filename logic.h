#ifndef LOGIC_H
#define LOGIC_H
#include "chips.h"
#include "board.h"
#include "click.h"
#include <string>
#include <SFML/Graphics.hpp>
class Logic
{
    public:
    Logic();
    void setCellsMovables(int cell,Chips& callChipsFunction,Board& board,Click& click); //if you can move there, awesome, add it to available list as visible
    //int returnMousesCellNumber(int xa,int ya);
    bool diagonalsAllowed(Chips& callChipsFunction);
    int* visibleness(Chips& callChipsFunction,int cell);
    int returnCell(int x,int y,Chips& callChipsFunction,Board& board);
    std::string intoString(int i);
    void scanner(Board& callBoardFunction,Chips& callChipsFunction,Click& click,sf::RenderWindow& Game,bool callback);
    void pathfinder(Chips& c,Board& b,int mover);
    protected:
    private:
    int six[8];//array to return valid directions

};

#endif // LOGIC_H

