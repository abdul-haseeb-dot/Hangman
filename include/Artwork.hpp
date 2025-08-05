#ifndef ARTWORK_HPP
#define ARTWORK_HPP

#include "raylib.h"

class Artwork
{
    private:
    Texture2D art[7];

    public:
    Artwork();
    void displayArt(int attemptsLeft);
    ~Artwork();
};

#endif