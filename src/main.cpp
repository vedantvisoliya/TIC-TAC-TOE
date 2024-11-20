#include <iostream>
#include <raylib.h>
#include "button.hpp"
#include "player.hpp"
using namespace std;

Color dark_turquoise = {0, 206, 209, 255};
Color pewter = {137, 148, 153, 255};
Color red = {255, 0, 0, 255};

class Grid
{
public:
    int rec_height = 150;
    int rec_width = 150;
    float rec_roundness = 0.2;

    void draw()
    {
        // top layer
        DrawRectangleRounded(Rectangle{65, 65, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);
        DrawRectangleRounded(Rectangle{225, 65, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);
        DrawRectangleRounded(Rectangle{385, 65, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);

        // middle layer
        DrawRectangleRounded(Rectangle{65, 225, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);
        DrawRectangleRounded(Rectangle{225, 225, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);
        DrawRectangleRounded(Rectangle{385, 225, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);

        // bottom layer
        DrawRectangleRounded(Rectangle{65, 385, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);
        DrawRectangleRounded(Rectangle{225, 385, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);
        DrawRectangleRounded(Rectangle{385, 385, (float)rec_width, (float)rec_height}, rec_roundness, 0, pewter);
    }
};

class Game
{
public:
    // x - 0
    // o - 1
    // int x_score = 0;
    // int o_score = 0;
    int player_turn = 0;
    int winner = 0;
    // x - x(1),o(2)  y - drawn(1) or not drawn(0);
    Vector2 rec1 = {0, 0};
    Vector2 rec2 = {0, 0};
    Vector2 rec3 = {0, 0};
    Vector2 rec4 = {0, 0};
    Vector2 rec5 = {0, 0};
    Vector2 rec6 = {0, 0};
    Vector2 rec7 = {0, 0};
    Vector2 rec8 = {0, 0};
    Vector2 rec9 = {0, 0};

    Grid grid = Grid();
    void draw(Player X, Player O)
    {
        grid.draw();
        if (player_turn == 0)
        {
            DrawText("x - TURN", 40, 25, 30, BLACK);
        }
        else if (player_turn == 1)
        {
            DrawText("o - TURN", 40, 25, 30, BLACK);
        }
        // DrawText(TextFormat("x - %i / o - %i", x_score, o_score), 350, 25, 30, BLACK);
        DrawText("press 'escape' to exit", 20, 560, 30, BLACK);
        DrawText("R - reset", 450, 560, 30, BLACK);
        if (rec1.y == 1)
        {
            if (rec1.x == 1)
            {
                X.draw({65, 65});
            }
            else if (rec1.x == 2)
            {
                O.draw({65, 65});
            }
        }
        if (rec2.y == 1)
        {
            if (rec2.x == 1)
            {
                X.draw({225, 65});
            }
            else if (rec2.x == 2)
            {
                O.draw({225, 65});
            }
        }
        if (rec3.y == 1)
        {
            if (rec3.x == 1)
            {
                X.draw({385, 65});
            }
            else if (rec3.x == 2)
            {
                O.draw({385, 65});
            }
        }
        if (rec4.y == 1)
        {
            if (rec4.x == 1)
            {
                X.draw({65, 225});
            }
            else if (rec4.x == 2)
            {
                O.draw({65, 225});
            }
        }
        if (rec5.y == 1)
        {
            if (rec5.x == 1)
            {
                X.draw({225, 225});
            }
            else if (rec5.x == 2)
            {
                O.draw({225, 225});
            }
        }
        if (rec6.y == 1)
        {
            if (rec6.x == 1)
            {
                X.draw({385, 225});
            }
            else if (rec6.x == 2)
            {
                O.draw({385, 225});
            }
        }
        if (rec7.y == 1)
        {
            if (rec7.x == 1)
            {
                X.draw({65, 385});
            }
            else if (rec7.x == 2)
            {
                O.draw({65, 385});
            }
        }
        if (rec8.y == 1)
        {
            if (rec8.x == 1)
            {
                X.draw({225, 385});
            }
            else if (rec8.x == 2)
            {
                O.draw({225, 385});
            }
        }
        if (rec9.y == 1)
        {
            if (rec9.x == 1)
            {
                X.draw({385, 385});
            }
            else if (rec9.x == 2)
            {
                O.draw({385, 385});
            }
        }
    }

    bool check_collision_with_rec(Vector2 mouse_position, bool mouse_pressed, Vector2 position)
    {
        if (CheckCollisionPointRec(mouse_position, Rectangle{position.x, position.y, (float)grid.rec_width, (float)grid.rec_height}) && mouse_pressed)
        {
            return true;
        }
        return false;
    }

    void win_checker()
    {
        // X - 1, player_x - 1
        if (rec1.x == 1 && rec2.x == 1 && rec3.x == 1)
        {
            DrawLineEx({65,140}, {535, 140}, 10, BLACK);
            winner = 1;
        }
        else if (rec1.x == 1 && rec4.x == 1 && rec7.x == 1)
        {
            DrawLineEx({140, 65}, {140, 535}, 10, BLACK);
            winner = 1;
        }
        else if (rec1.x == 1 && rec5.x == 1 && rec9.x == 1)
        {
            DrawLineEx({65, 65}, {535, 535}, 10, BLACK);
            winner = 1;
        }
        else if (rec2.x == 1 && rec5.x == 1 && rec8.x == 1)
        {
            DrawLineEx({300, 65}, {300, 535}, 10, BLACK);
            winner = 1;
        }
        else if (rec3.x == 1 && rec6.x == 1 && rec9.x == 1)
        {
            DrawLineEx({460, 65}, {460, 535}, 10, BLACK);
            winner = 1;
        }
        else if (rec7.x == 1 && rec8.x == 1 && rec9.x == 1)
        {
            DrawLineEx({65,460}, {535, 460}, 10, BLACK);
            winner = 1;
        }
        else if (rec4.x == 1 && rec5.x == 1 && rec6.x == 1)
        {
            DrawLineEx({65,300}, {535, 300}, 10, BLACK);
            winner = 1;
        }
        else if (rec3.x == 1 && rec5.x == 1 && rec7.x == 1)
        {
            DrawLineEx({535, 65}, {65, 535}, 10, BLACK);
            winner = 1;
        }
         // O - 2, player_o = 2
        else if (rec1.x == 2 && rec2.x == 2 && rec3.x == 2)
        {
            DrawLineEx({65,140}, {535, 140}, 10, BLACK);
            winner = 2;
        }
        else if (rec1.x == 2 && rec4.x == 2 && rec7.x == 2)
        {
            DrawLineEx({140, 65}, {140, 535}, 10, BLACK);
            winner = 2;
        }
        else if (rec1.x == 2 && rec5.x == 2 && rec9.x == 2)
        {
            DrawLineEx({65, 65}, {535, 535}, 10, BLACK);
            winner = 2;
        }
        else if (rec2.x == 2 && rec5.x == 2 && rec8.x == 2)
        {
            DrawLineEx({300, 65}, {300, 535}, 10, BLACK);
            winner = 2;
        }
        else if (rec3.x == 2 && rec6.x == 2 && rec9.x == 2)
        {
            DrawLineEx({460, 65}, {460, 535}, 10, BLACK);
            winner = 2;
        }
        else if (rec7.x == 2 && rec8.x == 2 && rec9.x == 2)
        {
            DrawLineEx({65,460}, {535, 460}, 10, BLACK);
            winner = 2;
        }
        else if (rec4.x == 2 && rec5.x == 2 && rec6.x == 2)
        {
            DrawLineEx({65,300}, {535, 300}, 10, BLACK);
            winner = 2;
        }
        else if (rec3.x == 2 && rec5.x == 2 && rec7.x == 2)
        {
            DrawLineEx({535, 65}, {65, 535}, 10, BLACK);
            winner = 2;
        }
    }

    void update(Vector2 mouse_position_new, bool mouse_pressed_new)
    {
        if (player_turn == 0)
        {
            if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {65, 65}))
            {
                if (rec1.y == 0 || rec1.x == 1)
                {
                    rec1.x = 1;
                    rec1.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {225, 65}))
            {
                if (rec2.y == 0 || rec2.x == 1)
                {
                    rec2.x = 1;
                    rec2.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {385, 65}))
            {
                if (rec3.y == 0 || rec3.x == 1)
                {
                    rec3.x = 1;
                    rec3.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {65, 225}))
            {
                if (rec4.y == 0 || rec4.x == 1)
                {
                    rec4.x = 1;
                    rec4.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {225, 225}))
            {
                if (rec5.y == 0 || rec5.x == 1)
                {
                    rec5.x = 1;
                    rec5.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {385, 225}))
            {
                if (rec6.y == 0 || rec6.x == 1)
                {
                    rec6.x = 1;
                    rec6.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {65, 385}))
            {
                if (rec7.y == 0 || rec7.x == 1)
                {
                    rec7.x = 1;
                    rec7.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {225, 385}))
            {
                if (rec8.y == 0 || rec8.x == 1)
                {
                    rec8.x = 1;
                    rec8.y = 1;
                    player_turn = 1;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {385, 385}))
            {
                if (rec9.y == 0 || rec9.x == 1)
                {
                    rec9.x = 1;
                    rec9.y = 1;
                    player_turn = 1;
                }
            }
        }
        else if (player_turn == 1)
        {
            if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {65, 65}))
            {
                if (rec1.y == 0 || rec1.x == 2)
                {
                    rec1.x = 2;
                    rec1.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {225, 65}))
            {
                if (rec2.y == 0 || rec2.x == 2)
                {
                    rec2.x = 2;
                    rec2.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {385, 65}))
            {
                if (rec3.y == 0 || rec3.x == 2)
                {
                    rec3.x = 2;
                    rec3.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {65, 225}))
            {
                if (rec4.y == 0 || rec4.x == 2)
                {
                    rec4.x = 2;
                    rec4.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {225, 225}))
            {
                if (rec5.y == 0 || rec5.x == 2)
                {
                    rec5.x = 2;
                    rec5.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {385, 225}))
            {
                if (rec6.y == 0 || rec6.x == 2)
                {
                    rec6.x = 2;
                    rec6.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {65, 385}))
            {
                if (rec7.y == 0 || rec7.x == 2)
                {
                    rec7.x = 2;
                    rec7.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {225, 385}))
            {
                if (rec8.y == 0 || rec8.x == 2)
                {
                    rec8.x = 2;
                    rec8.y = 1;
                    player_turn = 0;
                }
            }
            else if (check_collision_with_rec(mouse_position_new, mouse_pressed_new, {385, 385}))
            {
                if (rec9.y == 0 || rec9.x == 2)
                {
                    rec9.x = 2;
                    rec9.y = 1;
                    player_turn = 0;
                }
            }
        }
    }

    void restart()
    {
        rec1 = {0, 0};
        rec2 = {0, 0};
        rec3 = {0, 0};
        rec4 = {0, 0};
        rec5 = {0, 0};
        rec6 = {0, 0};
        rec7 = {0, 0};
        rec8 = {0, 0};
        rec9 = {0, 0};
        player_turn = 0;
        winner = 0;
    }
};

int main()
{
    const int screen_height = 600;
    const int screen_width = 600;
    bool exit = false;

    Game game = Game();

    InitWindow(screen_width, screen_height, "tic-tac-toe");
    SetTargetFPS(60);

    Texture2D background_image = LoadTexture("src/background.png");
    Button start_button("src/start-button.png", {60, 510}, 0.50);
    Button exit_button("src/exit-button.png", {300, 510}, 0.40);
    Player X("src/X.png");
    Player O("src/O.png");

    while (WindowShouldClose() == false && exit == false)
    {

        Vector2 mouse_position = GetMousePosition();
        bool mouse_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (start_button.is_pressed(mouse_position, mouse_pressed))
        {
            while (true)
            {
                Vector2 mouse_position_new = GetMousePosition();
                bool mouse_pressed_new = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

                if (IsKeyPressed(KEY_R))
                {
                    game.restart();
                }
                if (IsKeyPressed(KEY_ESCAPE))
                {
                    game.restart();
                    break;
                }

                if (game.winner == 0){
                    game.update(mouse_position_new, mouse_pressed_new);
                }

                BeginDrawing();
                ClearBackground(dark_turquoise);
                game.draw(X, O);
                game.win_checker();
                EndDrawing();
            }
        }

        if (exit_button.is_pressed(mouse_position, mouse_pressed))
        {
            exit = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background_image, 0, 0, WHITE);
        start_button.draw();
        exit_button.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}