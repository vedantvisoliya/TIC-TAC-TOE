#pragma once
#include <raylib.h>
class Button 
{
public:
    Button(const char* image_path, Vector2 image_position, float scale);
    ~Button();
    void draw();
    bool is_pressed(Vector2 mouse_position, bool mouse_pressed);
private:
    Texture2D texture;
    Vector2 position;
};