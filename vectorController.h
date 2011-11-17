#ifndef CELLS_H
#define CELLS_H
#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class vectorController
{
    public:

         struct node{
            map<string,int> integer;
            map<string,bool> boolean;
            map<string,sf::Color> color;
            };

        vectorController();
        void newNode();
        vector <node> cells;

    protected:
    private:

};

#endif // CELLS_H

/**************************************************************
    -add to cells array via
    -cells[0].integer["Bob"]=101;
    -
    -its so easy! use iterators to print the whole thing out
***************************************************************/
