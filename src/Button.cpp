#include "Button.hpp"

bool Button::isButtonClicked()
{
    Vector2 mouse=GetMousePosition();
    return CheckCollisionPointRec(mouse,rectangle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Button::drawButton(Color color)
{
    DrawRectangleRounded(rectangle,0.3f,10,color);
    DrawRectangleRoundedLines(rectangle,0.3f,10,3,BLACK);
    int fontSize=30;
    DrawText(label,rectangle.x+(rectangle.width-MeasureText(label,fontSize))/2,rectangle.y+(rectangle.height-fontSize)/2,fontSize,BLACK);
}