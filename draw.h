#ifndef DRAW_H
#define DRAW_H
#include <SFML/Graphics.hpp>
#include "chips.h"
#include "click.h"
class Draw
{
    public:
    Draw();
    int DrawBoard(sf::RenderWindow& MainWindow,Chips callChipsFunction,Click& click);
    protected:
    private:


};

#endif // Draw_H

