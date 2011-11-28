#include <iostream>
#include <SFML/Graphics.hpp>
#include "windowController.h"
#include "framework.h"
#include "turns.h"
#include "vectorController.h"
#include "scanController.h"
#include "pathController.h"
using namespace std;

void write(int message_type)
{
    if (message_type==1){
    cout<<"\n====================\n= WINDOW: drawing  =\n====================\n";
    }else if (message_type==2){
    cout<<"\n====================\n= MOUSE: click  =\n====================\n";
    }
}

int main()
{



sf::Event Event;
const sf::Input& InputStream = windowController::get()->window()->GetInput();

turns::get()->turn=1;
framework frame(windowController::get()->window());
frame.init_board();
frame.write_dimensions();


while(windowController::get()->window()->IsOpened()){
    if (windowController::get()->draw){

        write(1);//say, screen is being drawn

        windowController::get()->window()->Clear();

        pathController::get()->pathHandler();

        for (int i=0;i<vectorController::get()->cells.size();i++)
            {
                scanController::get()->checks(i);



                windowController::get()->window()->Draw(sf::Shape::Rectangle(vectorController::get()->cells[i].integer["x"],vectorController::get()->cells[i].integer["y"],vectorController::get()->cells[i].integer["x2"],vectorController::get()->cells[i].integer["y2"],vectorController::get()->cells[i].color["cell bkg"],2,vectorController::get()->cells[i].color["cell border"]));

                if (vectorController::get()->cells[i].boolean["visible"])
                {
                    if (vectorController::get()->cells[i].integer["belongs to"]==1)
                    windowController::get()->window()->Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["chip radius"],vectorController::get()->cells[i].color["chip color p1"]));//x,y,radius,color
                    if (vectorController::get()->cells[i].integer["belongs to"]==2)
                    windowController::get()->window()->Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["chip radius"],vectorController::get()->cells[i].color["chip color p2"]));//x,y,radius,color
                }


    if ((vectorController::get()->cells[i].boolean["valid space"]==true)||(vectorController::get()->cells[i].boolean["visible"]==true)){
     //sf::String label;
     //char * str;
     //itoa(i,str,10);
     //label.SetText(str);
     //label.SetCenter(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"]);
     //windowController::get()->window()->Draw(label);
    }

    if (vectorController::get()->cells[i].boolean["valid space"]==true)
    {



        if ((!vectorController::get()->cells[i].boolean["visible"])&&(vectorController::get()->cells[i].integer["valid space belongs to"]!=turns::get()->turn))
            windowController::get()->window()->Draw(sf::Shape::Circle(vectorController::get()->cells[i].integer["x"]+vectorController::get()->cells[i].integer["chip radius addition"],\
                        vectorController::get()->cells[i].integer["y"]+vectorController::get()->cells[i].integer["chip radius addition"],\
                        vectorController::get()->cells[i].integer["valid space radius"],vectorController::get()->cells[i].color["valid space color"]));


    }

            }


            windowController::get()->window()->Display();
            windowController::get()->draw=false;
    }











while (windowController::get()->window()->GetEvent(Event))
        {
         if ((Event.Type == sf::Event::Closed)||((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Escape)))
            windowController::get()->window()->Close();

 if (Event.Type==sf::Event::MouseButtonPressed)
            {
                write(2);

                if (-1!=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY()))
                    {
                        int current_cell=frame.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY());

                        if ((!vectorController::get()->cells[current_cell].boolean["visible"])&&(vectorController::get()->cells[current_cell].boolean["valid space"])){
                            cout<<"clicked "<<current_cell<<"\trow "<<(current_cell%8)<<"\n";
                            vectorController::get()->cells[current_cell].boolean["visible"]=true;

                            if (turns::get()->turn==2){
                                turns::get()->turn=1;
                                vectorController::get()->cells[current_cell].integer["belongs to"]=1;
                            }else{
                                turns::get()->turn=2;
                                vectorController::get()->cells[current_cell].integer["belongs to"]=2;
                            }
                            windowController::get()->draw=true;
                        }else{cout<<"invalid click\n";}
                    }
            }


        }








}

}
