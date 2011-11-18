#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "framework.h"
#include "turns.h"
#include "vectorController.h"
#include "scanController.h"

using namespace std;



int main()
{

bool callback_keypress_q=false;
sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Othello");
sf::Event Event;
const sf::Input& InputStream = window.GetInput();

turns::get()->turn=1;
framework frame(window);
frame.init_board();
frame.write_dimensions();
cout<<vectorController::get()->cells.size();

while(window.IsOpened()){
    for (int i=0;i<vectorController::get()->cells.size();i++)
        {
            if (scanController::get()->direction_isvalid(i,movement::moveUp))
                vectorController::get()->cells[i+movement::moveUp].boolean["valid space"]=true;
            if (scanController::get()->direction_isvalid(i,movement::moveDown))
                vectorController::get()->cells[i+movement::moveDown].boolean["valid space"]=true;
            if (scanController::get()->direction_isvalid(i,movement::moveLeft))
                vectorController::get()->cells[i+movement::moveLeft].boolean["valid space"]=true;
            if (scanController::get()->direction_isvalid(i,movement::moveRight))
                vectorController::get()->cells[i+movement::moveRight].boolean["valid space"]=true;


if (vectorController::get()->cells[i].boolean["valid space"]==true)
{


    cout<<"space valid="<<i;


    //if ((vectorController::get()->cells[i].integer["belongs to"]!=turns::get()->turn)&&(vectorController::get()->cells[i].integer["belongs to"]!=0))
        window.Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],\
                    vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],\
                    vectorController::get()->cells[i].integer["valid space radius"],vectorController::get()->cells[i].color["valid space color"]));


}

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
         if ((Event.Type == sf::Event::KeyPressed)&&(Event.Key.Code == sf::Key::Q))
            callback_keypress_q=true;
         if ((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Q))
            callback_keypress_q=false;
         if ((Event.Type == sf::Event::Closed)||((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Escape)))
            window.Close();

 if (Event.Type==sf::Event::MouseButtonPressed)
            {
                if (-1!=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY()))
                    {
                        int current_cell=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY());

                    if (!vectorController::get()->cells[current_cell].boolean["visible"]){
                        cout<<"clicked "<<current_cell<<"\n";
                        vectorController::get()->cells[current_cell].boolean["visible"]=true;
                        if (turns::get()->turn==2){
                            turns::get()->turn=1;
                            vectorController::get()->cells[current_cell].integer["belongs to"]=1;
                        }else{
                            turns::get()->turn=2;
                            vectorController::get()->cells[current_cell].integer["belongs to"]=2;
                        }
                    }else{cout<<"invalid click\n";}
                    }
            }


        }
        window.Display();

    }
}
