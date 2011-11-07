#ifndef EVENTS_H
#define EVENTS_H
#include <SFML/Graphics.hpp>
#include "chips.h"
#include "board.h"
#include "logic.h"
#include "click.h"
class Events
{
    public:
    Events();
    int EventsLoop(sf::RenderWindow& Win,const sf::Input& InputStream,Chips& ChipsCaller,Board& board,Logic& logical,Click& click,bool& scannerCallback);
    protected:
    private:


};

#endif // Events_H

