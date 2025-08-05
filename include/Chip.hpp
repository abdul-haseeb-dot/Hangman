#ifndef CHIP_HPP
#define CHIP_HPP

#include "raylib.h"

struct Chip
{
    Rectangle rectangle;
    char letter[2];

    Chip(char ch, float posX, float posY);
    void printChip(Color color, bool printLetter);
};

#endif