#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "raylib.h"

struct Button
{
    Rectangle rectangle;
    const char *label;

    virtual bool isButtonClicked();
    virtual void drawButton(Color color);
};

#endif