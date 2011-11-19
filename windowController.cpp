#include "windowController.h"
#include <iostream>

windowController* windowController::window_pointer=NULL;

windowController::windowController()
{
    //ctor
    window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Othello");
}

windowController* windowController::get()
{
     if(window_pointer==NULL)
        window_pointer=new windowController();

    return window_pointer;
}
