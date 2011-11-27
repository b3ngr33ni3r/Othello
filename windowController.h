#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H
#include <SFML/Graphics.hpp>

class windowController
{
    public:
        windowController();
        static windowController* get();
        static sf::RenderWindow* window();
        bool draw;
    protected:
    private:
    static windowController* window_pointer;
    static sf::RenderWindow* windowReal;
};

#endif // WINDOWCONTROLLER_H
