#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H
#include <SFML/Graphics.hpp>

class windowController
{
    public:
        windowController();
        static windowController* get();
        sf::RenderWindow* window;
    protected:
    private:
    static windowController* window_pointer;
};

#endif // WINDOWCONTROLLER_H
