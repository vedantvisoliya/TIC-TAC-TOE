#pragma once
#include <raylib.h>
class Player 
{
public:
    Texture2D texture;
    Vector2 position;
    Player(const char* image_path);
    void draw(Vector2 image_position);
};