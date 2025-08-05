#include "Keyboard.hpp"
#include "Constants.hpp"
#include<cctype>

using namespace std;

Keyboard::Keyboard()
{
    vector<vector<const char*>> rows={
        {"Q","W","E","R","T","Y","U","I","O","P"},
        {"A","S","D","F","G","H","J","K","L"},
        {"Z","X","C","V","B","N","M"}
    };

    int startY=500;
    for(int row=0;row<rows.size();row++)
    {
        vector<const char*>& current=rows[row];
        int totalRowWidth=current.size()*KEY_DIMENSIONS+(current.size()-1)*KEYBOARD_PADDING;
        int startX=(SCREEN_WIDTH-totalRowWidth)/2;
        int posY=startY+row*(KEYBOARD_PADDING+KEY_DIMENSIONS);

        vector<Key> rowKeys;
        for(int i=0;i<current.size();i++)
        {
            int posX=startX+i*(KEY_DIMENSIONS+KEYBOARD_PADDING);
            Key key(current[i],posX,posY);
            rowKeys.push_back(key);
        }
        keyboard.push_back(rowKeys);
    }
}

void Keyboard::drawKeyboard(set<char> guessedLetters)
{
    for(auto row:keyboard)
    {
        for(auto key:row)
        {
            if(guessedLetters.find(key.label[0])!=guessedLetters.end())
                key.drawButton(LIGHT_PEACH);
            else
                key.drawButton(PEACH);
        }
    }
}

char Keyboard::getCharacterInput()
{
    for(auto row:keyboard)
    {
        for(auto key:row)
        {
            if(key.isButtonClicked())
                return key.label[0];
        }
    }
    char ch=GetKeyPressed();
    ch=toupper(ch);
    return ch;
}