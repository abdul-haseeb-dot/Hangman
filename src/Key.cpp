#include "Key.hpp"
#include "Constants.hpp"

Key::Key(const char* ch,float posX,float posY)
{
    rectangle={posX,posY,KEY_DIMENSIONS,KEY_DIMENSIONS};
    label=ch;
}

void Key::drawButton(Color color)
{
    DrawRectangleRounded(rectangle,0.3f,10,color);
    DrawRectangleRoundedLines(rectangle,0.3f,10,3,Color{0,0,0,color.a});
    int fontSize=30;
    int textWidth=MeasureText(label,fontSize);
    int posX=rectangle.x+(rectangle.width-textWidth)/2;
    int posY=rectangle.y+(rectangle.height-fontSize)/2;
    DrawText(label,posX,posY,fontSize,Color{0,0,0,color.a});
}