#ifndef KEY_HPP
#define KEY_HPP

#include "Button.hpp"

struct Key : Button
{
    Key(const char* ch,float posX,float posY);
    void drawButton(Color color) override;
};

#endif