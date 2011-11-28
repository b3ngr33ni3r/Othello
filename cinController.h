#ifndef CINCONTROLLER_H
#define CINCONTROLLER_H
#include <string>
#include <iostream>
#include <SFML/System.hpp>

class cinController : public sf::Thread
{
    public:
        cinController();
        static cinController* get();
        void cinHandler();
    protected:
    private:
    void process(std::string cmd);
    static cinController* cin_pointer;
     virtual void Run()
    {
        std::cout<<"onrun";
        cinHandler();
    }

};

#endif // CINCONTROLLER_H
