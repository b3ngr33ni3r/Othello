#ifndef CLICK_H
#define CLICK_H
#include "chips.h"
#include <SFML/Graphics.hpp>

class Click
{
    public:
    Click();
    bool isp1;
    void placeChip(int cell,Chips& callChip);
    protected:
    private:


};

#endif // Click_H

