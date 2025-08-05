#include "Artwork.hpp"
#include "Constants.hpp"
#include<string>

using namespace std;

Artwork::Artwork()
{
    for(int i=0;i<7;i++)
    {
        string path="assets/images/art"+to_string(i)+".png";
        art[i]=LoadTexture(path.c_str());
    }
}

void Artwork::displayArt(int attemptsLeft)
{
    int index=6-attemptsLeft;
    float targetWidth=275.0f;
    int posX=(SCREEN_WIDTH-targetWidth)/2;
    int posY=25;
    float scale=targetWidth/art[index].width;
    Vector2 position={(float)posX,(float)posY};
    DrawTextureEx(art[index],position,0.0f,scale,WHITE);
}

Artwork::~Artwork()
{
    for(int i=0;i<7;i++)
        UnloadTexture(art[i]);
}