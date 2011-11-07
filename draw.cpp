#include "draw.h"
#include "chips.h"
#include "click.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Draw::Draw()
{


}


int Draw::DrawBoard(sf::RenderWindow& MainWindow,Chips callChipsFunction,Click& click)
{

    Chips::chip *list = callChipsFunction.head;
    while(list)
    {
        MainWindow.Draw(sf::Shape::Rectangle(list->x,list->y,list->x2,list->y2,sf::Color(50,60,70),2,sf::Color(200,100,200)));
        if (list->visible)
        {
            if (list->isavail)
            {
               // if (list->isp1==click.isp1) //with this commented, all avails are drawn
                    MainWindow.Draw(sf::Shape::Circle((list->x+((list->x2-list->x)/2)),(list->y+((list->y2-list->y)/2)),3,list->color));
            }
            else
            {
                MainWindow.Draw(sf::Shape::Circle((list->x+((list->x2-list->x)/2)),(list->y+((list->y2-list->y)/2)),10,list->color));
            }

        }
        list=list->next;
    }

    return EXIT_SUCCESS;
}
