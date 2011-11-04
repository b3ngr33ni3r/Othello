#include "render.h"
#include "events.h"
#include "board.h"
#include "chips.h"
#include "logic.h"
#include "click.h"
#include "write.h"
#include "draw.h"
#include <SFML/Graphics.hpp>

Render::Render()
{


}

int Render::Renderer()
{
      sf::RenderWindow Game(sf::VideoMode(800, 600, 32), "Othello");
      Events all;
      Click click;
      Chips callChipsFunction;
      Logic logical;
      Write write;
      Draw draw;
      bool scannerCallBack=false;
      Board callBoardFunction(Game,callChipsFunction);
      const sf::Input& InputStream = Game.GetInput();
      while (Game.IsOpened())
      {

      all.EventsLoop(Game,InputStream,callChipsFunction,callBoardFunction,logical,click,scannerCallBack);
      Game.Clear();
      callBoardFunction.drawBoard(Game,callChipsFunction,click);
      //logical.setCellsMovables(28,callChipsFunction,callBoardFunction,click);
      logical.scanner(callBoardFunction,callChipsFunction,click,Game,scannerCallBack);//scans for other players cells, checks suroundings and set ->isavail true for those
      if (click.isp1){
      write.sentence("greys turn. come on, make a move.",Game,10,10);
      }else{
      write.sentence("now, whites turn. lets go...",Game,10,10);
      }
draw.DrawBoard(Game,callChipsFunction,click);

      Game.Display();

      }
return 0;
}
