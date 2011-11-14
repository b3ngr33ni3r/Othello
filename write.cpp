#include "write.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Write::Write()
{
//default constructor

}

//write a sentence to the game window at position x y
void Write::sentence(std::string in,sf::RenderWindow& Win,int x,int y)
{

    // Load the font from a file
sf::Font MyFont;
if (!MyFont.LoadFromFile("arial.ttf", 18))
{
    std::cout<<"Error With Font >> arial.ttf\n";
}

//sf::String Text("Error Writing String", MyFont, 18);
sf::String Text;

Text.SetText(in);
Text.SetFont(MyFont);
Text.SetSize(18);
Text.SetPosition(x,y);

Win.Draw(Text);
}
