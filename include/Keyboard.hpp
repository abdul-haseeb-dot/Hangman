#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include<vector>
#include<set>
#include "Key.hpp"

struct Keyboard
{
    std::vector<std::vector<Key>> keyboard;
    
    Keyboard();
    void drawKeyboard(std::set<char> guessedLetters);
    char getCharacterInput();
};

#endif