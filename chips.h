#ifndef CHIPS_H
#define CHIPS_H
#include <SFML/Graphics.hpp>

class Chips
{
    public:
    Chips();

    struct chip{int x,y,x2,y2,index; sf::Color color; bool visible,isp1,isavail; chip* next; };

    struct pathfinder_array{int cnum,index; pathfinder_array* next;  };
    //the structures

    chip *head; int totalCells; pathfinder_array *head2;
    //the public vars

    int getClickedTotal();
    void setClicked(int n,sf::Color color);
    chip* getPos(int n);
    Chips::pathfinder_array* getPos(int n,bool other);
    void initNode(int xa,int xb, int ya, int yb,bool other);
    void addNode(int xa,int xb, int ya, int yb,bool other);
    void addCell(int xa,int xb,int ya, int yb);
    void addCell(int xa,bool is);
    void display();
    void setMovehere(int n);
    void resetMoveVis(int n);
    void setP1(int n);
    void setP1(int n,bool set);
    int pathfinder_int;


    bool is_gamepiece(int cell);
    bool does_colormatch(int cell, bool ISP1);
    int path(int init, int newdirection);
    //the public functions

    protected:
    private:

    int totalSpaces;

};

#endif // Chips_H

