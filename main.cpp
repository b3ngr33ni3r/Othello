#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "framework.h"
#include "vectorController.h"

using namespace std;

namespace movement{
    enum{
    moveUp=-1,
    moveDown=1,
    moveLeft=-8,
    moveRight=8,
    diagUL=-9,
    diagDL=-7,
    diagUR=7,
    diagDR=9
    };}


int main()
{

//Render all;
//all.Renderer();
//this is the call to the Render that runs the loop that is occuring whilst the window is open
sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Othello");
 sf::Event Event;
const sf::Input& InputStream = window.GetInput();

framework frame(window);
frame.init_board();
frame.write_dimensions();
cout<<vectorController::get()->cells.size();

while(window.IsOpened()){
    for (int i=0;i<vectorController::get()->cells.size();i++)
        {
            window.Draw(sf::Shape::Rectangle(vectorController::get()->cells[i].integer["x"],vectorController::get()->cells[i].integer["y"],vectorController::get()->cells[i].integer["x2"],vectorController::get()->cells[i].integer["y2"],vectorController::get()->cells[i].color["cell bkg"],2,vectorController::get()->cells[i].color["cell border"]));
            //cout<<"\n"<<vectorController::get()->cells[i].integer["x"]<<','<<vectorController::get()->cells[i].integer["y"]<<','<<vectorController::get()->cells[i].integer["x2"]<<','<<vectorController::get()->cells[i].integer["y2"];
            if (vectorController::get()->cells[i].boolean["visible"])
            {
                if (vectorController::get()->cells[i].integer["belongs to"]==1)
                window.Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["chip radius"],vectorController::get()->cells[i].color["chip color p1"]));//x,y,radius,color
                if (vectorController::get()->cells[i].integer["belongs to"]==2)
                window.Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["chip radius"],vectorController::get()->cells[i].color["chip color p2"]));//x,y,radius,color
            }
        }



        while (window.GetEvent(Event))
        {
         if ((Event.Type == sf::Event::Closed)||((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Escape)))
            window.Close();

 if (Event.Type==sf::Event::MouseButtonPressed)
            {
                if (-1!=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY()))
                    {
                        int current_cell=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY());
                        cout<<"clicked "<<current_cell<<"\n";
                        vectorController::get()->cells[current_cell].boolean["visible"]=true;
                    }
            }


        }
        window.Display();

    }
}
