#include "Word.hpp"
#include "Constants.hpp"

using namespace std;

Word::Word(string word)
{
    this->word=word;
    int posY=430;
    int totalWordWidth=0;
    for(char ch:word)
    {
        if(ch==' ')
            totalWordWidth+=CHIP_SPACE;
        else
            totalWordWidth+=(CHIP_DIMENSIONS+CHIP_PADDING);
    }
    totalWordWidth-=CHIP_PADDING;
    int startX=(SCREEN_WIDTH-totalWordWidth)/2;

    int currentX=startX;
    for(char ch:word)
    {
        if(ch==' ')
            currentX+=CHIP_SPACE;
        else
        {
            Chip chip(ch,currentX,posY);
            alphabets.push_back(chip);
            currentX+=(CHIP_PADDING+CHIP_DIMENSIONS);
        }
    }
}

void Word::displayWord(set<char> guessedLetters)
{
    for(auto chip:alphabets)
    {
        bool isGuessed=(guessedLetters.find(chip.letter[0])!=guessedLetters.end());
        chip.printChip(APRICOT,isGuessed);
    }
}