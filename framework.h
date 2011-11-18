#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "vectorController.h"
#include <SFML/Graphics.hpp>
/*
*   Put things in here, to clean up the code.
*
*
*/

class framework
{
    public:
        framework(sf::RenderWindow& window);
        void init_board();
        void write_dimensions();
        int returnCell(int x,int y);
    protected:
    private:
        int NUMBERCELLS,CELLWIDTH,CELLSPERROW,board_topleft_x,board_topleft_y;
};

#endif // FRAMEWORK_H
