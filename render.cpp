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
//Default Constructor

}

int Render::Renderer()
{
      sf::RenderWindow Game(sf::VideoMode(800, 600, 32), "Othello");
      //Create the RenderWindow that is the game, so name it Game, give it a title of Othello
      Events all;
      Click click;
      Chips callChipsFunction;
      Logic logical;
      Write write;
      Draw draw;
      //all the above are instance declarations of various types to allow calls to them

      bool scannerCallBack=false;
      //this is just something im trying to allow calling a function somewhere on keypress. not really needed

      Board callBoardFunction(Game,callChipsFunction);
      //the instance for Board, the constructor takes parameters

      const sf::Input& InputStream = Game.GetInput();
      //the Input handler, which allows calls to things the user does.

      while (Game.IsOpened())
      { //the forever loop, which is constantly running while the game window is up

      all.EventsLoop(Game,InputStream,callChipsFunction,callBoardFunction,logical,click,scannerCallBack);
      //calls the Event handler area, which gets hit everytime a key is pressed. and allows calling to a variety of things. basically user input is handled in here
      Game.Clear();
      //draw black in the whole window
      callBoardFunction.drawBoard(Game,callChipsFunction,click);
      //setup the acutal board, with its peices where they shoudl be based on the Chips list info, prepare it for drawing

      //logical.setCellsMovables(28,callChipsFunction,callBoardFunction,click);
      //old commented out code

      logical.scanner(callBoardFunction,callChipsFunction,click,Game,scannerCallBack);//scans for other players cells, checks suroundings and set ->isavail true for those
      //is suposed to handle all odd things, like where they can go, pathfinding, etc.

      if (click.isp1){
          //if player one is up
      write.sentence("greys turn. come on, make a move.",Game,10,10);
      }else{
          //player 2 is up
      write.sentence("now, whites turn. lets go...",Game,10,10);
      }
draw.DrawBoard(Game,callChipsFunction,click);
//acutally draw the board

      Game.Display();
//show the game
      }
return 0;
}
