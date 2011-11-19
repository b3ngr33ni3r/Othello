#include <iostream>
#include <SFML/Graphics.hpp>
#include "render.h"
#include "windowController.h"
#include "framework.h"
#include "turns.h"
#include "vectorController.h"
#include "scanController.h"

using namespace std;



int main()
{

bool callback_keypress_q=false;

sf::Event Event;
const sf::Input& InputStream = windowController::get()->window()->GetInput();

turns::get()->turn=1;
framework frame(windowController::get()->window());
frame.init_board();
frame.write_dimensions();
//cout<<vectorController::get()->cells.size();

while(windowController::get()->window()->IsOpened()){
    windowController::get()->window()->Clear();

    for (int i=0;i<vectorController::get()->cells.size();i++)
        {
            scanController::get()->checks(i);



            windowController::get()->window()->Draw(sf::Shape::Rectangle(vectorController::get()->cells[i].integer["x"],vectorController::get()->cells[i].integer["y"],vectorController::get()->cells[i].integer["x2"],vectorController::get()->cells[i].integer["y2"],vectorController::get()->cells[i].color["cell bkg"],2,vectorController::get()->cells[i].color["cell border"]));
            //cout<<"\n"<<vectorController::get()->cells[i].integer["x"]<<','<<vectorController::get()->cells[i].integer["y"]<<','<<vectorController::get()->cells[i].integer["x2"]<<','<<vectorController::get()->cells[i].integer["y2"];
            if (vectorController::get()->cells[i].boolean["visible"])
            {
                if (vectorController::get()->cells[i].integer["belongs to"]==1)
                windowController::get()->window()->Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["chip radius"],vectorController::get()->cells[i].color["chip color p1"]));//x,y,radius,color
                if (vectorController::get()->cells[i].integer["belongs to"]==2)
                windowController::get()->window()->Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["chip radius"],vectorController::get()->cells[i].color["chip color p2"]));//x,y,radius,color
            }





if (vectorController::get()->cells[i].boolean["valid space"]==true)
{


    //cout<<"space valid="<<i;

cout<<vectorController::get()->cells[i].integer["valid space belongs to"];

    if ((!vectorController::get()->cells[i].boolean["visible"])&&(vectorController::get()->cells[i].integer["valid space belongs to"]!=turns::get()->turn))
        windowController::get()->window()->Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],\
                    vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],\
                    vectorController::get()->cells[i].integer["valid space radius"],vectorController::get()->cells[i].color["valid space color"]));


}

        }

        while (windowController::get()->window()->GetEvent(Event))
        {
         if ((Event.Type == sf::Event::KeyPressed)&&(Event.Key.Code == sf::Key::Q))
            callback_keypress_q=true;
         if ((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Q))
            callback_keypress_q=false;
         if ((Event.Type == sf::Event::Closed)||((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Escape)))
            windowController::get()->window()->Close();

 if (Event.Type==sf::Event::MouseButtonPressed)
            {
                if (-1!=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY()))
                    {
                        int current_cell=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY());

                    if ((!vectorController::get()->cells[current_cell].boolean["visible"])&&(vectorController::get()->cells[current_cell].boolean["valid space"])){
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
        windowController::get()->window()->Display();

    }
}
