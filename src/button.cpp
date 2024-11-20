#include "button.hpp"

Button::Button(const char* image_path, Vector2 image_position, float scale)
{
    Image image = LoadImage(image_path);

    int original_width = image.width;
    int original_height = image.height;

    int new_width = static_cast<int>(original_width * scale);
    int new_height = static_cast<int>(original_height * scale);
    ImageResize(&image, new_width, new_height);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = image_position;
};  

Button::~Button()
{
    UnloadTexture(texture);
};

void Button::draw()
{
    DrawTextureV(texture, position, WHITE);
}

bool Button::is_pressed(Vector2 mouse_position, bool mouse_pressed){
    Rectangle rect = {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    if (CheckCollisionPointRec(mouse_position, rect) && mouse_pressed){
        return true;
    }
    return false;
}