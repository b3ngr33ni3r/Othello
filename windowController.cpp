#include "windowController.h"
#include <iostream>

windowController* windowController::window_pointer=NULL;
sf::RenderWindow* windowController::windowReal=NULL;

windowController::windowController()
{
    //ctor

}

windowController* windowController::get()
{
     if(window_pointer==NULL)
        window_pointer=new windowController();

    return window_pointer;
}

sf::RenderWindow* windowController::window()
{
    if(windowReal==NULL)
        windowReal=new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Othello");

    return windowReal;
}
