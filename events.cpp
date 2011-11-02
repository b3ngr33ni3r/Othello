#include "events.h"
#include "chips.h"
#include "logic.h"
#include "click.h"
#include "board.h"
#include "logfile.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Events::Events()
{


}


int Events::EventsLoop(sf::RenderWindow& Win,const sf::Input& InputStream,Chips& ChipCaller,Board& board, Logic& logical,Click& click)
{
        sf::Event Event;
        logfile log;
        while (Win.GetEvent(Event))
        {

            if (Event.Type==sf::Event::MouseButtonPressed)
            {
            //logical.setCellsMovables(logical.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY(),ChipCaller,board),ChipCaller,board,click);

            std::cout<<"You clicked cell:"<<logical.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY(),ChipCaller,board)<<"| totalchips:"<<ChipCaller.getClickedTotal()<<"\n";

            if (-1!=logical.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY(),ChipCaller,board))
                {

                    int cellnum=logical.returnCell(InputStream.GetMouseX(),InputStream.GetMouseY(),ChipCaller,board);
                    if (ChipCaller.getPos(cellnum)->isavail){
                    click.placeChip(cellnum,ChipCaller);
                    if (click.isp1){click.isp1=false;}else{click.isp1=true;}
                    }

                }
            }



            if ((Event.Type == sf::Event::Closed)||((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Escape)))
            Win.Close();
            if ((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::D))
            {
               ChipCaller.display();
            }
            if ((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::T))
            std::cout<<log.fileSize("all.log")<<"\n";

        }


//same per computer?
return EXIT_SUCCESS;
}
