#include "Chip.hpp"
#include "Constants.hpp"

Chip::Chip(char ch,float posX,float posY)
{
    letter[0]=ch;
    letter[1]='\0';
    rectangle={posX,posY,CHIP_DIMENSIONS,CHIP_DIMENSIONS};
}

void Chip::printChip(Color color,bool printLetter)
{
    DrawRectangleRounded(rectangle,0.3f,10,color);
    DrawRectangleRoundedLines(rectangle,0.3f,10,3,BLACK);
    int fontSize=35;
    int textWidth=MeasureText(letter,fontSize);
    int posX=rectangle.x+(rectangle.width-textWidth)/2;
    int posY=rectangle.y+(rectangle.height-fontSize)/2;
    if(printLetter)
        DrawText(letter,posX,posY,fontSize,BLACK);
    else
        DrawText(letter,posX,posY,fontSize,color);
}