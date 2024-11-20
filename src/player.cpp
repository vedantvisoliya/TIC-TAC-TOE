#include "player.hpp"

Player::Player(const char* image_path)
{
    Image image = LoadImage(image_path);

    ImageResize(&image, 140, 140);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

void Player::draw(Vector2 image_position)
{
    DrawTexture(texture, image_position.x, image_position.y, WHITE);
}
