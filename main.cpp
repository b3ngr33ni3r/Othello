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

framework frame(window);
frame.init_board();
frame.write_dimensions();

std::cout<<vectorController::get()->cells[0].integer["x"];

}
