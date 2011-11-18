#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "framework.h"
#include "vectorController.h"

using namespace std;

int main()
{

//Render all;
//all.Renderer();
//this is the call to the Render that runs the loop that is occuring whilst the window is open
sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Othello");
 sf::Event Event;

framework frame(window);
frame.init_board();
frame.write_dimensions();
cout<<vectorController::get()->cells.size();

while(window.IsOpened()){
    for (int i=0;i<vectorController::get()->cells.size();i++)
        {
            window.Draw(sf::Shape::Rectangle(vectorController::get()->cells[i].integer["x"],vectorController::get()->cells[i].integer["y"],vectorController::get()->cells[i].integer["x2"],vectorController::get()->cells[i].integer["y2"],vectorController::get()->cells[i].color["cellbkg"],2,vectorController::get()->cells[i].color["cellborder"]));
            //cout<<"\n"<<vectorController::get()->cells[i].integer["x"]<<','<<vectorController::get()->cells[i].integer["y"]<<','<<vectorController::get()->cells[i].integer["x2"]<<','<<vectorController::get()->cells[i].integer["y2"];
        }



        while (window.GetEvent(Event))
        {
         if ((Event.Type == sf::Event::Closed)||((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Escape)))
            window.Close();

        }
        window.Display();

    }
}
