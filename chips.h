#ifndef CHIPS_H
#define CHIPS_H
#include <SFML/Graphics.hpp>

class Chips
{
    public:
    Chips();

    struct chip{int x,y,x2,y2,index; sf::Color color; bool visible,isp1,isavail; chip* next; };

    struct pathfinder_array{int cellnumber; }

    chip *head; int totalCells;

    int getClickedTotal();
    void setClicked(int n,sf::Color color);
    chip* getPos(int n);
    void initNode(int xa,int xb, int ya, int yb);
    void addNode(int xa,int xb, int ya, int yb);
    void addCell(int xa,int xb,int ya, int yb);
    void display();
    void setMovehere(int n);
    void resetMoveVis(int n);
    void setP1(int n);
    void setP1(int n,bool set);
    protected:
    private:

    int totalSpaces;

};

#endif // Chips_H

